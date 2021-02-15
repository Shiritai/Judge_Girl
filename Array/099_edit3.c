/* 99. Bingo */
# include <stdio.h>
# define DEBUG
# ifdef DEBUG
# include <time.h>
# endif
# define NUM 256
int main(void){
# ifdef DEBUG
    clock_t start, off;
# endif
    int m, n, input;
    static int grid[10][NUM][NUM] = {}/* , * gPtr = grid */;
    char player[10][65];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        scanf("%s", player[i]);
        for (int j = 0; j < m; ++j){
            for (int k = 0; k < m; ++k)
                scanf("%d", &grid[i][j][k]);
        }
    }
# ifdef DEBUG
    start = clock();
# endif
    _Bool num_flag = 1, found;
    while (scanf("%d", &input) == 1){ // scan input
        for (int i = 0; i < n; ++i){ // choose player
            found = 0;
            /* find input in grid */
            for (int j = 0; j < m && !found; ++j){ // No.1 var
                for (int k = 0; k < m && !found; ++k){ // No.2 var
                    if (grid[i][j][k] == input){
                        grid[i][j][k] = 0;
                        found = 1;
                        /* check bingo or not */
                        int a = 0, b = 0, c = 0, d = 0;
                        for (; c < m && !grid[i][j][c]; ++c);
                        for (; d < m && !grid[i][d][k]; ++d);
                        if (j == k)
                            for (; a < m && !grid[i][a][a]; ++a);
                        if (j + k + 1 == m)
                            for (; b < m && !grid[i][b][m-b-1]; ++b);
                        /* bingo */
                        if (a == m || b == m || c == m || d == m){
                            if (num_flag){
                                printf("%d", input);
                                num_flag = 0;
                            }
                            printf(" %s", player[i]);
                        }
                        // /* next player's turn */
                        // goto next;
                    }
                }
            }
            // next : ;
        }
        if (!num_flag){
            printf("\n");
# ifdef DEBUG
            off = clock();
            printf("%lf\n", (double) (off - start) / CLOCKS_PER_SEC);
# endif
            goto end;
        }
    }
    end : return 0;
}