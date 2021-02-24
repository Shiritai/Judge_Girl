/* 50115. Depth of Water */
# include <stdio.h>
int main(void){
    int a, b, h, c, d;
    scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
    printf("%d\n", a * b * h / (a * b - c * d));
}