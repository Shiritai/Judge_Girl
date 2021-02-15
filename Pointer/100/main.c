#include <stdio.h>
#include <assert.h>
 
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

int main(void){
    int i, j, m;
    int array[100][100], check[100][100];
    const int *ptr_array[100][100];

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            ptr_array[i][j] = &(array[i][j]);
            scanf("%d", &(array[i][j]));
            check[i][j] = array[i][j];
        }
    }

    snake(ptr_array, m);

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            assert(check[i][j] == array[i][j]);
            assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
            printf("%d ", *(ptr_array[i][j]));
        }
        printf("\n");
    }

    return 0;
}