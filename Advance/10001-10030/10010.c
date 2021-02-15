/* 10010. Conquering cities and towns */
# include <stdio.h>
# include <string.h>
# define Len 1024
int main(void){
    static int Eroiko[Len][Len] = {{0}};
    int M, N, Q, ax, ay, bx, by;
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 0; i <= N; ++i){
        for (int j = 0; j <= M; ++j)
            Eroiko[i][j] = 1;
    }
    while (Q > 0){
        scanf("%d %d %d %d", &ax, &ay, &bx, &by);
        int cnt = 0;
        for (int i = ax; i <= bx; ++i){
            for (int j = ay; j <= by; ++j)
                if (Eroiko[i][j] == 1){
                    ++cnt;
                }
        }
        printf("%d", cnt);
        for (int i = ax; i <= bx; ++i){
            for (int j = ay; j <= by; ++j)
                if (Eroiko[i][j] == 1){
                    printf(" (%d, %d)", i, j);
                    Eroiko[i][j] = 0;
                }
        }
        putchar('\n');
        --Q;
    }
    /* too slow */
    // while (Q > 0){
    //     scanf("%d %d %d %d", &ax, &ay, &bx, &by);
    //     static char out[Len*Len*6] = "", tmp[Len] = "";
    //     int cnt = 0;
    //     for (int i = ax; i <= bx; ++i){
    //         for (int j = ay; j <= by; ++j)
    //             if (Eroiko[i][j] == 1){
    //                 sprintf(tmp, " (%d, %d)", i, j);
    //                 strcat(out, tmp);
    //                 Eroiko[i][j] = 0;
    //                 ++cnt;
    //             }
    //     }
    //     printf("%d%s\n", cnt, out);
    //     strcpy(out, "");
    //     --Q;
    // }
    return 0;
}