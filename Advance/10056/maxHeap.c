# include <stdio.h>
# include <assert.h>
# include <stdlib.h>

int * data;
int len, capacity;
int * index, * moto,

void init(int capacity){
    data = (int *) malloc(sizeof(int) * capacity);
}