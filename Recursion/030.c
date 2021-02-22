/* 30. From One Corner to Another with matrix */
# include <stdio.h>

int matrix[12][12] = {{}};

int compute(int r, int c){
    if (!matrix[r][c] || r < 0 || c < 0)
        return 0;
    else if (r == 0 && c == 0)
        return 1;
    else
        return compute(r - 1, c) + compute(r, c - 1);
}

int main(void){
    int row, col;
    scanf("%d%d", &row, &col);
    for (int i = row - 1; i >= 0; --i){
        for (int j = 0; j < col; ++j)
            scanf("%d", &matrix[i][j]);
    }
    printf("%d\n", compute(row - 1, col - 1));
}