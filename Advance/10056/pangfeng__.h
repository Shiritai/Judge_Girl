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

/* 紀錄原 score 順序 */
static int resultOrder[COLLEN][2]; // 0 : 拿目標成績去排序, 1 : 人的原順序 (單純的在 ExamTable 裡的順序) 副本
static char nametable[COLLEN][32] = {""}; // 0 : 拿目標成績去排序, 1 : 人的原順序 (單純的在 ExamTable 裡的順序) 副本
static char * namePtr[COLLEN];
static int n, col_len;

int comp(const void * data1, const void * data2){
    int a = * (int *) data1;
    int b = * (int *) data2;
    if (a < b)
        return 1;
    else if (a > b)
        return -1;
    int nameSwap = strcmp(nametable[a], nametable[b]);
    printf("swap name : %s (move back) <--> %s (move front)\n", nametable[a], nametable[b]);
    if (nameSwap > 0){
        char tmp[32];
        strcpy(tmp, nametable[a]);
        strcpy(nametable[a], nametable[b]);
        strcpy(nametable[b], tmp);
    }
    // int nameSwap = strcmp(namePtr[a], namePtr[b]);
    // if (nameSwap < 0){
    //     char * tmp = namePtr[a];
    //     namePtr[a] = namePtr[b];
    //     namePtr[b] = tmp;
    // }
    return nameSwap; 
}

void print(ExamTable * self, int order[]){
    n = self->num_of_person, col_len = self->dim_n; // 排序用，人數
    for (int i = 0; i < n; ++i)
        resultOrder[i][1] = i;
    /* 為排序做準備 */
    for (int j = 0; j < n; ++j){
        strcpy(nametable[j], self->ST[j].name);
        namePtr[j] = nametable[j];
    }
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
        /* 將 resultOrder[0] 用 quick sort 排序 */
        qsort(resultOrder, n, sizeof(resultOrder[0]), comp);
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