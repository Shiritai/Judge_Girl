/* 50. Overlap Area */
# include <stdio.h>
# define abs(x) (x>=0)?x:-x
int main(void){
    int coo[4][2][2]; // [3+1 square][2 points][x, y]
    for (int i = 0; i < 3; i++)
        scanf("%d%d", &coo[i][0][0], &coo[i][0][1], &coo[i][1][1], &coo[i][1][1]);
    int area = 0, coo[3] = coo[0];
    printf("%d", coo[3][0][0]);
    int flag_x, flag_y;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            // flag_x = abs(coo[i][j][0] - coo[i+1][0][0]) + \
            //     abs(coo[i][j][0] - coo[i+1][1][0]) - \
            //     abs(coo[i+1][0][0] - coo[i+1][1][0]);
            // flag_y = abs(coo[i][j][1] - coo[i+1][0][1]) + \
            //     abs(coo[i][j][1] - coo[i+1][1][1]) - \
            //     abs(coo[i+1][0][1] - coo[i+1][1][1]);
            // if (flag_x == 0 && flag_y == 0){

            // }
        }
    }
    printf("%d", area);
}