/* 218. Sum of Selections */
# include <stdio.h>
int Count(int x, int y){
    int numerator = 1, denominator = 1;
    for (int i = 0; i < y; i++)
        numerator *= (x-i), denominator *= (i+1);
    return numerator/denominator;
}
int C_sum (int a, int b){
    int sum = 1; // 取 0 都是 1, 提早加上
    for (int i = 1; i <= b; i++)
        sum += Count(a, i);
    return sum;
}
int main (void){
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", C_sum(n, m));
}