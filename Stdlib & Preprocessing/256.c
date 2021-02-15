/* 256. One Count Sorting */
/* didn't passed */
# include <stdio.h>
# include <stdlib.h> // qsort
# define LL long long
# define num 1000
int comp(const void * data1, const void * data2);
int main (void){
    LL a[num] = {0};
    int cnt = 0, i;
    while (scanf("%lld", &a[cnt]) != EOF){
        cnt++;
    }
    qsort(a, cnt, sizeof(LL), comp);
    for (i = 0; i < cnt; i++)
        printf("%lld\n", a[i]);
    return 0;
}
int comp(const void * data1, const void * data2){
    LL * magPtr1 = (LL *) data1, * magPtr2 = (LL *) data2, mask = 1;
    LL tmp_ll_1 = * magPtr1, tmp_ll_2 = * magPtr2;
    int tmp1, tmp2;
    for (tmp1 = 0, tmp2 = 0; tmp_ll_1 > 0; tmp_ll_1 >>= 1, tmp_ll_2 >>= 1){
        tmp1 += tmp_ll_1 & mask;
        tmp2 += tmp_ll_2 & mask;
    }
    if (tmp1 > tmp2 || (tmp1 == tmp2 && * magPtr1 > * magPtr2))
        return 1;
    else
       return -1;
    return 0;
}