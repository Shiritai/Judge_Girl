/* 99. Bingo */
# include <stdio.h>
# define max_player 10
# define max_num 256 // horiz, vert, left_diagnose, right_diagnose
int main(void){
    int player, indice;
    scanf("%d%d", &player, &indice);
    /* variables in bingle */
    char name[max_player][64] = {'0'};
        /* to declare a big matrix in a function,
        add 'static' to represent the variable that will stay in MEM until the end of the program */
    static int paper[max_player][max_num][max_num] = {0}; // player, vert., horiz.
    int called[max_num*max_num] = {0};
    /* scan paper */
    for (int h = 0; h < player; h++){
        scanf("%s", &name[h]);
        for (int i = 0; i < indice; i++){
            for (int j = 0; j < indice; j++){
                scanf("%d", &paper[h][i][j]);
            }
        }
    }
    /* scan called numbers */
    int nums = indice*indice;
    for (int i = 0; i < nums; i++)
        scanf("%d", &called[i]);
    /* mark called num on player's paper */
    int win_num_order[max_player] = {0};
    int loop_brk = 0;
    for (int g = 0; g < player; g++){ // player
        loop_brk = 0;
        for (int h = 0; h < nums, loop_brk != 1; h++){ // called num
            /* set refreshing variables */
            int temp[5] = {0}; // record temp data such as...
                // [0] row and [1] column (before break), [2-5] is the sum of possibilities
            /* mark called num */
            for (int i = 0; i < indice, loop_brk != 1; i++){  // vert.
                for (int j = 0; j < indice, loop_brk != 1; j++){ // horiz.
                    if (paper[g][i][j] == called[h]){
                        paper[g][i][j] = -1, loop_brk = 1; // set break signal
                        temp[0] = i, temp[1] = j; // fetch row and column
                    }
                }
            }
            loop_brk = 0; // reset break signal
            /* Case 1 : only check vert. and horiz. */
            if (temp[0] != temp[1]){
                for (int i = 0; i < indice; i++){
                    temp[2] += paper[g][i][temp[1]]; // vert.
                    temp[3] += paper[g][temp[0]][i]; // horiz.
                }
                if (temp[2] == -indice || temp[3] == -indice)
                    win_num_order[g] = h, loop_brk = 1;
                printf("No.%d: vert. = %2d\thoriz. = %2d\n", h, temp[2], temp[3]);
            }
            /* Case 2 : check vert., horiz., left and right diagnose */
            else if (temp[0] == temp[1] || temp[0] + temp[1] == indice-1){
                for (int i = 0; i < indice; i++){
                    temp[2] += paper[g][i][temp[0]]; // vert.
                    temp[3] += paper[g][temp[1]][i]; // horiz.
                }
                for (int i = 0; i < indice; i++){
                    temp[4] += paper[g][i][i]; // left
                    temp[5] += paper[g][i][indice-i-1]; // right
                }
                if (temp[2] == -indice || temp[3] == -indice \
                    || temp[4] == -indice || temp[5] == -indice)
                    win_num_order[g] = h, loop_brk = 1;
                printf("No.%d: vert. = %2d\thoriz. = %2d\tl-diag = %2d\tr-diag = %2d\n", h, temp[2], temp[3], temp[4], temp[5]);
            }
        }
    }
    /* before print, fetch winner from the array of "win_num_order" */
    /* win_num_order[ PERSON_ORDER ] = WIN_NUM_ORDER */
    int winner[max_player] = {0}, winning_num = 0, index = 0;
    int flag = 0;
    for (int h = 0; h < player; h++){
        for (int i = 0; i < player; i++){
            if (win_num_order[h] <= win_num_order[i])
                flag++;
        }
        if (flag == player){
            winner[index] = h, winning_num = win_num_order[h];
            index++;
        }
    }
    /* output test */
    printf("\n\n");
    for (int h = 0; h < player; h++){
        printf("__%s__\n\n", name[h]);
        for (int i = 0; i < indice; i++){
            for (int j = 0; j < indice; j++){
                printf("%3d", paper[h][i][j]);
            }
            printf("\n");
        }
        printf("\nwin_num_order = %d\n", winning_num);
    }
    printf("\n");
    /* print */
    printf("%d", called[winning_num]);
    for (int i = 0; i < index; i++)
        printf(" %s", name[winner[i]]);
}