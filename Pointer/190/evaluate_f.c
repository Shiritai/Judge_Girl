# include "evaluate_f.h"
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