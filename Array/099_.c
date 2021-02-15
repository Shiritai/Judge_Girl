/* 99. Bingo */
# include <stdio.h>
# define max_player 10
# define link_type 4 // horiz, vert, left_diagnose, right_diagnose
int main(void){
    int player, indice;
    scanf("%d%d", &player, &indice);
    /* variables in bingle */
    char name[max_player][64] = {'0'};
    /* to declare a big matrix in a function,
        add 'static' to represent the variable that will stay in MEM until the end of the program */
    static int paper[max_player][256][256] = {0}; // player, vert., horiz.
    int called[65536] = {0};
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
    static int check[max_player][link_type] = {0};
    int vert_horiz_check[max_player][2] = {0}; // 0: vert.; 1: horiz.
    int flag = 0;
    char winner[max_player] = {0};
    int temp = 0, crt_num = 0;
    for(int g = 0; g < nums; g++){ // called number order
        /* call a number for everybody within a loop */
        /* determine whether sb wins before the next loop */
        for (int h = 0; h < player; h++){ // player order
            for (int i = 0; i < indice; i++){ // vert.
                for (int j = 0; j < indice; j++){ // horiz.
                    if (called[g] == paper[h][i][j]) // match
                        paper[h][i][j] = -1; // let -1 to be the mark
                }
            }
            /* vertical and horizontal */
            for (int i = 0; i < indice; i++){
                for (int j = 0; j < indice-1; j++){
                    vert_horiz_check[h][2] += paper[h][i][j];
                }    
            }
            /* left diagnose */
            for (int i = 0; i < indice-1; i++){
                check[h][2] += paper[h][i][i+1];
            }
            /* right diagnose */
            for (int i = 0; i < indice-1; i++){
                check[h][3] += paper[h][indice-i-1][i]; 
            }
            /* Matome */
            for (int l = 0; l < )
                if (vert_horiz_check[0] == 1 || vert_horiz_check[1] == 1)
                    check[h] = 1;
            if (check[h][2] = -indice || check[h][3] = -indice){
                winner[temp] = h;
                temp++;
                flag = 1, crt_num = called[g];
            }
            check[h] = 0;
        }
        if (flag == 1)
            break;
    }
    /* print */
    printf("%d", crt_num);
    for (int i = 0; i < temp; i++)
        printf(" %s", name[winner[i]]);
    /* output test */
    printf("\n\n");
    for (int h = 0; h < player; h++){
        printf("%s\n", name[h]);
        for (int i = 0; i < indice; i++){
            for (int j = 0; j < indice; j++){
                printf("%3d", paper[h][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}