/* 208. Print a Bitmap */
/* unknown problem */
# include <stdio.h>
# include <stdbool.h>
# define uintS 1024
# define BitLen 32
int main(void){
    unsigned int U[uintS] = {0}, mask = 0x80000000;
    int wid, hei, i, j;
    char one, zero, peek[4] = "";
    scanf("%d%d\n", &wid, &hei); // notice '\n'
    fgets(peek, sizeof(peek) / sizeof(char), stdin);
    one = peek[0], zero = peek[2];
    int cnt = wid * hei, range = cnt / 36 + ((range % BitLen == 0) ? 0 : 1);
    for (i = 0; i < range; i++)
        scanf("%u", &U[i]);
    bool tmp = false;
    for (i = 0; i < range; i++){
        for (j = 0; j < BitLen && cnt > 0; j++, U[i] <<= 1, cnt--){
            tmp = U[i] & mask;
            printf("%c", (tmp) ? one : zero);
            if ((j+1) % wid == 0 && cnt != 1)
                printf("\n");
        }
    }
    return 0;
}