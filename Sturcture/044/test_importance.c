# include <stdio.h>
typedef unsigned int UI;
UI importance_cnt(UI tmp){
    while (!(tmp & 1))
        tmp >>= 1;
    UI i = 0;
    tmp >>= 1;
    while (!(tmp & 1)){
        tmp >>= 1;
        ++i;
    }
    return i;
}
int main(void){
    UI tmp;
    while (scanf("%x", &tmp) == 1)
        printf("%u\n", importance_cnt(tmp));
}