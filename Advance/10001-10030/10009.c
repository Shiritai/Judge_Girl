/* 10009. Reduce a Fraction */
# include <stdio.h>
void After_gcd(int * a, int * b){
    int a_ = * a, b_ = * b;
    while (b_ != 0){
        int tmp = b_;
        b_ = a_ % b_;
        a_ = tmp;
    }
    * a /= a_, * b /= a_;
    return; 
}
int main(void){
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF){
        After_gcd(&x, &y);
        printf("%d / %d\n", x, y);
    }
    return 0;
}