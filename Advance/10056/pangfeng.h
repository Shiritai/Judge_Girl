# ifndef PANGFENG_H
# define PANGFENG_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h> 
# define NAMELEN 32
# define SCORELEN 128
# define COLLEN 256

typedef struct scoreTable {
    char name[NAMELEN];
    int score[SCORELEN];
} scoreTable;

typedef struct ExamTable {
    int dim_n;
    int num_of_person;
    scoreTable ST[COLLEN];
} ExamTable;

void init(ExamTable * self, int n);

void addrow(ExamTable * self, char * name, int score[]);

void print(ExamTable * self, int order[]);

void init(ExamTable * self, int n){
    self->dim_n = n;
    self->num_of_person = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            self->ST[i].score[j] = 0;
    }
}

void addrow(ExamTable * self, char * name, int score[]){
    strcpy(self->ST[self->num_of_person].name, name);
    for (int i = 0; i < self->dim_n; ++i)
        (&(self->ST[self->num_of_person]))->score[i] = score[i];
    ++(self->num_of_person);
}

void normal_print(ExamTable * self){
    puts("-------- test print --------");
    for (int i = 0; i < self->num_of_person; ++i){
        printf("%s, ", self->ST[i].name);
        for (int j = 0; j < self->dim_n; ++j)
            printf("%d ", self->ST[i].score[j]);
        puts("");
    }
    puts("-------- test print --------");
}

int strcomp(char * a, char * b){
    for (int i = 0; i < (strlen(a) > strlen(b)) ? strlen(b) : strlen(a); ++i){
        if (a[i] < b[i]) // 字典序小者優先
            return 1;
        else if (a[i] < b[i])
            return -1;
    }
    return strlen(b) - strlen(a); // 等長 -> 相等, 短者優先 (比如若 a 短, 返回 +)
}

void print(ExamTable * self, int order[]){
    /* 紀錄原 score 順序 */
    int resultOrder[COLLEN][2]; // 0 : 拿目標成績去排序, 1 : 人的原順序 (單純的在 ExamTable 裡的順序) 副本
    int n = self->num_of_person, col_len = self->dim_n; // 排序用，人數
    for (int i = 0; i < n; ++i)
        resultOrder[i][1] = i;
    /* 排序 dim_n 次, 從優先度低者開始 */
    for (int i = 1; i <= col_len; ++i){
        /* 反著 order 順序來排序 */
        int sortIndex = order[col_len - i];
        /* 印出當前人的順序 */
        // for (int i = 0; i < n; ++i)
        //     printf("%s%c", self->ST[resultOrder[i][1]].name, " \n"[i == n - 1]);
        // printf("_____________Selected column : %d_______________\n", sortIndex);
        /* 依正確的順序 (resultOrder[...][1]) 將成績 (self->ST[sortIndex]) 複製給 resultOrder[...][0] */
        for (int j = 0; j < n; ++j)
            resultOrder[j][0] = self->ST[resultOrder[j][1]].score[sortIndex];
        /* 將 resultOrder[0] 用 shell sort 排序 */
        int span = 1;
        while (span <= (n >> 2))
            span <<= 1;
        for (int s = span; s >= 1; s >>= 1){ // set span
            for (int y = 0; y < n - 1; ++y){
                /* 對 resultOrder[y + span] 插入排序 */
                int move = y;
                while (resultOrder[move][0] < resultOrder[move + s][0] || \
                    (resultOrder[move][0] == resultOrder[move + s][0] && \
                    strcomp(self->ST[resultOrder[move][1]].name, self->ST[resultOrder[move + s][1]].name) < 0)){
                    // /* check strcomp */
                    // if (resultOrder[move][0] == resultOrder[move + s][0] && strcomp(self->ST[resultOrder[move][1]].name, self->ST[resultOrder[move + s][1]].name) < 0)
                    //     printf("swap %s (move back) <-> %s (move front)!\n", self->ST[resultOrder[move][1]].name, self->ST[resultOrder[move + s][1]].name);
                    /* swap */
                    int tmp[2] = {resultOrder[move][0], resultOrder[move][1]};
                    resultOrder[move][0] = resultOrder[move + s][0];
                    resultOrder[move][1] = resultOrder[move + s][1];
                    resultOrder[move + s][0] = tmp[0];
                    resultOrder[move + s][1] = tmp[1];
                    /* iter of move */
                    move -= s;
                    if (move < 0)
                        break;
                }
            }
        }
    }
    /* 印出當前人的順序 */
    // for (int i = 0; i < n; ++i)
    //     printf("%s%c", self->ST[resultOrder[i][1]].name, " \n"[i == n - 1]);
    /* 印出 */
    puts("----- table begin -----");
    for (int i = 0; i < n; ++i){
        printf("%s, ", self->ST[resultOrder[i][1]].name);
        for (int j = 0; j < col_len - 1; ++j){
            printf("%d, ", self->ST[resultOrder[i][1]].score[j]);
        }
        printf("%d\n", self->ST[resultOrder[i][1]].score[col_len - 1]);
    }
    puts("----- end         -----");
}

# endif