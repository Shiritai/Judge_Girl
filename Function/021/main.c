/* 21. Maximum in Matrix */
# include <stdio.h>
#include "max.h"
int main(void){
    int i, j; 
    int array[5][5];
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++)
              scanf("%d", &(array[i][j]));
    }
    printf("%d\n", max(array));
    return 0;
}
