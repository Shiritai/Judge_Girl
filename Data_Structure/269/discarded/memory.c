/* 269. Memory Allocation */
# include "memory.h"
void initMemory(Memory * memory, int length){
    assert(length > 0);
    memory = (Memory *) malloc(sizeof(Memory));
    assert(memory);
    memory->start = 0, memory->length = length;
    memory->next = NULL;
    return;
}
void printMemory(Memory * memory){
    assert(memory != NULL);
    puts("==========");
    while (memory != NULL){
        if (memory->status)
            printf("start %d, length %d\n", memory->start, memory->length);
        memory = memory->next;
    }
    return;
}
void allocateMemory(Memory * memory, int start, int length){
    while(memory->next != NULL && memory->start < start){
        memory = memory->next;
    } // traverse
    int diff = memory->start + memory->length - (start + length);
    if (memory->status && diff >= 0){
        Memory newMem = (Memory *) malloc(sizeof(Memory));
        assert(newMem);
        /* adjust newMem */
        newMem->start = start;
        newMem->length = length;
        newMem->status = false;
        newMem->next = memory->next;
        /* adjust current Mem */
        memory->length = start - memory->start;
        memory->next = newMem;
        /* add remainder block */
        if (diff > 0){
            Memory remMem = (Memory *) malloc(sizeof(Memory));
            assert(reMem);
            remMem->start = start + length;
            remMem->length = diff;
            reMem->status = true;
            reMem->next = newMem->next;
            newMem->next = reMem;
        }
    }
    else
        printf("Error allocation\n");
    return;
}
void freeMemory(Memory * memory, int start, int length){
    /* traverse former nodes */
    while (memory->next != NULL && memory->start + memory->length < start){
        memory = memory->next;
    }
    /* build free block with adjust front stuffs */
    freeMem = (Memory *) malloc(sizeof(Memory));
    memory->next = freeMem;
    memory->length = start - memory->start;
    freeMem->status = true;
    /* kill covered blocked */
    Memory * tmp;
    while(memory != NULL && memory->start + memory->length < start + length){
        tmp = memory;
        memory = memory-> next;
        free(tmp);
    }
    /* adjust back stuff */
    freeMem->next = memory;
    memory->length -= (start + length - memory->start);
    memory->start = start + length;
    /* merge free blocks */
    if (memory != NULL && memory->status){
        freeMem->next = memory->next;
        freeMem->length += memory->length;
        free(memory);
    }
    return;
}
void freeAllMemory(Memory * memory){
    Memory * tmp;
    while (memory != NULL){
        tmp = memory;
        memory = memory->next;
        free(tmp);
    }
    return;
}