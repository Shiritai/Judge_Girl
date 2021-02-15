/* 100. Snake Order */
# include "snake.h"

void snake(const int *ptr_array[100][100], int m){
    int * list[10000], * tmp, ind = 0;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < m; ++j, ++ind){
            list[ind] = ptr_array[i][j];
        }
    }
    /* bubble sort */
    for (int i = m * m - 2; i >= 0; --i){
        for (int j = 0; j <= i; ++j){
            if (*list[j] > *list[j+1]){
                tmp = list[j];
                list[j] = list[j+1];
                list[j+1] = tmp;
            }
        }

    }
    ind = 0;
    for (int i = 0; i < m; ++i){
        if (i & 1){
            for (int j = m - 1; j >= 0; --j, ++ind){
                ptr_array[i][j] = list[ind];
            }
        }
        else {
            for (int j = 0; j < m; ++j, ++ind){
                ptr_array[i][j] = list[ind];
            }
        }
    }
    return;
}