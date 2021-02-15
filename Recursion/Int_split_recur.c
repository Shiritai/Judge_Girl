/* Spliting integer use recursive func. */
# include <stdio.h>
# include <stdint.h>
int64_t Pkn(int k, int n);
int64_t Pn(int n);
int main(void){
    int n;
    fscanf(stdin, "%d", &n);
    printf("%lld", Pn(n));
}
int64_t Pn(int n){
    if (n == 1){
        return 1;
    }
    int i = 1; // at least split to 1 piece
    int64_t sum = 0;
    for (; i <= n; i++){
        sum += Pkn(i, n);
    }
    return sum;
}
int64_t Pkn(int k, int n){
    if (k > n){
        return 0;
    }
    else if (k == 1){
        return 1;
    }
    return Pkn(k - 1, n - 1) + Pkn(k, n - k);
}