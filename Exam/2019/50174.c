# include <stdio.h>
# include <stdint.h>
# include <inttypes.h> 
# define N 63

/* mode 為 0 : 以零為主體，指定一個位子為 1 (from 0 ~ 63); mode 為 1 則相反 */
uint64_t mask_generator(int position, int mode){
    return (((uint64_t) 1ull) << position) ^ ((mode) ? (uint64_t) 0xffffffffffffffff : (uint64_t) 0);
}

/* 交換 a 之 position 以及 position + 1 的位元 */
void swap_near_bit(uint64_t * a, int position){
    * a ^= (mask_generator(position, 0) | mask_generator(position + 1, 0));
}

/* 返回 position (from 0 ~ 63) 的位元值, 0 或 1 */
int check_bit(uint64_t n, int position){
    return (n & mask_generator(position, 0)) != 0;
}

/* for debuging */
void printBit(uint64_t num){
    uint64_t mask = 1ull << N;
    int cnt = 0;
    while (cnt <= N){
        putchar((num & mask) ? '1' : '0');
        mask >>= 1;
        ++cnt;
    }
    puts("");
}

void BubbleSort(uint64_t input, uint64_t output[N]){
    for (int i = N - 1; i >= 0; --i){
        for (int j = i - 1; j >= 0; --j){
            if (check_bit(input, j) == 0 && check_bit(input, j + 1) == 1)
                swap_near_bit(&input, j);
        }
        // printBit(input);
        output[62 - i] = input;
    }
}

int main(){
    uint64_t input;
    uint64_t output[N];
 
    scanf("%I64lu", &input);
    // printBit(input);

    BubbleSort(input, output);
    for(int i = 0; i < N; i++)
        printf("%" PRIx64 "\n", output[i]);
    return 0;
}