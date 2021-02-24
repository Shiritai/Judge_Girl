/* 50154. Path within a Network */
# include <stdio.h>
int main(void){
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    printf("%d\n%d\n", a + b + c + d + (a + b + c) * e + (c + d) * f + e * g + g + f, (a + b + c) * e * g + (c + d) * f);
}