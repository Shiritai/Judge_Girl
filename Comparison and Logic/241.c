# include <stdio.h>
# include <stdbool.h>
int main(){
    int a, b, c, d, e, f, g, h;
    scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
    // printf("%d%d%d%d%d%d%d%d", a, b, c, d, e, f, g, h);
    bool x = (a*d-b*c > 0 && c*f-d*e > 0 && e*h-f*g > 0 && g*b-h*a > 0);
    printf("%d",x);
}