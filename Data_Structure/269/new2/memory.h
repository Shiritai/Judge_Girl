/* 269. Memory Allocation */
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <assert.h>

typedef struct memory{
    int start;
    int length;
    struct memory * next;
} Memory;

void freeMemory(Memory *, int, int);
void initMemory(Memory *, int);
void printMemory(Memory *);
void allocateMemory(Memory *, int, int);