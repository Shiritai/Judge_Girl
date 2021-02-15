/* 195. Tic-Tac-Toe */
# include <stdio.h>
int main(void){
    int n;
    scanf("%d", &n);
    int board[3][3] = {0};
    int temp_x, temp_y;
    int result = 0;
    while (n > 0){
        /* FIRST person */
        scanf("%d%d", &temp_x, &temp_y);
        board[temp_x][temp_y] = (board[temp_x][temp_y] == 0) ? 4:board[temp_x][temp_y];
        /* check whether Black wins or not */
        for (int i = 0; i < 3; i++){
            /* horizontal */
            if (board[i][0] + board[i][1] + board[i][2] == 12)
                result = (result == 0) ? 1:result;
            /* vertical */
            if (board[0][i] + board[1][i] + board[2][i] == 12)
                result = (result == 0) ? 1:result;
        }
        /* cross */
        if (board[1][1] == 4){
            if (board[0][0] + board[1][1] + board[2][2] == 12)
                result = (result == 0) ? 1:result;
            if (board[0][2] + board[1][1] + board[2][0] == 12)
                result = (result == 0) ? 1:result;
        }
        n--;
        if (n == 0)
            break;
        /* SECOND person */
        scanf("%d%d", &temp_x, &temp_y);
        board[temp_x][temp_y] = (board[temp_x][temp_y] == 0) ? 1:board[temp_x][temp_y];
        /* check whether white wins or not */
        for (int i = 0; i < 3; i++){
            if (board[i][0] + board[i][1] + board[i][2] == 3)
                result = (result == 0) ? 2:result;
            if (board[0][i] + board[1][i] + board[2][i] == 3)
                result = (result == 0) ? 2:result;
        }
        if (board[1][1] == 1){
            if (board[0][0] + board[1][1] + board[2][2] == 3)
                result = (result == 0) ? 2:result;
            if (board[0][2] + board[1][1] + board[2][0] == 3)
                result = (result == 0) ? 2:result;
        }
        n--;
    }
    switch (result){
    case 1:
        printf("Black wins.");
        break;
    case 2:
        printf("White wins.");
        break;
    case 0:
        printf("There is a draw.");
        break;
    default:
        printf("Meow?");
        break;
    }
    printf("\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            printf("%2d", board[i][j]);
        printf("\n");
    }
}