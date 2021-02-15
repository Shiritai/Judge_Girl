/* Move Zeroes */
# include <stdio.h>
# define Len 100000
int main(void){
    int num, a[Len] = {0}, tmp, cnt = 0, zero = 0;
    scanf("%d", &num);
    for (; num > 0; --num){
        scanf("%d", &tmp);
        if (tmp != 0)
            a[cnt] = tmp, cnt++;
        else
            zero++;
    }
    for (int i = 0; i < cnt; i++)
        printf("%d ", a[i]);
    for (int i = 0; i < zero - 1; i++)
        fputs("0 ", stdout);
    fputs("0\n", stdout);
}