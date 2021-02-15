/* 265. Minimum Containing Box */
# include <stdio.h>
# define abs(x) (x>0)?x:-x 
int main(void){
    int some_coo[2];
    int rect[2][2] = {{0x7fffffff, 0x7fffffff}, {0xffffffff, 0xffffffff}};
    while (scanf("%d%d", &some_coo[0], &some_coo[1]) == 2){
        rect[0][0] = (some_coo[0] < rect[0][0]) ? some_coo[0] : rect[0][0]; // min x
        rect[0][1] = (some_coo[1] < rect[0][1]) ? some_coo[1] : rect[0][1]; // min y
        rect[1][0] = (some_coo[0] > rect[1][0]) ? some_coo[0] : rect[1][0]; // max x
        rect[1][1] = (some_coo[1] > rect[1][1]) ? some_coo[1] : rect[1][1]; // max y
    }
    printf("%d", abs((rect[0][0] - rect[1][0]) * (rect[0][1] - rect[1][1])));
}