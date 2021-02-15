/* 269. Memory Allocation */
#ifndef MEMORY_H
#define MEMORY_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <assert.h>
typedef struct memory{
    int start;
    int length;
    bool status; // true : avaliable, false : using
    struct memory * next;
} Memory;
void freeMemory(Memory * memory, int start, int length);
void initMemory(Memory * memory, int length);
void printMemory(Memory * memory);
void allocateMemory(Memory * memory, int start, int length);
void freeAllMemory(Memory * memory);

# endif /* MEMORY_H */