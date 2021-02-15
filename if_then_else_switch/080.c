/* 80. Triangle */
# include <stdio.h>
# include <stdlib.h>
int switch_read_printer(int x){
    switch (x){
    case 0:
        printf("isosceles\n");
        break;
    case 1:
        printf("acute\n");
        break;
    case 2:
        printf("obtuse\n");
        break;
    case 3:
        printf("right\n");
        break;
    default:
        break;
    }
}
int main(){
    int counter;
    int save_data[100] = {0};
    scanf("%d", &counter);
    /* read coordination */
    for (int i = 0; i < counter; i++){
        int a, b, c, d, e, f;
        scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
        int sq_A = (c-a)*(c-a) + (d-b)*(d-b);
        int sq_B = (e-a)*(e-a) + (f-b)*(f-b);
        int sq_C = (c-e)*(c-e) + (d-f)*(d-f);
        /* sort and distinguish isosceles */
        /* isosceles */
        if (sq_A == sq_B || sq_A == sq_C || sq_B == sq_C){
            save_data[i] = 0;
        }
        /* sort, make sq_A > sq_B && sq_A > sq_C */
        else if (sq_B > sq_A){
            sq_A ^= sq_B ^= sq_A ^= sq_B;
            if (sq_C > sq_A){
                sq_A ^= sq_C ^= sq_A ^= sq_C;
            }   
        }
        else if (sq_A > sq_B){
            if (sq_C > sq_A)
                sq_C ^= sq_A ^= sq_C ^= sq_A;
        }
        /* mark acute, obtuse or right triangle */
        if (sq_A != sq_B && sq_A != sq_C && sq_B != sq_C){
            if (sq_A - sq_B - sq_C < 0)
                save_data[i] = 1;
            else if (sq_A - sq_B - sq_C > 0)
                save_data[i] = 2;
            else
                save_data[i] = 3;
        }
    }
    /* print type of triangle */
    for (int i = 0; i < counter; i++)
        switch_read_printer(save_data[i]);
}