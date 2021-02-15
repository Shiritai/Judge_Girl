/* 234. Factorization */
# include <stdio.h>
# define FACTOR_length 100000
int storage(int count, int matrix[][3], int data_matrix[][3]);
int main (){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int p_n = c;
    c = (c > 0) ? c : -c;
    int fac[FACTOR_length] = {0};
    /* by Vieta's formulas: c = -d*e*f, collect the possible int */
    /* !!!!!!!!!!!!!__Later I'll add the situation while c = 0__!!!!!!!!!!!!! */
    /* i.e. find the factor of c */
    int h = 0;
    for (int i = 1; i < (c+2)/2; i++){
        if (c % i == 0){
            fac[h] = i;
            h++;
        }
    }
    fac[h] = c;
    for (int i = 0; i < h+1; i++)
        printf("%4d", fac[i]);
    printf("\n\nEnd of test 1\n\n");
    /* output checked :) */
    /* find 3 num in fac s.t. their multiple = c */
    int pot[][6] = {{0, 0, 0, 0, 0, 0}};
    int length = 0;
    for (int i = 2; i < h+1; i++){
        for (int j = 1; j < i; j++){
            for (int k = 0; k < j; k++){
                if (fac[i] * fac[j] * fac[k] == c){
                    pot[length][0] = fac[k];
                    pot[length][1] = fac[j];
                    pot[length][2] = fac[i];
                    length++;
                }
            }
        }
    }
    for (int i = 0; i < length; i++){
        printf("%4d%4d%4d\n", pot[i][0], pot[i][1], pot[i][2]);
    }
    printf("\nEnd of test 2\n\n");
    /* output checked :) */
    /* be careful to both consider the positive and tne negative num after all */
    // /* no need!? */
    // /* expand value to the negative */
    // for (int i = 0; i < length; i++){
    //     pot[i][5] = pot[i][2], pot[i][4] = pot[i][1], pot[i][3] = pot[i][0];
    //     pot[i][2] ^= pot[i][0] ^= pot[i][2] ^= pot[i][0];
    //     pot[i][0] *= -1, pot[i][1] *= -1, pot[i][2] *= -1;
    // }
    // for (int i = 0; i < length; i++){
    //     printf("%4d%4d%4d%4d%4d%4d\n", pot[i][0], pot[i][1], pot[i][2], pot[i][3], pot[i][4], pot[i][5]);
    // }
    // printf("\nEnd of test 3\n\n");
    // /* output checked :) */
    int flag[length][4], store[length][3];
    int temp = 0;
    int l = 0;
    if (p_n > 0){ // 1 or 3 negative
        for (int i = 0; i < length; i++){
            temp = pot[i][0] + pot[i][1] + pot[i][2];
            if (a == -(temp - 2*pot[i][0]))
                (l, store[l]) = storage(l, store[l], pot[i]); // min is minus
            else if (a == -(temp - 2*pot[i][1]))
                flag[i][1] = 1; // middle is minus
            else if (a == -(temp - 2*pot[i][2]))
                flag[i][2] = 1; // max is minus
            else if (a == temp)
                // all are minus
            for (int j = 0, leave = 1; j < 3; j++){
                if (flag[i][j] == 1) // put 1 minus
                    pot[i][j] *= -1;
            }
        }

    }
    else if (p_n < 0){ // 0 ot 2 negative
        for (int i = 0; i < length; i++){
            temp = -(pot[i][0] + pot[i][1] + pot[i][2]);
            if (a == -(temp + 2*pot[i][0]))
                flag[i][0] = 1, temp = 0x7fffffff; // min is positive
            else if (a == -(temp + 2*pot[i][1]))
                flag[i][1] = 1, temp = 0x7fffffff; // middle is positive
            else if (a == -(temp + 2*pot[i][2]))
                flag[i][2] = 1, temp = 0x7fffffff; // max is positive
            else if (a == -temp)
                flag[i][3] = 1, temp = 0x7fffffff; // all are positive
            if (temp = 0x7fffffff){
                break;
            }
        }
        
    }


}
int storage(int count, int matrix[][3], int data_matrix[][3]){
    return (count+1, matrix[count][3])
}
        