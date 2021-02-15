# include <stdio.h>
# define Whole 8
main(){
    int i, j = 1;
    for (i = 1; i <= Whole; i++)    j *= i;
    printf("%d\n", j);
    short short_test = 0x8000;
    printf("%hd", short_test);
}