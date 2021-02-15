/* 230. The Knapsack */ // linked list
# include <stdio.h>
# include <stdlib.h> 
# include <assert.h>

int limit;

typedef struct monolist{
    int weight, value;
    struct monolist * next;
} mono;

mono * init(mono * last, int w, int v){
    mono * tmp = (mono *) malloc(sizeof(mono));
    assert(tmp != NULL);
    tmp->weight = w, tmp->value = v;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    return tmp;
}

void print_mono(mono * head){
    while (head != NULL){
        printf("%d %d\n", head->weight, head->value);
        head = head->next;
    }
}

int find_max(mono * start, int curLim, int curVal){
    if (start != NULL && curLim < limit){
        int tmp1 = find_max(start->next, curLim + start->weight, curVal + start->value); // select
        int tmp2 = find_max(start->next, curLim, curVal); // not select
        return (tmp1 > tmp2) ? tmp1 : tmp2;
    }
    else if (curLim > limit){
        return 0;
    }
    else if (curLim == limit || start == NULL){
        return curVal;
    }
    else {
        puts("error");
        // printf("error : %d + %d, %d + %d, %p\n", curLim, start->weight, curVal, start->value, start);
        return 0;
    }
}

int main(void){
    int num, tmpIn1, tmpIn2;
    scanf("%d%d%d%d", &num, &limit, &tmpIn1, &tmpIn2);
    mono * head, * prev;
    head = prev = init(NULL, tmpIn1, tmpIn2);
    for (int i = 1; i < num; ++i){
        scanf("%d%d", &tmpIn1, &tmpIn2);
        prev = init(prev, tmpIn1, tmpIn2);
    }
    // print_mono(head); // debug
    printf("%d\n", find_max(head, 0, 0));
    return 0;
}