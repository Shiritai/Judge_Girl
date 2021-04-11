# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define LEN 10000

typedef struct Node {
    int year, month, date, cost;
    char category[32];
} Node;

void copyNode(Node * destination, int year, int month, int date, int cost, char * category){
    destination->year = year;
    destination->month = month;
    destination->date = date;
    destination->cost = cost;
    strcpy(destination->category, category);
}

int comp(const void * data1, const void * data2){
    Node * a = *(Node **) data1;
    Node * b = *(Node **) data2;
    if (a->year != b->year)
        return a->year - b->year;
    if (a->month != b->month)
        return a->month - b->month;
    if (a->date != b->date)
        return a->date - b->date;
    return strcmp(a->category, b->category);
}

int main(void){
    Node data[LEN], * dataPtr[LEN];
    int y, m, d, c, length = 0;
    char tmp[32];
    for (int i = 0; i < LEN; ++i){
        dataPtr[i] = data + i;
    }
    while (scanf("%d%d%d%s%d", &y, &m, &d, tmp, &c) == 5){
        copyNode(dataPtr[length++], y, m, d, c, tmp);
    }
    qsort(dataPtr, length, sizeof(dataPtr[0]), comp);
    Node * tmpPtr = dataPtr[0];
    for (int i = 1; i < length; ++i){
        if (tmpPtr->year != dataPtr[i]->year || tmpPtr->month != dataPtr[i]->month
        || tmpPtr->date != dataPtr[i]->date || strcmp(tmpPtr->category,dataPtr[i]->category)){
            printf("%4d %d %d %s %d\n", tmpPtr->year, tmpPtr->month
                , tmpPtr->date, tmpPtr->category, tmpPtr->cost);
            tmpPtr = dataPtr[i];
        }
        else 
            tmpPtr->cost += dataPtr[i]->cost;
    }
    printf("%4d %d %d %s %d\n", tmpPtr->year, tmpPtr->month
        , tmpPtr->date, tmpPtr->category, tmpPtr->cost);
}