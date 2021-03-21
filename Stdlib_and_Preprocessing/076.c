/* 76. Strings */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define LEN 40

int comp(const void * data1, const void * data2){
    return strcmp((char *) data1, (char *) data2);
}

int main(void){
    char strings[65][LEN];
    int lines = 0;
    while (fgets(strings[lines], LEN, stdin) != NULL){
        ++lines;
    }
    qsort(strings, lines, sizeof(strings[0]), comp);
    for (int i = 0; i < lines; ++i){
        printf("%s", strings[i]);
    }
}