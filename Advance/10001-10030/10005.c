/* 10005. Parse Integer */
#include <stdio.h>
#include <string.h>    // strlen(s)
# include <stdbool.h>
# include <ctype.h>
int main(void) {
    char s[1024];
    while (scanf("%s", s) == 1) {
        int n = (int) strlen(s);    // strlen("CSIE") = 4, actually use "CSIE\0" in memory.
        bool flag = false;
        int tmp = 0;
        for (int i = 0; i <= n; i++) {
            if (isdigit(s[i]))
                flag = true;
            if (isdigit(s[i]) && flag)
                tmp = tmp * 10 + (s[i] - '0');
            if (!isdigit(s[i]) && flag){
                flag = false;
                printf("%d\n", tmp);
                tmp = 0;
            }
        }
    }
    return 0;
}