# include <stdio.h>
int main(){
    /* 0: number to be sort; 1: order of the input */
    int A[10][2] = {0};
    for (int i = 0; i < 10; i++){
        scanf("%d", &A[i][0]);
        A[i][1] += i; // mark the imput order
    }
    for (int j = 8; j >= 0; j--){ // sort range
        for (int k = 0; k <= j; k++){
            if (A[k][0] > A[k+1][0]){
                A[k][0] ^= A[k+1][0] ^= A[k][0] ^= A[k+1][0]; // bubble sort: change 1 by 1
                A[k][1] ^= A[k+1][1] ^= A[k][1] ^= A[k+1][1]; // record the order
            } // min to the LHS
        }
    }
    for (int i = 0; i < 10; i++){
        printf("%d  ", A[i][1]);
    }
}