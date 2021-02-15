/* 10030. Real / Fake Thing */
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# define numLen 8
# define llBitSize (sizeof(long long) * 8) // 1 byte = 8bits
bool same_test(long long *, long long *, int);
void add_bit(long long *, int);
int main(void){
    int N, M;
    char tmp;
    while (scanf("%d%d\n", &N, &M) != EOF){
        long long bitString[1024][numLen] = {{0}};
        /* input */
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                do {scanf("%c", &tmp);} while (tmp == ' ' || tmp == '\n'); // beautiful input method OwO
                if (tmp == '1'){
                    // add_bit(bitString[i], j);
                    bitString[i][j>>6] |= (1ll << (j & 63));
                }
            }
        }
        // /* test array */
        // for (int i = 0; i < N; ++i){
        //     for (int j = 0; j < 1; ++j){
        //         for (long long k = 1, time = 0; time < 10; k <<= 1, ++time){
        //             printf("%d", (bitString[i][j] & k) >> time);
        //         }
        //         putchar('\n');
        //     }
        //     putchar('\n');
        // }
        /* test pairs */
        int S = 0;
        for (int i = 0; i < N-1; ++i){
            for (int j = i+1; j < N; ++j){
                if (same_test(bitString[i], bitString[j], M))
                    ++S;
            }
        }
        printf("%.2f\n", (float) 200*S/(N*(N-1)));
    }
    return 0;
}
void add_bit(long long * big_num, int place){
    big_num += (int) place/llBitSize;
    * big_num |= 1ll << place;
    return;
}
bool same_test(long long * big_num1, long long * big_num2, int len){
    int intersection = 0, uni = 0;
    long long tmp1, tmp2;
    for (int i = 0; i <= len / llBitSize; ++i, big_num1++, big_num2++){
        // tmp1 = ~(* big_num1 ^ * big_num2);
        tmp1 = * big_num1 & * big_num2;
        tmp2 = * big_num1 | * big_num2;
        // for (long long j = 1, time = 0; time < llBitSize; j <<= 1, ++time){
        //     if (tmp1 & j)
        //         ++intersection;
        //     if (tmp2 & j)
        //         ++uni;
        // }
        intersection += __builtin_popcountll(tmp1);
        uni += __builtin_popcountll(tmp2);
    }
    // printf("inter : %d\nunion : %d\n", intersection, uni);
    // printf("S -> %f\n", (float) intersection / uni);
    // if ((float) intersection / uni >= 0.8f);
    if (5 * intersection >= 4 * uni){
        return true;
    }
    return false;
}