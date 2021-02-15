/* 236. Least Common Multiplier */
/* finding the least common multiplier is the same as to find the greatesr commom divisor */
# include <stdio.h>
# include <math.h>
int gcd(int a, int b);
int main(void){
    static int Nums[100000] = {1};
    int cnt = 0;
    int tmp_lcm, tmp_mul, tmp_gcd;
    while (scanf("%d", &Nums[cnt]) >= 1){
        for (int i = 0; i < cnt; i++){
            tmp_lcm = tmp_mul / tmp_gcd;
        }
        cnt++;
    }
    printf("%d", tmp_mul);
}
int gcd(int a, int b){ // Euclidean Algorithm
    while (b != 0){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}