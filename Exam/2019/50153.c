/* 50153. Stepped Polygon */
# include <stdio.h>
int main(void){
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    printf("%d\n%d\n", 2 * (a + b + c + d + e + f), a * (b + d + f) + c * (d + f) + e * f);
}