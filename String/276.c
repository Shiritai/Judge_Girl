/* 276. Abbreviation */
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# define SenLen 127
# define Words 10000
void Abbreviate(char * result, char * source);
int main(void){
    static char abbr[Words] = "", moto[Words][SenLen];
    int i = 0, j = 0;
    while (scanf("%s", moto[i]) != EOF){
        if (strcmp(moto[i], "of") != 0 && strcmp(moto[i], "the") != 0 \
            && strcmp(moto[i], "and") != 0 && strcmp(moto[i], "at") != 0\
            && strcmp(moto[i], "of.") != 0 && strcmp(moto[i], "the.") != 0 \
            && strcmp(moto[i], "and.") != 0 && strcmp(moto[i], "at.") != 0){
            abbr[j] = toupper(moto[i][0]);
            j++;
        }
        if (moto[i][strlen(moto[i]) - 1] == '.'){
            abbr[j] = '\n';
            i = 0, j++;
            continue;
        }
        i++;
    }
    printf("%s", abbr);
    return 0; 
}