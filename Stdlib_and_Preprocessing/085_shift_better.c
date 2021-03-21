/* 85. Sort Dates */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define NUM 1000000

int comp(const void * data1, const void * data2){
    return * (long long *) data1 > * (long long *) data2 ? 1 : -1;
}

int main(void){
    int nums = 0;
    long long tmp1, tmp2, tmp3;
    static long long dates[NUM];
    scanf("%d", &nums);
    for (int i = 0; i < nums; ++i){
        scanf("%lld %lld %lld", &tmp1, &tmp2, &tmp3);
        dates[i] = (tmp1 << 9) + (tmp2 << 5) + tmp3;
    }
    qsort(dates, nums, sizeof(dates[0]), comp);
    // puts("___after qsort___");
    for (int i = 0; i < nums; ++i)
        printf("%lld %lld %lld\n", dates[i] >> 9, (dates[i] >> 5) & 15, dates[i] & 31);
    return 0;
}