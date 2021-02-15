/* 10006. Sum of Integers */
# include <stdio.h>
int main(void){
    int sum = 0, tmp;
    for (; scanf("%d", &tmp) != EOF; sum += tmp);
    printf("%d\n", sum);
    return 0;
}