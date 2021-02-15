/* 262. Maximum Number of Consecutive 1's */
# include <stdio.h>
# define BitLen 32
int main(void){
    int a, i, mask = 1, tmp = 0, max = 0;
    while (scanf("%d", &a) != EOF){
        for (i = 0; i < BitLen; i++){
            if (a & mask)
                tmp++;
            else {
                max = (tmp > max) ? tmp : max;
                tmp = 0;
            }
            a >>= 1;
        }
        printf("%d\n", max);
        max = 0, tmp = 0;
    }
}