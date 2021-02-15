/* 99. Bingo */ // 以空間換取時間，三倍空間換取差非常多的搜尋時間
# include <stdio.h>
// # define DEBUG
# ifdef DEBUG
# include <time.h>
# endif
# define NUM 256
int main(void){
# ifdef DEBUG
    clock_t start, off;
# endif
    int m, n, input;
    static int grid[10][NUM][NUM] = {}, coo_map[10][NUM * NUM][2] = {}; // 0 : row mark for col search; 1 : col mark for row search
    char player[10][65];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        scanf("%s", player[i]);
        for (int j = 0; j < m; ++j){
            for (int k = 0; k < m; ++k){
                scanf("%d", &input);
                // grid[i][j][k] = input; // actually, "grid[i][j][k] = 1" is better, just for extention someday
                grid[i][j][k] = 1;
                coo_map[i][input][0] = j;
                coo_map[i][input][1] = k;
            }
        }
    }
# ifdef DEBUG
    start = clock();
# endif
    _Bool num_flag = 1;
    while (scanf("%d", &input) == 1){ // scan input
        for (int i = 0; i < n; ++i){ // choose player
            grid[i][coo_map[i][input][0]][coo_map[i][input][1]] = 0;
            /* check bingo or not */
            int a = 0, b = 0, c = 0, d = 0;
            for (; c < m && !grid[i][coo_map[i][input][0]][c]; ++c);
            for (; d < m && !grid[i][d][coo_map[i][input][1]]; ++d);
            if (coo_map[i][input][0] == coo_map[i][input][1])
                for (; a < m && !grid[i][a][a]; ++a);
            if (coo_map[i][input][0] + coo_map[i][input][1] + 1 == m)
                for (; b < m && !grid[i][b][m-b-1]; ++b);
            /* bingo */
            if (a == m || b == m || c == m || d == m){
                if (num_flag){
                    printf("%d", input);
                    num_flag = 0;
                }
                printf(" %s", player[i]);
            }
        }
        if (!num_flag){
            printf("\n");
# ifdef DEBUG
            off = clock();
            printf("time comsume : %lf (sec)\n", (double) (off - start) / CLOCKS_PER_SEC);
# endif
            goto end;
        }
    }
    end : return 0;
}