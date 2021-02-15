/* 96. Cow and House */
# include <stdio.h>
// # include <math.h>
# define PI 3.1415926
# define sq(x) (x*x)
int main(void){
    double a, b, c, area;
    scanf("%lf%lf%lf", &a, &b, &c);
    /* whatever a, b, c is, this must be compute */
    area = sq(c)*PI*3/4;
    /* add the remain areas */
    /* !!!!!!!!!!!! BE CARE OF using bracket will !!!!!!!!!!! */
    area = (c > a) ? (area + sq((c-a))*PI/4) : area;
    area = (c > b) ? (area + sq((c-b))*PI/4) : area;
    printf("%f", area);
}