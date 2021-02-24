/* 50078. Parallelogram */
# include <stdio.h>
int main(void){
    int ax, ay, bx, by, cx, cy;
    scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
    printf("%d\n%d\n%d\n%d\n%d\n%d\n", bx + (cx - ax), by + (cy - ay), ax + (cx - bx), ay + (cy - by), ax + (bx - cx), ay + (by - cy));
}