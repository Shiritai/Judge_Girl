# include <stdio.h>
int main(void){
    int coin_paper[7] = {0}, num;
    while (scanf("%d", &num) != EOF){
        coin_paper[0] = num / 1000;
        num %= 1000;
        coin_paper[1] = num / 500;
        num %= 500;
        coin_paper[2] = num / 100;
        num %= 100;
        coin_paper[3] = num / 50;
        num %= 50;
        coin_paper[4] = num / 10;
        num %= 10;
        coin_paper[5] = num / 5;
        num %= 5;
        coin_paper[6] = num / 1;
        num %= 1;
        for (int i = 0; i < 6; ++i)
            printf("%d ", coin_paper[i]);
        printf("%d\n", coin_paper[6]);
    }
    return 0;
}