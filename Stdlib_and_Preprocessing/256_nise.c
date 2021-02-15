/* 256. One Count Sorting */
/* use qsort and try again! */
# include <stdio.h>
# define num 1000
# define BitLen 64
int main(void){
    long long a[num] = {0}, mask = 1, tmp_ll;
    int ones[num] = {0}, tmp_int;
    int cnt = 0, i, j;
    while (scanf("%lld", &a[cnt]) != EOF){
        for (i = 0, tmp_int = 0, tmp_ll = a[cnt]; i < BitLen - 1; i++){ // don't change a[cnt]
            tmp_int += tmp_ll & mask;
            tmp_ll >>= 1;
        }
        ones[cnt] = tmp_int;
        cnt++;
    }
    /* bubble sort */
    /* review: aPtr[1] = * (aPtr + 1) is a "value" */
    long long * aPtr = a;
    int * onePtr = ones;
    for (i = cnt - 2; i >= 0; i--){
        for (j = 0; j <= i; j++){
            if (onePtr[j] > onePtr[j+1] || (onePtr[j] == onePtr[j+1] && aPtr[j] > aPtr[j+1])){
                tmp_ll = aPtr[j], tmp_int = onePtr[j];
                aPtr[j] = aPtr[j+1], onePtr[j] = onePtr[j+1];
                aPtr[j+1] = tmp_ll, onePtr[j+1] = tmp_int;
            }
        }
    }
    for (i = 0; i < cnt; i++)
        printf("%lld\n", aPtr[i]);
}