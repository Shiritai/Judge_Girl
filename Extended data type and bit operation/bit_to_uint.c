# include <stdio.h>
# include <string.h>
# include <stdint.h>
# define BitLen 32
int main(void){
    char a[BitLen] = "";
    scanf("%s", &a);
    int i;
    unsigned int ans = 0, tmp = 1;
    for (i = strlen(a); i >= 0; i--){
        if (a[i] == '1')
            ans += tmp;
        tmp *= 2;
    }
    printf("%u", ans);
}