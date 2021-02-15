/* 74. Mn, Mn + 1, ... Mn + M - 1 */
# include <stdio.h>
int main(void){
    int N, M;
    static int nums[200000] = {0};
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &nums[i]);
    scanf("%d", &M);
    static int remainder[100000] = {0};
    for (int i = 0; i < N; ++i)
        remainder[nums[i] % M]++;
    for (int i = 0; i < M; ++i)
        printf("%d\n", remainder[i]);
    // for (int i = 0; i < N; i++){
    //     for (int j = 0; j < M; j++){
    //         if (nums[i] % M == j)
    //             remainder[j]++;
    //     }
    // }
    // for (int i = 0; i < M; i++)
    //     printf("%d\n", remainder[i]);
}