# include <stdio.h>
int main(void){
    printf("%x\n", ~((~0) << 4));
    printf("%x\n", (~0) >> 4);
}