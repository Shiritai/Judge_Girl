/* 28. Sum of Squares with Recursion */
# include <stdio.h>
int sum_sq(int a){
    if (a == 1) return 1;
    return a*a + sum_sq(a-1);
}
int main(void){
    int num;
    scanf("%d", &num);
    printf("%d", sum_sq(num));
}