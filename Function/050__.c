/* 50. Overlap Area */
# include <stdio.h>
# define area(ax, ay, bx, by) ((bx - ax) * (by - ay))
int rect[3][4][2], ind[2][2];
// int comp(int ax, int ay, int bx, int by){
//     if (bx > ax && )
// }
int ovArea(int a, int b){
    if (rect[a][0][0] > rect[b][0][0] && rect[a][0][1] > rect[b][0][1] && rect[a][0][0] < rect[b][1][0] && rect[a][0][1] > rect[b][1][1])
        return area(rect[a][0][0],  rect[a][0][1], rect[b][1][0], rect[b][1][1]);
    else if (rect[b][0][0] > rect[a][0][0] && rect[b][0][1] > rect[a][0][1] && rect[b][0][0] < rect[a][1][0] && rect[b][0][1] > rect[a][1][1])
        return area(rect[b][0][0],  rect[b][0][1], rect[a][1][0], rect[a][1][1]);
    else if (rect[b][0][0] > rect[a][0][0] && rect[b][0][1] > rect[a][0][1] && rect[b][0][0] < rect[a][1][0] && rect[b][0][1] > rect[a][1][1])
        return area(rect[b][0][0],  rect[b][0][1], rect[a][1][0], rect[a][1][1]);
    
}
int main(void){
    int sum = 0;
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 2; ++j){
            for (int k = 0; k < 2; ++k)
                scanf("%d", &rect[i][j][k]);
        }
        rect[i][3][0] = rect[i][2][0], rect[i][3][1] = rect[i][1][1];
        rect[i][4][0] = rect[i][1][0], rect[i][4][1] = rect[i][2][1];
    }
    for (int i = 0; i < 3; ++i)
        sum += area(rect[i][0][0], rect[i][0][1], rect[i][1][0], rect[i][1][1]);
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3 - i; ++j){
            sum += ovArea(i, j);
        }
    }
    printf("%d\n", area(1, 2, 1, 2));
}