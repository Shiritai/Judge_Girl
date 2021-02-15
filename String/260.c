/* 260. String Fusion */
# include <stdio.h>
# include <string.h>
# define Len 128
int main(void){
    char out[10000] = "", input[Len], tmp[Len];
    int add_ind;
    _Bool fusion;
    while (scanf("%s", input) != EOF && strcmp(input, "-1") != 0){
        fusion = 0;
        for (int i = (strlen(input) <= strlen(out)) ? strlen(input) : strlen(out); i >= 1 && !fusion; --i){
            strncpy(tmp, input, i);
            tmp[i] = '\0';
            if (!strcmp(out+strlen(out)-i, tmp))
                fusion = 1, add_ind = i;
        }
        if (fusion){
            strcat(out, input+add_ind);
        }
        else 
            strcat(out, input);
    }
    puts(out);
}