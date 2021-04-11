/* 93. Heap */
// 實際上我寫的是最小堆
# include "heap.h"

void initialize(Heap * heap){
    heap->num = 0;
}

void shiftUp(Heap * heap, int index){
    int originVal = heap->array[index];
    for (int newInd = (index - 1) >> 1; index >= 1 && heap->array[newInd] > originVal; newInd = (newInd - 1) >> 1){
        heap->array[index] = heap->array[newInd];
        index = newInd;
    }
    heap->array[index] = originVal;
}

void shiftDown(Heap * heap, int index){
    int originVal = heap->array[index];
    for (int newInd = (index << 1) + 1; newInd < heap->num; newInd = (newInd << 1) + 1){
        if (newInd + 1 < heap->num && heap->array[newInd + 1] < heap->array[newInd])
            ++newInd;
        if (heap->array[newInd] > originVal)
            break;
        heap->array[index] = heap->array[newInd];
        index = newInd;
    }
    heap->array[index] = originVal;
}

int removeMin(Heap * heap){
    int res = heap->array[0];
    heap->array[0] = heap->array[--heap->num];
    shiftDown(heap, 0);
    return res;
}

void add(Heap * heap, int i){
    heap->array[heap->num++] = i;
    shiftUp(heap, heap->num - 1);
}

int isFull(Heap * heap){
    return MAXHEAP == heap->num;
}

int isEmpty(Heap * heap){
    return heap->num == 0;
}