/* 18. Larger than Neighbors */
# include <stdio.h>
# define row 102 // make the edge all 0
# define col 102
int main(void){
    int M[row][col] = {0};
    int R, C;
    scanf("%d%d", &R, &C);
    for (int i = 1; i < R+1; i++){
        for (int j = 1; j < C+1; j++)
            scanf("%d", &M[i][j]);
    }
    for (int i = 1; i < R+1; i++){
        for (int j = 1; j < C+1; j++){
            if (M[i][j] > M[i+1][j] && M[i][j] > M[i][j+1] && M[i][j] > M[i-1][j] && M[i][j] > M[i][j-1])
                printf("%d\n", M[i][j]);
        }
    }    
}