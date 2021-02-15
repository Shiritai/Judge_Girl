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
    return 0;
}

void initMemory(Memory * memory, int length){
    assert(length > 0);
    printf("%p\n", memory);
    * memory = (Memory) {0, length, NULL};
    assert(memory != NULL);
    printf("%p\n", memory);
    return;
}

void printMemory(Memory * memory){
    puts("==========");
    for (; memory != NULL; memory = memory->next)
        printf("start %d, length %d\n", memory->start, memory->length);
    return;
}

void allocateMemory(Memory * memory, int start, int length){
    for (; memory->next != NULL && (memory->next)->start <= start; memory = memory->next); // traverse
    /* Case 1 : same block */
    if (memory->start == start && memory->length == length){
        puts("AC1");
        if (memory->next != NULL){
            memory->start = (memory->next)->start;
            memory->length = (memory->next)->length;
            if ((memory->next)->next != NULL)
                memory->next = (memory->next)->next;
            else 
                memory->next = NULL;
            free(memory->next);
        }
        else 
            free(memory);
    }
    /* Case 2 : same end */ // 去尾
    else if (memory->start + memory->length == start + length){
        puts("AC2");
        memory->length = start - memory->start;
    }
    /* Case 3 : same start and diff end */ // 縮頭
    else if (memory->start == start){
        puts("AC3");
        memory->start = start + length;
        memory->length -= length;
    }
    /* Case 4 : diff start and diff end */
    else {
        /* create remainder free block */
        Memory * reFrMem = (Memory *) malloc(sizeof(Memory));
        puts("AC4");
        assert(reFrMem != NULL);
        reFrMem->start = start + length;
        reFrMem->length = memory->start + memory->length - (start + length);
        if (memory->next != NULL)
            reFrMem->next = memory->next;
        else 
            reFrMem->next = NULL;
        /* adjust former block */
        memory->length = start - memory->start;
        memory->next = reFrMem;
    }
    return;
}

void freeMemory(Memory * memory, int start, int length){
    /* 頭接壤 */
    if (memory->start > start){
        if (start + length == memory->start){
            memory->start = start;
            memory->length += length;
        }
        else {
            Memory * tmp = (Memory *) malloc(sizeof(Memory));
            * tmp = (Memory) {memory->start, memory->length, memory->next};
            * memory = (Memory) {start, length, tmp};
        }
        return;
    }
    for (; (memory->next)->start < start; memory = memory->next); // traverse
    /* Case 1 : 續前 */
    if (memory->start + memory->length == start){
        puts("TC1");
        memory->length += length;
        /* 同時接壤 */
        if (memory->next != NULL && memory->start + memory->length == (memory->next)->start){
            memory->length += (memory->next)->length;
            if ((memory->next)->next != NULL){
                Memory * tmp = (memory->next)->next;
                free(memory->next);
                memory->next = tmp;
            }
            else {
                free(memory->next);
                memory->next = NULL;
            }
        }
    }
    /* Case 2 : 接壤 */
    else if (memory->next != NULL && start + length == (memory->next)->start){
        puts("TC2");
        (memory->next)->start = start;
        (memory->next)->length += length;
    }
    /* Case 3 : others */
    else {
        puts("TC3");
        Memory * freeMem = (Memory *) malloc(sizeof(Memory));
        freeMem->start = start, freeMem->length = length;
        if (memory->next != NULL)
            freeMem->next = memory->next;
        else 
            freeMem->next = NULL;
        memory->next = freeMem;
    }
    return;
}

void freeAllMemory(Memory * memory){
    Memory * now = memory, * prev;
    while (now->next != NULL){
        prev = now;
        now = now->next;
        free(prev);
    }
    free(now);
    puts("free complete");
    return;
}