# include <stdio.h>
# include <stdbool.h>
# define BitLen 32
int main(void){
    unsigned int a, mask = 0x80000000;
    int i;
    bool tmp = false;
    while (scanf("%u", &a)){
        for (i = 0; i < BitLen; i++, a <<= 1){
            tmp = a & mask;
            printf("%d", tmp);
        }
        printf("\n");
    }
    return 0;
}