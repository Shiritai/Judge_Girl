/* 103. Triangular Matrix Solver */
# include <stdio.h>
# define size 16
int main(void){
    double A[size][size], x[size] = {0}, y[size];
    int n;
    scanf("%d", &n);
    for (int h = 0; h < n; h++)
        for (int i = 0; i < n; i++)
            scanf("%lf", &A[h][i]);
    for (int i = 0; i < n; i++)
        scanf("%lf", &y[i]);
    /* initial data */
    x[n-1] = y[n-1] / A[n-1][n-1];
    /* solve one by one */
    double tmp; // BE CARE OF the right type of variables
    for (int i = n-2; i >= 0; i--){ // BE CARE OF >, >=, < <=, ++, --
        tmp = 0.0; // 
        for (int j = 1; j <= n-i-1; j++)
            tmp += A[i][i+j] * x[i+j];
        x[i] = (y[i] - tmp)/A[i][i];
    }
    /* print result */
    for (int i = 0; i < n; i++)
        printf("%f\n", x[i]);
} // quite concisely this program