/* 24. Vowel, Consonant, and Digit */
# include <stdio.h>
int main(void){
    char str[100];
    scanf("%s", &str);
    int Cnt_type[3] = {0}; // 0: number, 2: consonant, 1: vowel
    int cnt;
    for (cnt = 0; str[cnt] != '\0'; cnt++){
        if (str[cnt] >= '0' && str[cnt] <= '9')
            Cnt_type[0]++;
        else if (str[cnt] == 'A' || str[cnt] == 'E' || str[cnt] == 'I'\
            || str[cnt] == 'O' || str[cnt] == 'U' || str[cnt] == 'a'\
            || str[cnt] == 'e' || str[cnt] == 'i' || str[cnt] == 'o' || str[cnt] == 'u')
            Cnt_type[1]++;
        else if (str[cnt] >= 'B' && str[cnt] <= 'Z')
            Cnt_type[2]++;
        else if (str[cnt] >= 'b' && str[cnt] <= 'z')
            Cnt_type[2]++;
    }
    printf("%d %d %d %d", Cnt_type[0], Cnt_type[1] + Cnt_type[2], Cnt_type[1], Cnt_type[2]);
}