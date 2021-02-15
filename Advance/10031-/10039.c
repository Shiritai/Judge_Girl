/* 10039. Baby Boos */
# include <stdio.h>
# include <string.h>
char sentence[100000] = "";
int main(void){
    int changes;
    char moto, ato;
    scanf("%s%d\n", sentence, &changes);
    for (int i = 0; i < changes; ++i){
        do {scanf("%c", &ato);} while (ato == ' ' || ato == '\n');
        do {scanf("%c", &moto);} while (moto == ' ' || moto == '\n');
        if (moto == ato)    continue;
        char * tmp = strchr(sentence, moto);
        for (; tmp != NULL; tmp = strchr(tmp, moto))    * tmp = ato;
    }
    puts(sentence);
    return 0;
}