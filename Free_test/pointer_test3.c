# include <stdio.h>
void ptr_Inc(int * p1, int * p2){
    * p1 += 1;
    p1 = p2;
    * p1 += 2;
}
int main(void){
    int a = 5, b = 7;
    int * a_ptr = &a;
    int * b_ptr = &b;
    ptr_Inc(a_ptr, b_ptr);
    printf("a = %d, b = %d", a, b);
}