/* 85. Sort Dates */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define NUM 1000000

int comp(const void * data1, const void * data2){
    return ((* (int *) data1) << 9) + ((* ((int *) data1 + 1)) << 5) + (* ((int *) data1 + 2)) \
        > ((* (int *) data2) << 9) + ((* ((int *) data2 + 1)) << 5) + (* ((int *) data2 + 2)) ? 1 : -1;
}

int main(void){
    int nums = 0;
    static int dates[NUM][3];
    scanf("%d", &nums);
    for (int i = 0; i < nums; ++i){
        scanf("%d %d %d", &dates[i][0], &dates[i][1], &dates[i][2]);
    }
    qsort(dates, nums, sizeof(dates[0]), comp);
    // puts("___after qsort___");
    for (int i = 0; i < nums; ++i)
        printf("%d %d %d\n", dates[i][0], dates[i][1], dates[i][2]);
    return 0;
}