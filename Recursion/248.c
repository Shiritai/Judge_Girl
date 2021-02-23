/* 248. Mine Field */
# include <stdio.h>
# include <string.h>

_Bool solve(int, int);

char mine_field[81] = "", tmp_ans[81] = "", mine_field_copy[81] = "";

int main(void){
    int tmp;
    for (int i = 0; i < 81; ++i){
        scanf("%d", &tmp);
        sprintf(mine_field, "%s%d", mine_field, tmp);
    }
    strcpy(mine_field_copy, mine_field);
    char ans[81] = "";
    if (solve(8, 8)){
        // puts("");
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j)
                printf("%c ", mine_field[i*9+j]);
            puts("");
        }
    }
    else 
        puts("no solution").

}

_Bool solve(int pos_y, int pos_x){
    _Bool put_bomb = 1;
    for (int i = -1; i < 2; ++i){
        for (int j = -1; j < 2; ++j){
            if (pos_y + i >= 0 && pos_y + i < 9 && pos_x + j < 9 && pos_x + j >= 0){
                if (!mine_field_copy[pos_y + i][pos_x + j])
                    put_bomb = 0;
            }
        }
    }
    if (put_bomb){
        for (int i = -1; i < 2; ++i){
            for (int j = -1; j < 2; ++j){
                if (pos_y + i >= 0 && pos_y + i < 9 && pos_x + j < 9 && pos_x + j >= 0){
                    if (!mine_field_copy[pos_y + i][pos_x + j])
                        mine_field_copy[pos_y + i][pos_x + j]--;
                }
            }
        }
    }
    else {
        
    }

}

