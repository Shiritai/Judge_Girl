# include <stdio.h>
int main(void){
    int a[16][16];
    int (* matrix_ptr) [10][10] = &(a[0][1]);
    int (* ma_ptr) [16] = &a[1];
    printf("a\t   = %p\n", &a);
    printf("matrix_ptr = %p\n", matrix_ptr);
    printf("ma_ptr\t   = %p\n", ma_ptr);
}