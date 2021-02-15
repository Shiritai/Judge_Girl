/* 236. Least Common Multiplier */
# include <stdio.h>
int gcd_type1(int a, int b){
    while(a != 0){
        int tmp = a;
        a = b % a;
        b = tmp;
    }
    return b;
}
int gcd_type2(int a, int b){
    if (a == 0)
        return b;
    return gcd_type2(b%a, a);
}
int main(void){
    int num, lcm, tmp_gcd, tmp_mul;
    scanf("%d", &lcm);
    tmp_mul = lcm, tmp_gcd = lcm;
    while(scanf("%d", &num) == 1){
        tmp_gcd = gcd_type1(lcm, num);
        lcm *= num;
        lcm /= tmp_gcd;
    }
    printf("%d", lcm);
    // printf("%d", gcd_type2(2, 3));
}