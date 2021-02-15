/* 38. Witchcraft */
/* didn't use recursion...*/
# include <stdio.h>
# include <stdbool.h>
# define LL long long
static LL A, B, C, D; // const
bool ABC(int a, int b, int c){
    int i, j, k;
    LL tmp;
    bool judge = false;
    for (i = 0; i <= a; i++){
        tmp = 0;
        for (j = 0; j <= b; j++){
            tmp = 0;
            for (k = 0; k <= c && tmp <= D && judge == false; k++){
                tmp = A*i + B*j + C*k;
                judge =  (tmp == D);
            }
        }
    }
    return judge;
}
int main(void){
    int N, i, a, b, c;
    scanf("%d", &N);
    for (i = 0; i < N; i++){
        scanf("%d%d%d%d%lld%lld%lld", &D, &a, &b, &c, &A, &B, &C);
        if (D == 0 || (A == 1 && a >= D) || (B == 1 && b >= D) || (C == 1 && c >= D))
            printf("yes\n");
        else if (ABC(a, b, c))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}