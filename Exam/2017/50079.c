/* 50079. Apple Pile */
# include <stdio.h>
int main(void){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n%d\n", b * (b + 1) / 2 - (a - 1) * a / 2, (b - a) * 2 + a + b - 2);
}