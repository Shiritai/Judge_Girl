/* 50114. Simple Polygon */
# include <stdio.h>
int main(void){
    int ax, ay, bx, by, cx, cy, dx, dy;
    scanf("%d%d%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
    printf("%d\n%d\n", 2 * (cx - ax + cy - ay), (cx - ax) * (cy - ay) - (dx - ax) * (cy - dy) - (cx - bx) * (by - ay));
}