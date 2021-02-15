/* 281. Number of 1s */
# include <stdio.h>
# define BitLen 64
# define Type long long
int main(void){
    Type a, mask = 1;
    int i, oneNum = 0;
# if BitLen == 32
    while (scanf("%d", &a) != EOF)
# endif
# if BitLen == 64
    while (scanf("%lld", &a) != EOF)
# endif
    {
        for (i = 0; i < BitLen; i++){
            oneNum += a & mask;
            a >>= 1;
        }
        printf("%d\n", oneNum);
        oneNum = 0;
    }
    return 0;
}