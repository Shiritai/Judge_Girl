/* 267. Traveling Distance */
# include <stdio.h>
# include <stdlib.h>
// # define sq(a) (a) * (a)

typedef struct Coordinate {
    int x, y;
} Coo;

// int distToOrigin(Coo a){ return sq(a.x) + sq(a.y);}
int distToOrigin(Coo * a){ return a->x * a->x + a->y * a->y;}

// int dist(Coo a, Coo b){ return sq(a.x - b.x) + sq(a.y - b.y);}
int dist(Coo * a, Coo * b){ return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);}

int comp(const void * data1, const void * data2){
    Coo * a = (Coo *) data1, * b = (Coo *) data2;
    int aDist = distToOrigin(a), bDist = distToOrigin(b);
    if (aDist != bDist) // 小心邏輯障礙...
        return aDist - bDist;
    if (a->x < b->x || (a->x == b->x && a->y < b->y)) // 小心邏輯障礙...
        return -1;
    return 1;
}

int main(void){
    Coo list[100000];
    int size = 0;
    while (scanf("%d%d", &list[size].x, &list[size].y) == 2)
        ++size;
    qsort(list, size, sizeof(list[0]), comp);
    int sum = distToOrigin(&list[0]);
    for (int i = 1; i < size; ++i)
        sum += dist(&list[i - 1], &list[i]);
    printf("%d\n", sum);
}