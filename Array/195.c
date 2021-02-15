/* 195. Tic-Tac-Toe */
# include <stdio.h>
# define side_len 3
int main(void){
    int grid[side_len][side_len] = {}, turn, x, y, flip = -1, inputCnt = 0;
    char result[3][20] = {"Black wins.", "There is a draw.", "White wins."};
    scanf ("%d", &turn);
    while (turn > 0){
        do {
            scanf("%d%d", &x, &y);
            --turn;
            if (!turn && grid[y][x]){
                printf("%s\n", result[1]);
                goto end;
            }
        }
        while ((x > 2 || x < 0 || y > 2 || y < 0 || grid[y][x]) && turn);

        grid[y][x] = flip;
        ++inputCnt;

        int a = 0, b = 0, c = 0, d = 0;
        for (; a < side_len && grid[a][x] == flip; ++a);
        for (; b < side_len && grid[y][b] == flip; ++b);
        if (x == y)
            for (; c < side_len && grid[c][c] == flip; ++c);
        if (x + y + 1 == side_len)
            for (; d < side_len && grid[d][side_len-d-1] == flip; ++d);
        
        if (a == side_len || b == side_len || c == side_len || d == side_len){
            printf("%s\n", result[flip+1]);
            goto end;
        }

        if (inputCnt == side_len * side_len){
            printf("%s\n", result[1]);
            goto end;
        }

        flip *= -1;
    }
    printf("%s\n", result[1]);
    end : return 0;
}