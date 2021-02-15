/* 222. Bookshelf */
# include <stdio.h>
int main(){
    static unsigned long long input[10000] = {0};
    unsigned long long shelf = 0, * tmp = input;
    int i, ind = 1;
    while (scanf("%llu", &input[ind]) != EOF){
        if (input[ind] != *tmp)  ++ind, ++tmp;
        if (ind == 9999)    ind = 1, tmp = input;
    }
    if (ind < 50){
        tmp = input + 1;
        while (ind > 1){
            for (i = 0; i < 56; i += 8){
                if (((shelf >> i) & 255llu) == *tmp){
                    shelf = ((shelf & ((~0llu) << (i+8))) | ((shelf & ~((~0llu) << i))) << 8);
                    break;
                }
            }
            shelf >>= 8;
            shelf |= (*tmp << 56);
            --ind, ++tmp;
        }
        for (i = 0; i < 56; i += 8){
            printf("%llu ", (shelf >> i) & 255llu);
        }
        printf("%llu\n", (shelf >> 56) & 255llu);
    }
    else {
        for (i = ind - 8; i < ind-1; ++i)
            printf("%llu ", input[i]);
        printf("%llu\n", input[ind-1]);
    }
}