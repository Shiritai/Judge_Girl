/* 9. Score of an Integer */
# include <stdio.h>
int main(){
    int x;
    int counter = 0;
    scanf("%d", &x);
    /* > = < 0 */
    if (x <= 0)
        counter -= 100;
    else{
        /* multiple of 3 */
        if (x % 3 == 0)
            counter += 3;
        /* multiole of 5 */
        if (x % 5 == 0)
            counter += 5;
        /* 100~200 */
        if (100 <= x && x <= 200)
            counter += 50;
        else
            counter -= 50;
    }
    printf("%d", counter);
}