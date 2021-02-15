/* 10030. Real / Fake Thing */
# include <stdio.h>
int same_test(unsigned long long * big_num1, unsigned long long * big_num2, int len){
    int intersection = 0, uni = 0;
    unsigned long long tmp1, tmp2;
    for (int i = 0; i <= len / 64; ++i, big_num1++, big_num2++){
        tmp1 = * big_num1 & * big_num2;
        tmp2 = * big_num1 | * big_num2;
        intersection += __builtin_popcountll(tmp1);
        uni += __builtin_popcountll(tmp2);
    }
    if (5 * intersection >= 4 * uni)    return 1;
    else    return 0;
}
int main(void){
    int N, M;
    char input[1024];
    while (scanf("%d%d\n", &N, &M) != EOF){
        unsigned long long bitString[1024][9] = {};
        for (int i = 0; i < N; ++i){
            scanf("%s", input);
            for (int j = 0; j < M; ++j)    if (input[j] == '1')    bitString[i][j>>6] |= (1ull << (j & 63));
        }
        int S = 0;
        for (int i = 0; i < N-1; ++i)    for (int j = i+1; j < N; ++j)    if (same_test(bitString[i], bitString[j], M))    ++S;
        printf("%.2f\n", (float) 200*S/(N*(N-1)));
    }
    return 0;
}