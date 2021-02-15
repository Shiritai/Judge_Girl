/* 54. Number of Appearance */
# include <stdio.h>
int real_10_power(int x);
int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    int M_dig[7] = {0};
    int N_dig[2] = {0};
    /* fetch digit */
    for (int i = 6; i > -1; i--){
        int temp = real_10_power(i);
        M_dig[i] = M / temp;
        M -= temp * M_dig[i];
    }
    for (int i = 1; i > -1; i--){
        int temp = real_10_power(i);
        N_dig[i] = N / temp;
        N -= temp * N_dig[i];
    }
    /* compare */
    int counter = 0;
    for (int i = 6; i > 0; i--){
        if (N_dig[1] == M_dig[i] && N_dig[0] == M_dig[i-1])
            counter++;
    }
    printf("%d", counter);
}
int real_10_power(int x){
    int y = 1;
    for (int i = 0; i < x; i++)
        y *= 10;
    return y;
}