/* 248. Mine Field */
# include <stdio.h>
# define LEN 9
# define EXTEND_LEN 11

int mine_field[LEN][LEN] = {}, result[EXTEND_LEN][EXTEND_LEN] = {};

void put_bomb(int x, int y){
    /* get result */
    if (y == LEN){
        _Bool ok = 0;
        for (int i = 0; i < LEN; ++i){
            ok = ok || mine_field[0][i];
        }
        if (!ok){
            for (int i = 1; i < EXTEND_LEN; ++i){
                for (int j = 1; j < EXTEND_LEN; ++j){
                    printf("%d%c", result[i][j], " \n"[j == EXTEND_LEN - 1]);
                }
            }
        }
        else 
            puts("no solution");
        return;
    }
    else {
        /* 1. don't put bomb */
        if (!(y < LEN && y >= 0 && x < LEN && x >= 0) || !mine_field[y - 1][x - 1]){
            result[y + 1][x + 1] = 0;
            /* recur */
            if (x == 8){
                if (y < 2 || mine_field[y - 2][8] == 0){
                    put_bomb(0, y + 1);
                }
            }
            else 
                put_bomb(x + 1, y);
        }
        /* 2. put bomb */
        if (!(y < LEN && y >= 0 && x < LEN && x >= 0) || mine_field[y - 1][x - 1] == 1){
            if (can_put(x, y)){
                result[y + 1][x + 1] = 1;
                for (int i = -1; i <= 1; ++i){
                    for (int j = -1; j <= 1; ++j){
                        if (y + i < LEN && y + i >= 0 && x + j < LEN && x + j >= 0)
                            --mine_field[y + i][x + j];
                    }
                }
                /* recur */
                if (x == 8)
                    put_bomb(0, y + 1);
                else 
                    put_bomb(x + 1, y);
                /* refresh mine_field */
                for (int i = -1; i <= 1; ++i){
                    for (int j = -1; j <= 1; ++j){
                        if (!(y + i >= 9 || y + i < 0 || x + j >= 9 || x + j < 0))
                            ++mine_field[y + i][x + j];
                    }
                }
            }
        }
    }
    return;
}

_Bool can_put(int x, int y){
    int tmp = 0;
    for (int i = -1; i <= 1; ++i){
        for (int j = -1; j <= 1; ++j){
            if (result[y + i + 1][x + j + 1])
                ++tmp;
        }
    }
    if (tmp < mine_field[y][x])
        return 1;
    return 0;
}

int main(void){
    for (int i = 0; i < LEN; ++i){
        for (int j = 0; j < LEN; ++j){
            scanf("%d", &mine_field[i][j]);
        }
    }
    put_bomb(0, 0);
}