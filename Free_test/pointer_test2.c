# include <stdio.h>
# define X 4
# define Y 4
# define Z 4
int main(void){
    int a[X][Y][Z];
    int * arr_ptr = &a;
    int * arr_X_ptr = &a[1];
    int * arr_Y_ptr = &a[0][1];
    int * arr_Z_ptr = &a[0][0][1];
    printf("arr_ptr   = %p\narr_X_ptr = %p\narr_Y_ptr = %p\narr_Z_ptr = %p\n",\
        arr_ptr, arr_X_ptr, arr_Y_ptr, arr_Z_ptr);
}