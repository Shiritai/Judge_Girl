/* 234. Factorization */
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# define abs(x) (x>0)?x:-x
int main(void){
    int a, b, c, i, j, k, l;
    scanf("%d%d%d", &a, &b, &c);
    int find_fac[100000] = {0}, f_faCnt = 0;
    int fac[100000] = {0}, faCnt = 0;
    bool flag = true, a_sit = false, b_sit = false;
    if (c != 0){
        int C = abs((c));
        /* find factor */
        for (i = 1; i <= C / 2; i++){
            if (!(C % i)){
                find_fac[f_faCnt] = i;
                f_faCnt++;
            }
        }
        find_fac[f_faCnt] = C, f_faCnt++;
        /* make +- factor array */
        for (i = 0; i < f_faCnt; i++){
            fac[i] = -find_fac[f_faCnt-i-1];
            fac[f_faCnt+i] = find_fac[i];
            faCnt += 2;
        }
        /* give all combination and match them */
        for (i = 0; i < faCnt && flag; i++){
            for (j = 0; j < faCnt && flag; j++){
                for (k = 0; k < faCnt && flag; k++){
                    a_sit = (fac[i]+fac[j]+fac[k] == a);
                    b_sit = (fac[i]*fac[j] + fac[j]*fac[k] + fac[k]*fac[i] == b);
                    if (a_sit && b_sit){
                        printf("%d %d %d", fac[i], fac[j], fac[k]);
                        flag = false;
                    }
                }
            }
        }
    }
    else { // there are at least one "x = 0"
        if (b == 0){ // there are at least two "x = 0"  
            if (a > 0)
                printf("%d %d %d", 0, 0, a);
            else if (a < 0)
                printf("%d %d %d", a, 0, 0);
            else
                printf("%d %d %d", 0, 0, 0);
        }
        else {
            int B = abs((b));
            /* find factor */
            for (i = 1; i <= B / 2; i++){
                if (!(B % i)){
                    find_fac[f_faCnt] = i;
                    f_faCnt++;
                }
            }
            /* make +- factor array */
            for (i = 0; i < f_faCnt; i++){
                fac[i] = -find_fac[f_faCnt-i-1];
                fac[f_faCnt+i] = find_fac[i];
                faCnt += 2;
            }
            int ans[3] = {0};
            for (j = 0; j < faCnt && flag; j++){
                for (k = 0; k < faCnt && flag; k++){
                    if (fac[j]+fac[k] == a && fac[j] * fac[k] == b){
                        ans[0] = fac[j], ans[1] = fac[k];
                        for (i = 3 - 2; i >= 0; i--){
                            for (j = 0; j <= i; j++){
                                if (ans[j] > ans[j+1])
                                    ans[j] ^= ans[j+1] ^= ans[j] ^= ans[j+1];
                            }
                        }
                        printf("%d %d %d", ans[0], ans[1], ans[2]);
                        flag = false;
                    }
                }
            }
        }
    }
    return 0;
}