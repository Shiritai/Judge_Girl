/* 55. The Robots */
# include <stdio.h>
int main(void){
    int M, N, x1, y1, E1, N1, f1, x2, y2, E2, N2, f2, time = 0, flag = 1;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &M, &N, &x1, &y1, &E1, &N1, &f1, &x2, &y2, &E2, &N2, &f2);
    for (int n1 = N1, e1 = E1, n2 = N2, e2 = E2; !(f1 == 0 && f2 == 0) && flag; ++time){
        if (f1){
            if (n1 > 0){
                ++y1, --n1;
                if (y1 == N)
                    y1 = 0;
            }
            else if (e1 > 0){
                ++x1, --e1;
                if (x1 == M)
                    x1 = 0;
            }
            --f1;
        } 
        if (f2){
            if (e2 > 0){
                ++x2, --e2;
                if (x2 == M)
                    x2 = 0;
            }
            else if (n2 > 0){
                ++y2, --n2;
                if (y2 == N)
                    y2 = 0;
            }
            --f2;
        } 
        if (n1 == 0 && e1 == 0 && f1 > 0)
            n1 = N1, e1 = E1;
        if (n2 == 0 && e2 == 0 && f2 > 0)
            n2 = N2, e2 = E2;
        if (x1 == x2 && y1 == y2){
            printf("robots explode at time %d\n", time+1);
            flag = 0;
        }
    }
    // printf("\nR1 : (%d, %d)\nR2 : (%d, %d)\ntime : %d\n", x1, y1, x2, y2, time);
    if (flag)
        printf("robots will not explode\n");
    return 0;
}