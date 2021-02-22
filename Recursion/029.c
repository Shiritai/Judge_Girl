/* 29. From One Corner to Another */
# include <stdio.h>

int compute(int r, int c){
    if (r == 0 || c == 0)
        return 1;
    return compute(r - 1, c) + compute(r, c - 1);
}

int main(void){
    int row, col;
    scanf("%d%d", &row, &col);
    printf("%d\n", compute(row - 1, col - 1));
}