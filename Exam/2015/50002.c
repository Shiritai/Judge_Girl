/* 50002. Game of Life */
# include <stdio.h>
# define N 100
# define DEBUG 0
int main (void){
    /* input */
    int k, n, A[3][N][N] = {{0}}; // 0/1: swap, 2: stay alive time
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &A[0][i][j]);
            A[2][i][j] = A[0][i][j];
        }
    }
    int curr = 0, target = 0, nei;
    while (k > 0){
        target = (curr == 0) ? 1 : 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                /* init, check neighbors */
                nei = 0;
                for (int xNei = -1; xNei <= 1; xNei++){
                    for (int yNei = -1; yNei <= 1; yNei++){
                        int x = i + xNei, y = j + yNei;
                        if (x >= 0 && x < n && y >= 0 && y < n \
                            && A[curr][x][y] == 1 && !(xNei == 0 && yNei == 0))
                            nei++;
                    }
                }
                switch (nei){
                    case 3:
                        A[target][i][j] = 1;
                        A[2][i][j] += 1;
                        break;
                    case 2: // nothing need to change
                        A[target][i][j] = (A[curr][i][j] == 1) ? 1 : 0;
                        A[2][i][j] = (A[curr][i][j] == 1) ? A[2][i][j] + 1 : A[2][i][j];
                        break;
                    default: // died situation
                        A[target][i][j] = 0;
                        break;
                }
            }
        }
        /* init */
        curr = target;
        k--;
# if DEBUG == 1
        /* print */
        printf("\n");
        int topRec[3] = {0};
        for (int i = 0; i < n; i++){
            if (topRec[2] <= A[2][i][0])
                topRec[0] = i, topRec[1] = 0, topRec[2] = A[2][i][0];
            printf("%d", A[target][i][0]);
            for (int j = 1; j < n; j++){
                if (topRec[2] <= A[2][i][j])
                    topRec[0] = i, topRec[1] = j, topRec[2] = A[2][i][j];
                printf(" %d", A[target][i][j]);
            }
            printf("\n");
        }
        printf("(%d,%d) = %d\n", topRec[0]+1, topRec[1]+1, topRec[2]);
# endif
    }
# if DEBUG == 0
    /* print */
    int topRec[3] = {0};
    for (int i = 0; i < n; i++){
        if (topRec[2] <= A[2][i][0])
            topRec[0] = i, topRec[1] = 0, topRec[2] = A[2][i][0];
        printf("%d", A[target][i][0]);
        for (int j = 1; j < n; j++){
            if (topRec[2] <= A[2][i][j])
                topRec[0] = i, topRec[1] = j, topRec[2] = A[2][i][j];
            printf(" %d", A[target][i][j]);
        }
        printf("\n");
    }
    printf("%d %d", topRec[0]+1, topRec[1]+1);
# endif
}