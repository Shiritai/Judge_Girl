/* 104. Material Composition */
# include <stdio.h>
# include <stdbool.h>
static int inputNum, da, db, dc, ea, eb, ec, fa, fb, fc;
bool test(int, int, int); // input needed: remained A, B, C
void proc(int remain);
int main(void){
    int i, j;
    /* input */
    scanf("%d%d%d%d%d%d%d%d%d%d", &da, &db, &dc, &ea, &eb, &ec, &fa, &fb, &fc, &inputNum);  
    proc(inputNum);
    return 0;
}
void proc(int remain){
    /* terminate */
    if (!remain)
        return;
    /* recur */
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (test(a, b, c))
        printf("yes\n");
    else
        printf("no\n");
    proc(remain-1);
}
bool test(int A, int B, int C){
    /* terminate */
    if (A == 0 && B == 0 && C == 0)
        return true;
    else if (A < 0 || B < 0 || C < 0)
        return false;
    /* recur */
    return test(A-da, B-db, C-dc) || test(A-ea, B-eb, C-ec) ||test(A-fa, B-fb, C-fc);
}