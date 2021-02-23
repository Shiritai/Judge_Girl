# include <stdio.h>
int main(void){
    int a = 0, b = 20, c = 30;
    if (c > b > a)
        puts("true");
    else 
        puts("false");
    getchar();
    return 0;
}