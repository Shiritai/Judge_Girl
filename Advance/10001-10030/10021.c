/* 10021. Walking on the Safe Side */
# include <stdio.h>
# define Len 100
int compute(int [][Len], int, int);
int main(void){
    int ROW, COL, tmp;
    while (scanf("%d%d", &COL, &ROW) != EOF){
        int net[Len][Len] = {{0}};
        for (int i = 0; i < COL; ++i){
            for (int j = 0; j < ROW; ++j){
                scanf("%d", &tmp);
                if (tmp != 0)
                    net[i][j] = -1;
                else 
                    net[i][j] = 0;
            }
        }
        printf("%d\n", compute(net, COL, ROW) % 10000);
    }
    return 0;
}
int compute(int plate[][Len], int col, int row){
    int x = 0, y = 0;
    plate[0][0] = 1;
    while (!(x == row-1 && y == col-1)){
        if (x < row-1){
            if (plate[y][x] >= 1){
                if (plate[y][x+1] >= 0)
                    plate[y][x+1] += plate[y][x];
                if (plate[y+1][x] >= 0)
                    plate[y+1][x] += plate[y][x];
                plate[y][x+1] %= 10000; // be aware of overflow
                plate[y+1][x] %= 10000; // be aware of overflow
            }
            ++x;
        }
        else {
            if (plate[y+1][x] >= 0 && plate[y][x] >= 1){
                plate[y+1][x] += plate[y][x];
                plate[y+1][x] %= 10000; // be aware of overflow
            }
            x = 0, ++y;
        }
    }
    return plate[col-1][row-1];
}