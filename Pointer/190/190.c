/* 190. Function Evaluation */
# include <stdio.h>
int evaluate_f(int * iptr[], int n, int * index){
    int i = 0, result_val, result_ind, tmp;
    result_val = (* iptr[i]) * 4 - (* (iptr[i]+1)) * 6, result_ind = i;
    for (i = 1; i < n; ++i){
        tmp = (* iptr[i]) * 4 - (* (iptr[i]+1)) * 6;
        if (tmp > result_val){
            result_val = tmp;
            result_ind = i;
        }
    }
    * index = result_ind;
    return result_val;
}
int main(void){
    int a[] = { 9, 7 };
    int b[] = { 3, 2 };
    int c[] = { 3, 2 };
    int d[] = { 9, 7 };
    int *iptr[] = { a, b, c, d };
    int max, index;
    max = evaluate_f(iptr, 4, &index);
    printf("%d %d\n", max, index);
}