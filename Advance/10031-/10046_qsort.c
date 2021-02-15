/* 10046. Derangement */
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define crzLen 362880
# define rngLen 10
static char ansStr[crzLen][rngLen] = {""};
char dict[rngLen];
int ind = 0, limit[100][2] = {};
int n, m;
void init(void){
    for (int i = 0; i < m; ++i)
        limit[i][0] = 0, limit[i][1] = 0;
    memset(dict, 0, sizeof(char) * n);
    memset(ansStr, 0, sizeof(ansStr[0]) * (crzLen+1));
    ind = 0;
    return;
}
void swap(char * a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
int check_derange(int place, int alpha){
    for (int i = 0; i < m; ++i){
        if (limit[i][0] == dict[alpha] - 'A' + 1 && limit[i][1] == place+1)
            return 0;
    }
    return 1;
}
void permute(int head){
    if (head == n-1){
        if (check_derange(n-1, n-1)){
            strcpy(ansStr[ind], dict);
            ++ind;
        }
    }
    else {
        for (int i = head; i < n; ++i){
            if (check_derange(head, i)){
                swap((dict+head), (dict+i));
                permute(head+1);
                swap((dict+head), (dict+i));
            }
        }
    }
}
int comp(const void * data1, const void * data2){
    return strcmp((char *) data1, (char *) data2);
}
int main(void){
    while (scanf("%d%d", &n, &m) == 2){
        for (int i = 0; i < n; ++i)
            dict[i] = i + 'A';
        for (int i = 0; i < m; ++i)
            scanf("%d%d", &limit[i][0], &limit[i][1]);
        permute(0);
        qsort((void *) ansStr, ind, sizeof(ansStr[0]), comp);
        for (int i = 0; i < ind; ++i)
            puts(ansStr[i]);
        init();
    }
    return 0;
}