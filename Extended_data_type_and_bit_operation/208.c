/* 208. Print a Bitmap */
# include <stdio.h>
int main(void){
    char dic[2];
    int width, line, num, len;
    unsigned int input[1024];
    scanf("%d%d\n%c %c", &width, &line, &dic[1], &dic[0]);
    len = width * line;
    for (num = 0; num < len / 32 + ((len % 32) ? 1 : 0); ++num)
        scanf("%u", &input[num]);
    for (int i = 0, ind = 0; i < len; ++i){
        printf("%c", dic[(int) ((input[ind] & 0x80000000u) >> 31)]);
        if (!((i + 1) % width))    printf("\n");
        input[ind] <<= 1;
        if (!((i + 1) % 32))    ++ind;
    }
    return 0;
}