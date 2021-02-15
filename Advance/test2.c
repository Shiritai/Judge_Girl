# include <stdio.h>
typedef struct {
    int x, y;
} Coo;
# define now [now.x][now.y]
int main(void){
    int net[10][10] = {0};
    net[5][5] = 1;
    Coo now = {5, 5}
    printf("%d\n", net[now]);
    return 0;
}