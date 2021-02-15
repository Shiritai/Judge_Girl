/* 10029. Where is My Life */ // Gauss Matrix
# include <stdio.h>
# define Len 100
int main(void){
    int N, M;
    while (scanf("%d%d", &N, &M) != EOF){
        int board[Len+1][Len+1] = {{0}};
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M+1; ++j)
                scanf("%d", &board[i][j]);
        }
        int toaru[M] = {0};
        for (int i = 0; i < M; ++i)
            scanf("%d", &toaru[i]);
        /* Gauss Method */
        int line = 0;
        for (int i = 0; i < M; ++i){
            if (board[line][i] != 0){
                int tmp[Len+1] = {0};
                for (int j = i; j < M+1; ++j)
                    tmp[j] = board[line][j];
                for (int ato = 0; ato < N-line; ++ato){
                    if (board[line+ato][i] != 0){
                        int mul_tmp = board[line+ato][i], mul_board = tmp[i];
                        for (int k = i; k < M+1; ++k){
                            board[line+ato][k] = board[line+ato][k] * mul_board - tmp[k] * mul_tmp;
                        }
                    }
                }
                ++line;
            }
        }
    }

}
