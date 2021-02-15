# include <stdio.h>
int main(){
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    int surf = 2*(a*b + a*c + b*c) + 8*d*((a-2*e) + (c-2*e) + (b-2*e));
    int vol = a*b*c - 2 * d * ((a-2*e) * (c-2*e) + (b-2*e) * (c-2*e) + (a-2*e) * (b-2*e));
    printf("%d\n%d", surf, vol);
}
