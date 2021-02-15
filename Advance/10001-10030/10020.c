# include <stdio.h>
# include <math.h>
int main(void){
    double a, b, c;
    while (scanf("%lf%lf%lf", &a, &b, &c) != EOF){
        double tmp = sqrt(b*b-4*a*c);
        printf("%.20lf %.20lf\n", (-b-tmp)/(2*a), (-b+tmp)/(2*a));
    }
    return 0;
}