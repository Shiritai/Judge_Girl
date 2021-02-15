/* 220. Sentence Count */
# include <stdio.h>
# include <string.h>
int main(void){
    static char str[1000000] = "", tmpstr[1000000];
    int i, tmp_E = 1, tmp_CL = 1, result = 0;
    while (fgets(tmpstr, 0x7fffffff, stdin)){ // fgets(*str, scan nums, stdin)
        strcat(str, tmpstr);
    }
    int str_len = strlen(str);
    for (i = 0; i < str_len; i++){
        if (str[i] == '.' && ((str[i+1] == ' ' && str[i+2] == ' ') || str[i+1] == '\n' || str[i+1] == '\0'))
            result++;
    }
    printf("%d", result);
}