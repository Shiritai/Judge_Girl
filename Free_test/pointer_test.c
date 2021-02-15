# include <stdio.h>
int main (void){
    int a = 1, b = 2;
    double d = 0.0;
    int * a_ptr = &a;
    * a_ptr = b;
    a = * a_ptr;
    float * f_ptr = NULL;
    double * d_ptr = &d;
    printf("%d\n", a);
    printf("int pointer size: %d\n", sizeof(a_ptr));
    printf("float pointer size: %d\n", sizeof(f_ptr));
    printf("double pointer size: %d\n", sizeof(d_ptr));
    printf("\n*(&(a_ptr)) = %p\n", *(&(a_ptr)));
    printf("&(*(a_ptr)) = %p\n", &(*(a_ptr)));
    // printf("NULL = %d", *f_ptr); // nothing will print
}