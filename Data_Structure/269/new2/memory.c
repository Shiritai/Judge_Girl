# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "memory.h"

/* 使用虛擬 Head Node, 僅儲存 Avaliable 部分 */
void initMemory(Memory * memory, int length){
    memory->start = -1;
    memory->length = 0;
    memory->next = (Memory *) malloc(sizeof(Memory));
    memory->next->start = 0;
    memory->next->length = length;
    memory->next->next = NULL;
}

/* 輔助函數，由 Memory 基礎資料建立新 Memory block */
Memory * init(Memory * next, int start, int length){
    Memory * cur = (Memory *) malloc(sizeof(Memory));
    cur->start = start;
    cur->length = length;
    cur->next = next;
    return cur;
}

void printMemory(Memory * cur){
    if (cur->start == -1)
        cur = cur->next;
    puts("==========");
    while (cur != NULL){
        printf("start %d, length %d\n", cur->start, cur->length);
        cur = cur->next;
    }
}

/* 傳入再移動至下一個 Memory block */
void allocateMemory(Memory * prev, int start, int length){
    Memory * cur = prev->next; 
    if (cur != NULL){
        if (start >= cur->start  && start <= cur->start + cur->length){
            assert(cur->start + cur->length >= start + length); // 確保真的可以 Allocate
            if (start == cur->start && length == cur->length){
                prev->next = cur->next;
                free(cur);
            }
            else if (start == cur->start){
                cur->start = start + length;
                cur->length -= length;
            }
            else if (start + length == cur->start + cur->length)
                cur->length = start - cur->start;
            else { // 欲定址記憶體在中間，將 Avaliable 分成兩半
                cur->next = init(cur->next, start + length, cur->start + cur->length - start - length);
                cur->length = start - cur->start;
            }
        }
        else 
            allocateMemory(cur, start, length); // 將當前節點 Recur 即可
    }
}

void freeMemory(Memory * prev, int start, int length){
    Memory * cur = prev->next;
    if (cur != NULL){
        if (start >= prev->start + prev->length && start + length <= cur->start){
            if (start == prev->start + prev->length && start + length == cur->start){
                prev->next = cur->next;
                prev->length += cur->length + length;
                free(cur);
            }
            else if (start == prev->start + prev->length)
                prev->length += length;
            else if (start + length == cur->start){
                cur->length += length;
                cur->start = start;
            }
            else // 新 available Memory 在兩個舊 block 之間
                prev->next = init(cur, start, length);
        }
        else 
            freeMemory(cur, start, length);
    }
    else {
        if (start == prev->start + prev->length)
            prev->length += length;
        else 
            prev->next = init(NULL, start, length);
    }
}