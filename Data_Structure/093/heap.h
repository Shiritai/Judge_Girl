#ifndef HEAP_H
#define HEAP_H
#define MAXHEAP 100
 
typedef struct Heap{
    int array[MAXHEAP];
    int num;
} Heap;
 
void initialize(Heap * heap);
int removeMin(Heap * heap);
void add(Heap * heap, int i);
int isFull(Heap * heap);
int isEmpty(Heap * heap);

#endif /* HEAP_H */