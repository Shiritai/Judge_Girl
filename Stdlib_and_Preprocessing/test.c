/* 85. Sort Dates */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int comp(const void * data1, const void * data2){
    printf("%d %d %d\n", * (int *) data1, * (int *) data2, * (int *) data1 - * (int *) data2);
    return * (int *) data1 - * (int *) data2;
}

int main(void){
    int a[4] = {1, 4, 2, 3};
    qsort(a, 4, sizeof(int), comp);
    for (int i = 0; i < 4; ++i)
        printf("%d ", a[i]);
    // printf("%d\n", strcmp("a", "b"));
    // printf("%d\n", a);
}