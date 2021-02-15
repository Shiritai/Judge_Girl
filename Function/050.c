/* 50. Overlap Area */
# include <stdio.h>
# define NUM 3
typedef struct {
    int x_l, x_h, y_l, y_h; // low, high
} square;
int area(square a){
    return (a.x_h - a.x_l) * (a.y_h - a.y_l);
}
square overlap(square a, square b){
    if (a.x_l > b.x_h || a.x_h < b.x_l || a.y_l > b.y_h || a.y_h < b.y_l)
        return (square) {0, 0, 0, 0};
    square tmp;
    tmp.x_l = (a.x_l > b.x_l) ? a.x_l : b.x_l;
    tmp.x_h = (a.x_h < b.x_h) ? a.x_h : b.x_h;
    tmp.y_l = (a.y_l > b.y_l) ? a.y_l : b.y_l;
    tmp.y_h = (a.y_h < b.y_h) ? a.y_h : b.y_h;
    return tmp;
}
int main(void){
    square sq[NUM];
    int tmp_x, tmp_y;
    for (int i = 0; i < NUM; ++i){
        scanf("%d%d", &tmp_x, &tmp_y);
        sq[i].x_l = tmp_x, sq[i].y_l = tmp_y;
        scanf("%d%d", &tmp_x, &tmp_y);
        sq[i].x_h = tmp_x, sq[i].y_h = tmp_y;
    }
    int sum = 0;
    for (int i = 0; i < NUM; ++i){
        sum += area(sq[i]);
        for (int j = i + 1; j < NUM; ++j){
            sum -= area(overlap(sq[i], sq[j]));
        }
    }
    sum += area(overlap(overlap(sq[0], sq[1]), sq[2]));
    printf("%d\n", sum);
}