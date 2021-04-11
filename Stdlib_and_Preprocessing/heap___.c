/* 我老了，留著作紀念 */
/* 239. Daily Expense */
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>
/* 注意 Heap 自 1 開始定義 */
typedef struct Node {
    int year;
    int month;
    int date;
    char category[32];
    int cost;
} Node;

Node * maxheap;
int size = 0, capacity = 0;
int * index/* , * reverse */;

/* *
 * 若 a >= b, 返回 1 (true)
 * 其餘返回 0 (false)
 * 定義 「>」 者為
 * 1. 日期小者
 * 2. 字典序小者 
 * */
_Bool nodeCompare(Node * a, Node * b){
    if (a->year < b->year)
        return 1;
    else if (a->month < b->month)
        return 1;
    else if (a->date < b->date)
        return 1;
    return (strcmp(a->category, b->category) < 0) ? 1 : 0;
}

/* 初始化整個 max heap */
void init(int cap){
    if (cap < 32)   cap = 32;
    data = (Node *) malloc(sizeof(Node) * cap);
    index = (int *) malloc(sizeof(int) * cap);
    // reverse = (int *) malloc(sizeof(int) * cap);
    // for (int i = 0; i < cap; ++i)
    //     reverse[i] = 0;
    size = capacity = 0;
}

/* 深度複製節點 */
void copyNode(Node * destination, Node * source){
    destination->year = source->year;
    destination->month = source->month;
    destination->date = source->date;
    destination->cost = source->cost;
    strcpy(destination->category, source->category);
}

/* 重設 Heap 大小, 傳入大小變化比率 ratio */
void resize(float ratio){
    int newCap = (int) (capacity * ratio);
    Node * tmpData = (Node *) malloc(sizeof(Node) * newCap);
    int tmpIndex = (int *) malloc(sizeof(int) * newCap);
    // int tmpReverse = (int *) malloc(sizeof(int) * newCap);
    for (int i = 0; i < ((newCap > capacity) ? capacity : newCap); ++i){
        copyNode(tmpData[i], data[i]);
        tmpIndex[i] = index[i];
        // tmpReverse[i] = reverse[i];
    }
    data = tmpData;
    index = tmpIndex;
    // reverse = tmpReverse;
    free(tmpData);
    free(tmpIndex);
    // free(tmpReverse);
    capacity = newCap;
}

/* 嘗試將 index[i] 元素 shift up */
void shiftUp(int i){
    while (i > 1 && !nodeCompare(data[index[i >> 1]], data[index[i]])){
        int tmp = index[i];
        index[i] = index[i >> 1];
        index[i >> 1] = tmp;
        i >>= 1;
    }
}

/* 插入新元素 */
void insert(Node node){
    if (size + 1 == capacity)
        resize(2);
    copyNode(data[++size], &node);
    index[size] = size;
    // reverse[size] = size;
    shiftUp(size);
}

Node getElement(){
    
}

int main(void){
    int y, m, d, c;
    char tmp[32];
    while (scanf("%d%d%d%s%d", &y, &m, &d, tmp, &c) == 5 && c >= 0){

    }
}