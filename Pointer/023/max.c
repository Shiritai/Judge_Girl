/* 23. Maximum in Pointer Array */
# include "max.h"
int max(int *iptr[], int n){
    for (int i = 1; i < n; i++)
        iptr[0] = (*iptr[i] > *iptr[0]) ? iptr[i] : iptr[0];
    return (* iptr[0]);
}