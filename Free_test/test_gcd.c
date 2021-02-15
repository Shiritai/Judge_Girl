# include <stdio.h>
int gcd_type2(int a, int b){
    if (a == 0)
        return b;
    return gcd_type2(b%a, a);
}
int main(void){
    printf("%d\n", gcd_type2(1529, 14038));
}