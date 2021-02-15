/* 88. AB Numbers */
# include <stdio.h>
int real_power(int a, int b);
int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    int AB[2] = {0};
    int save_dig[2][4] = {0};
    /* fetch digit */
    for (int i = 3; i > -1; i--){
        int del_dig = real_power(10, i);
        printf("%4d\t", del_dig);
        // printf("del_dig = %d\n", del_dig);
        save_dig[0][i] = x/del_dig, save_dig[1][i] = y/del_dig;
        x -= del_dig * (x/del_dig), y -= del_dig * (y/del_dig);
        printf("%4d || %4d\t", x, y);
        printf("%d || %d\n", save_dig[0][i], save_dig[1][i]);
    }
    
    for (int i = 3; i > -1; i--){
        /* count A */
        if (save_dig[0][i] == save_dig[1][i])
            AB[0]++;
        /* count B */    
        for (int j = 3; j > -1; j--){
            if (i != j && save_dig[0][i] == save_dig[1][j])
                AB[1]++;
        }
    }
    printf("%dA%dB", AB[0], AB[1]);
}
int real_power(int a, int b){
    int x = 1;
    for (int i = 0; i < b; i++)
        x *= a;
    return x;
}