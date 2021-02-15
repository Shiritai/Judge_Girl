# include <stdio.h>
# define size 128
int main(void){
    int a[size] = {0};
    int * a_ptr = &a;
    printf("a_ptr     = %p\n", a_ptr);
    * (a_ptr + 1) += 1;
    a_ptr[1]++;
    printf("a[1] = %d\n", a[1]);
    // for (int i = 0; i < 8; i++)
    //     printf("a[%d] = %d\n", i, a[i]);
    a_ptr += 5;
    printf("a_ptr + 3 = %p\n", a_ptr);
}