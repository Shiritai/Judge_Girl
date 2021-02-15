/* 53. Permutation */
# include <stdio.h>
# include <stdlib.h>

int num, tmp[10] = {}, list[10] = {};
_Bool check[10] = {};

int comp(const void * a, const void * b){
    return * (int *) a > * (int *) b;
}

void permute(int depth){
    if (depth == num){
        for (int i = 0; i < num; ++i){
            printf("%d%c", tmp[i], " \n"[i == num - 1]);
        }
        return;
    }    
    else {
        for (int i = 0; i < num; ++i){
            if (!check[i]){
                tmp[depth] = list[i];
                check[i] = 1;
                permute(depth + 1);
                check[i] = 0;
            }
        }
    }
}

int main(void){
    scanf("%d", &num);
    for (int i = 0; i < num; ++i)
        scanf("%d", &list[i]);
    qsort(list, num, sizeof(int), comp);
    // permute(list, 0, num - 1); // old permute, discard
    permute(0);
    return 0;
}