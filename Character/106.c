/* 106. Divisible */
# include <stdio.h>
int main(void){
    char num[1000];
    int cnt, i, j, k, N = 0;
    static int check[100000][4] = {0};
    scanf("%s", &num);
    while (num[0] != '-'){
        int tmp[2] = {0}; // check:: 0:2's, 1:3's, 2:5's, 3:11's; tmp:: 0:even, 1:odd
        for (cnt = 0; num[cnt] != '\0'; cnt++);
        /* count odd and even digit */
        for (i = cnt-1; i >= 0; i -= 2)
            tmp[0] += num[i] - '0';
        for (i = cnt-2; i >= 0; i -= 2)
            tmp[1] += num[i] - '0';
        /* determine yes or no */
        if (!(num[cnt-1] % 2))
            check[N][0]++;
        if (!((tmp[0] + tmp[1]) % 3))
            check[N][1]++;
        if (num[cnt-1] == '5' || num[cnt-1] == '0')
            check[N][2]++;
        if (!((tmp[0] - tmp[1]) % 11))
            check[N][3]++;
        scanf("%s", &num);
        N++;
    }
    /* print */
    for (i = 0; i < N; i++){
        if (check[i][0] == 0)
            printf("no ");
        else
            printf("yes ");
        if (check[i][1] == 0)
            printf("no ");
        else
            printf("yes ");
        if (check[i][2] == 0)
            printf("no ");
        else
            printf("yes ");
        if (check[i][3] == 0)
            printf("no\n");
        else
            printf("yes\n");
    }

}