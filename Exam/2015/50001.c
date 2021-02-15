/* 50001. Vehicle */
# include <stdio.h>
# include <stdbool.h>
# define abs(x) ((x>0)?x:-x)
# define north 0
# define east 1
# define south 2
# define west 3
static int footpoint[2][2] = {0}, ftCnt = 0;
// bool have_gold(int m, int n);
void move(int * X, int * Y, int dir);
int main(void){
    int a, b, c, d, e, x, y, F, p, q, r, s;
    scanf("%d%d%d%d%d\n%d%d%d%d\n%d%d%d", &a, &b, &c, &d, &e, &p, &q, &r, &s, &x, &y, &F);
    // have_gold(p, q), have_gold(r, s);
    int gold = (abs((c*x + d*y)) % e);
    while (F > 0){
        /* move */
        move(&x, &y, (abs((a*x + b*y)) % 4));
        /* transport */
        if (x == p && y == q)
            x = r, y = s;
        else if (x == r && y == s)
            x = p, y = q;
        /* end of move */
        /* collect gold */
        if (!((x == p && y == q) || (x == r && y == s)))
            gold += (abs((c*x + d*y)) % e);
        F--;
    }
    printf("%d\n%d %d", gold, x, y);
    return 0;
}
void move(int * X, int * Y, int dir){
    switch (dir){
    case north:
        (*Y)++;
        break;
    case east:
        (*X)++;
        break;
    case south:
        (*Y)--;
        break;
    case west:
        (*X)--;
        break;
    default:
        printf("Hell?\n");
        break;
    }
    return;
}
// bool have_gold(int m, int n){
//     int i;
//     bool flag = true;
//     for (i = 0; i < ftCnt && flag; i++){
//         if (m == footpoint[i][0] && n == footpoint[i][1])
//             flag = false;
//     }
//     footpoint[ftCnt][0] = m, footpoint[ftCnt][1] = n;
//     ftCnt++;
//     return flag;
// }