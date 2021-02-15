/* 10031. Fast 64-bits Modular Arithmetic  */
# include <stdio.h>
int main(void){
    unsigned long long a, b, n;
    while (scanf("%llu%llu%llu", &a, &b, &n) == 3){
        a %= n, b %= n;
        if (a == 0 || b == 0){
            puts("0");
            continue;
        }
        unsigned long long ans = 0llu;
        for (; b > 0; b >>= 1, a %= n){
            if (b & 1llu == 1)
                ans = (ans + a) % n;
            a = a * 2;
        }
        printf("%llu\n", ans);
    }
    return 0;
}