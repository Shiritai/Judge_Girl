/* 269. Memory Allocation */
#include "memory.h"
int main() {
    Memory myMemory;
    // initMemory(&myMemory, 100);
    // printMemory(&myMemory);
    // allocateMemory(&myMemory, 50, 10);
    // printMemory(&myMemory);
    // allocateMemory(&myMemory, 70, 10);
    // printMemory(&myMemory);
    // allocateMemory(&myMemory, 0, 10);
    // printMemory(&myMemory);
    // allocateMemory(&myMemory, 30, 10);
    // printMemory(&myMemory);
    // freeMemory(&myMemory, 50, 5);
    // printMemory(&myMemory);
    // freeMemory(&myMemory, 70, 10);
    // printMemory(&myMemory);
    // freeMemory(&myMemory, 30, 10);
    // printMemory(&myMemory);
    // freeMemory(&myMemory, 0, 10);
    // printMemory(&myMemory);
    initMemory(&myMemory, 100);
    printMemory(&myMemory);
    allocateMemory(&myMemory, 10, 10);
    printMemory(&myMemory);
    allocateMemory(&myMemory, 20, 10);
    printMemory(&myMemory);
    allocateMemory(&myMemory, 0, 10);
    printMemory(&myMemory);
    allocateMemory(&myMemory, 30, 70);
    printMemory(&myMemory);
    printMemory(&myMemory);
    freeMemory(&myMemory, 40, 20);
    printMemory(&myMemory);
    freeMemory(&myMemory, 80, 10);
    printMemory(&myMemory);
    freeMemory(&myMemory, 10, 10);
    printMemory(&myMemory);
    freeMemory(&myMemory, 0, 10);
    printMemory(&myMemory);
    freeMemory(&myMemory, 20, 20);
    printMemory(&myMemory);
    freeMemory(&myMemory, 90, 10);
    printMemory(&myMemory);
    freeMemory(&myMemory, 60, 20);
    printMemory(&myMemory);
    return 0;
}