/* 271. Multiply Polynomials */
# include <stdio.h>
int main(void){
    int f, F[100], g, G[100], H[199] = {0};
    scanf("%d", &f);
    for (int i = 0; i < f; i++)
        scanf("%d", &F[i]);
    scanf("%d", &g);
    for (int i = 0; i < g; i++)
        scanf("%d", &G[i]);
    for (int i = 0; i < f; i++){
        for (int j = 0; j < g; j++){
            H[i+j] += F[i] * G[j];
        }
    }
    printf("%d", H[0]);
    for (int i = 1; i < f+g-1; i++)
        printf(" %d", H[i]);
}