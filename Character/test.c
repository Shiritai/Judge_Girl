#include <stdio.h>
int main(){ // this computer treat "char" as signed char
    char a = -1;
    signed char b = -1;
    unsigned char c = -1;
    printf("a = %d,b = %d,c = %d\n", a, b, c);
    return 0;
}