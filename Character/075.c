/* 75. Count Letters */
# include <stdio.h>
# define _A_ 65
# define _Z_ 90
# define _a_ 97
# define _z_ 122

int main(void){
    char str[100];
    int cnt_letters[26] = {0}, i;
    scanf("%s", &str);
    for (i = 0; str[i] != '\0'; i++){
        if (str[i] >= _A_ && str[i] <= _Z_)
            cnt_letters[(int) str[i] - _A_]++;
        else if (str[i] >= _a_ && str[i] <= _z_)
            cnt_letters[(int) str[i] - _a_]++;
    }
    for (i = 0; i < 26; i++)
        printf("%d\n", cnt_letters[i]);
}