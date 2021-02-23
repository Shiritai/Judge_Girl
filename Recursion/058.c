/* 58. Lakes */
# include <stdio.h>
# include <stdlib.h>

int n, m, matrix[400][400] = {{}};

int lake_recur(int cur_row, int cur_col);

int comp(const void * data1, const void * data2){
    return * (int *) data1 < * (int *) data2;
}

// void print(void){ // for debug
//     for (int i = 0; i < n; ++i, puts("")) for (int j = 0; j < m; ++j) printf("%2d ", matrix[i][j]);
//     puts("");
//     return;
// }

int main(void){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j)
            scanf("%d", &matrix[i][j]);
    }
    int lakes[80002] = {}, lake_ind = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (matrix[i][j] == 1){
                lakes[lake_ind] = lake_recur(i, j);
                // printf("lakes[%d] : %d\n", lake_ind, lakes[lake_ind]);
                lake_ind++;
                // print();
            }
        }
    }
    qsort(lakes, lake_ind, sizeof(int), comp);
    for (int i = 0; i < lake_ind; ++i)
        printf("%d\n", lakes[i]);
}

int lake_recur(int cur_row, int cur_col){
    if (cur_row >= n || cur_row < 0 || cur_col < 0 || cur_col >= m || matrix[cur_row][cur_col] != 1)
        return 0;
    else {
        matrix[cur_row][cur_col] = -1;
        return 1 + lake_recur(cur_row + 1, cur_col) + lake_recur(cur_row, cur_col + 1) \
            + lake_recur(cur_row - 1, cur_col) + lake_recur(cur_row, cur_col - 1);
    }
}