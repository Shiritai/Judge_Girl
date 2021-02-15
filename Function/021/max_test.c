/* 21. Maximum in Matrix */
#include "max.h"
int max(int array[5][5]) {
    int * maxPtr = &array, i, j;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++)
            maxPtr = (* maxPtr < array[i][j]) ? &(array[i][j]) : maxPtr;
    }
    int a = *maxPtr;
    return a;
}