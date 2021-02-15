/* 269. Memory Allocation */
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

int main() {
    int i = 0;
    Memory myMemory;
    initMemory(&myMemory, 100);
    printf("Test %d\n", i), i++;
    printMemory(&myMemory);
    printf("Test %d\n", i), i++;
    allocateMemory(&myMemory, 50, 10);
    printf("Test %d\n", i), i++;
    printMemory(&myMemory);
    printf("Test %d\n", i), i++;
    allocateMemory(&myMemory, 70, 10);
    printf("Test %d\n", i), i++;
    printMemory(&myMemory);
    printf("Test %d\n", i), i++;
    allocateMemory(&myMemory, 0, 10);
    printf("Test %d\n", i), i++;
    printMemory(&myMemory);
    printf("Test %d\n", i), i++;
    allocateMemory(&myMemory, 30, 10);
    printf("Test %d\n", i), i++;
    printMemory(&myMemory);
    printf("Test %d\n", i), i++;
    freeMemory(&myMemory, 50, 5); // bug
    printf("Test %d\n", i), i++;
    printMemory(&myMemory);
    printf("Test %d\n", i), i++;
    freeMemory(&myMemory, 70, 10);
    printf("Test %d\n", i), i++;
    printMemory(&myMemory);
    printf("Test %d\n", i), i++;
    freeMemory(&myMemory, 30, 10);
    printf("Test %d\n", i), i++;
    printMemory(&myMemory);
    printf("Test %d\n", i), i++;
    freeMemory(&myMemory, 0, 10);
    printf("Test %d\n", i), i++;
    printMemory(&myMemory);
    printf("Test %d\n", i), i++;
    freeAllMemory(&myMemory);
    printf("Test %d\n", i), i++;
    return 0;
}

void initMemory(Memory * memory, int length){
    assert(length > 0);
    if (memory == NULL){
        memory = (Memory *) malloc(sizeof(Memory));
        assert(memory);
    }
    memory->start = 0, memory->length = length;
    memory->status = true;
    memory->next = NULL;
    return;
}

void printMemory(Memory * memory){
    puts("==========");
    while (memory != NULL){
        if (memory->status){
            printf("start %d, length %d\n", memory->start, memory->length);
            printf("adr = %p\n", memory);
        }
        memory = memory->next;
    }
    return;
}

void allocateMemory(Memory * memory, int start, int length){
    while(memory->next != NULL && memory->start < start){
        memory = memory->next;
    } // traverse
    int diff = memory->start + memory->length - (start + length);
    if (memory->status && memory->start == start){ // same start point
        /* adjust current Mem */
        memory->length = length;
        memory->status = false;
        /* add remainder block */
        if (diff > 0){
            Memory * remMem = (Memory *) malloc(sizeof(Memory));
            assert(remMem);
            remMem->start = start + length;
            remMem->length = diff;
            remMem->status = true;
            remMem->next = memory->next;
            memory->next = remMem;
        }
    }
    else if (memory->status && diff > 0){
        /* assign newMem */
        Memory * newMem = (Memory *) malloc(sizeof(Memory));
        assert(newMem);
        newMem->start = start;
        newMem->length = length;
        newMem->status = false;
        newMem->next = memory->next;
        /* adjust current Mem */
        memory->length = start - memory->start;
        memory->next = newMem;
        /* add remainder block */
        if (diff > 0){
            Memory * remMem = (Memory *) malloc(sizeof(Memory));
            assert(remMem);
            remMem->start = start + length;
            remMem->length = diff;
            remMem->status = true;
            remMem->next = newMem->next;
            newMem->next = remMem;
        }
    }
    else
        printf("Error allocation\n");
    return;
}

void freeMemory(Memory * memory, int start, int length){
    /* 1 traverse former nodes */
    while (memory->next != NULL && memory->start + memory->length < start){
        memory = memory->next;
    }
    /* 2..1 free a complete same block */
    if (memory->start == start && memory->length == length){
        memory->status = false;
        if (!((memory->next)->status))
    }
    /* 2..2 same start, diff end */
    else if (memory->start == start){
        /* 2..2.1 build free block */
        Memory * remMem = (Memory *) malloc(sizeof(Memory));
        assert(remMem);
        remMem->next = memory->next;
        remMem->start = memory->start + memory->length;
        remMem->length = (remMem->next)->start - remMem->start;
        remMem->status = false;
        /* adjust memory */
        memory->next = remMem;
        memory->length = remMem->start - start;
        memory->status = true;
    }
    /* 2..3 diff start same end */
    else if (memory->start + memory->length == start + length){
        Memory freeMem
    }
    /* 2..4 diff start diff end */
    else {
        /* 2..3.1 build free block and adjust stuffs of the front node */
        Memory * freeMem = (Memory *) malloc(sizeof(Memory));
        assert(freeMem);
        memory->next = freeMem;
        memory->length = start - memory->start;
        freeMem->status = true;
        /* 2..3.2 kill (free) covered blocked */
        Memory * tmp;
        while(memory != NULL && memory->start + memory->length < start + length){
            tmp = memory;
            memory = memory-> next;
            free(tmp);
        }
        /* 2..3.3 adjust back stuff */
        freeMem->next = memory;
        memory->length -= (start + length - memory->start);
        memory->start = start + length;
    }
    /* 3 merge free blocks */
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