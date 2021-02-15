/* 99. Bingo */
# include <stdio.h>
# define NUM 256
int main(void){
    char player[10][65];
    int m, n, input;
    static int grid[10][NUM][NUM] = {};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        scanf("%s", player[i]);
        for (int j = 0; j < m; ++j){
            for (int k = 0; k < m; ++k)
                scanf("%d", &grid[i][j][k]);
        }
    }
    int play_ign[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, num_flag = 1, found;
    for (int h = 0; h < m * m; ++h, num_flag = 1){
        scanf("%d", &input);
        for (int i = 0; i < n; ++i){ // choose player
            found = 0;
            if (play_ign[i]){
                for (int j = 0; j < m && !found; ++j){ // No.1 var
                    for (int k = 0; k < m && ! found; ++k){ // No.2 var
                        if (grid[i][j][k] == input){
                            grid[i][j][k] = 0;
                            found = 1;

                            // /* check bingo or not, low efficiency */
                            // int horiz[NUM] = {}, vert[NUM] = {}, l_dia = 0, r_dia = 0, tmp = 0;
                            // for (int x = 0; x < m && !tmp; ++x){
                            //     for (int y = 0; y < m && (!horiz[x] || !vert[x]); ++y){
                            //         if (grid[i][x][y]) horiz[x] = 1;
                            //         if (grid[i][y][x]) vert[x] = 1;
                            //     }
                            //     if (!horiz[x] || !vert[x])  tmp = 1;
                            //     if (grid[i][x][x]) l_dia = 1;
                            //     if (grid[i][x][m-x-1]) r_dia = 1;
                            // }
                            // if (tmp || l_dia == 0 || r_dia == 0)
                            // {
                            //     play_ign[i] = 0;
                            //     if (num_flag){
                            //         printf("%d", input);
                            //         num_flag = 0;
                            //     }
                            //     printf(" %s", player[i]);
                            // }

                            /* check bingo or not */
                            int dia_l = -1, dia_r = -1, horiz = 0, vert = 0;
                            if (j == k || j + k + 1 == m){
                                dia_l = 0, dia_r = 0;
                                for (int x = 0; x < m && (!dia_r || !dia_l); ++x){
                                    if (grid[i][x][x]) dia_l = 1;
                                    if (grid[i][x][m-x-1]) dia_r = 1;
                                }
                            }
                            for (int y = 0; y < m && (!horiz || !vert); ++y){
                                if (grid[i][j][y]) horiz = 1;
                                if (grid[i][y][k]) vert = 1;
                            }
                            if (!horiz || !vert || dia_r == 0 || dia_l == 0){
                                play_ign[i] = 0;
                                if (num_flag){
                                    printf("%d", input);
                                    num_flag = 0;
                                }
                                printf(" %s", player[i]);
                            }
                        }
                    }
                }
            }
        }
        if (!num_flag){
            printf("\n");
            goto end;
        }
    }
    end : return 0;
}