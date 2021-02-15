/* 10032. String Subset */
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define MAX_LEN 500
int cmp(const void * data1, const void * data2){ return strcmp((char *) data1, (char *) data2);}
int main(void){
    static char dict[250000][MAX_LEN] = {""};
    char input[501];
    scanf("%s", input);
    int len = strlen(input), dictCnt = 0;
    for (int i = 0; i < len; ++i){
        for (int j = 1; j <= len - i; ++j, ++dictCnt)
            strncpy(dict[dictCnt], input+i, j);
    }
    qsort((void *)dict, dictCnt, sizeof(dict[0]), cmp);
    for (int i = 0; i < dictCnt; ++i){
        if (strcmp(dict[i-1], dict[i]))
            puts(dict[i]);
    }
    return 0;
}