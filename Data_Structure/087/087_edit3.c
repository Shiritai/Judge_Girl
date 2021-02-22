/* 87. Merge Lists */
#include <stdio.h>
#include <stdlib.h>
 
#define LEN 1000
 
typedef struct node {
    int value;
    struct node * next;
} node;

struct node * build(int v[], int n) {
    struct node * head, * ptr;
    int i;
    if (!n)
        return 0;
    head = (struct node *) malloc(sizeof(struct node));
    ptr = head;
    head -> value = v[0];
    for (i = 1; i < n; i++) {
        ptr -> next = (struct node *) malloc(sizeof(struct node));
        ptr = ptr -> next;
        ptr -> value = v[i];
    }
    ptr -> next = 0;
    return head;
}
 
void print(struct node * ptr) {
    printf("%d", ptr -> value);
    if (ptr -> next) {
        putchar(' ');
        print(ptr -> next);
    }
}

void test_print(node * ptr){
    int tmp;
    while (ptr != NULL){
        printf("%d ", ptr->value);
        if (tmp == ptr->value)   
            break;
        tmp = ptr->value;
        ptr = ptr->next;
    }
    puts("\n");
}

// void link(node ** tmp1_link, node ** tmp2){
//     node * tmp1_next = (* tmp1_link)->next;
//     (* tmp1_link)->next = * tmp2;
//     * tmp1_link = tmp1_next;
//     return;
// }

void link(node ** tmp1_link, node ** tmp2){
    node * tmp1_next = (* tmp1_link)->next;
    (* tmp1_link)->next = * tmp2;
    * tmp1_link = * tmp2;
    * tmp2 = tmp1_next;
    return;
}

node * merge(node * list1, node * list2){
    node * tmp1, * tmp2;
    if (list1->value < list2->value){
        tmp1 = list1;
        tmp2 = list2;
    }
    else {
        tmp2 = list1;
        tmp1 = list2;
    }
    while (tmp2 != NULL && tmp1->next != NULL){
        if (tmp1->value < tmp2->value && (tmp1->next)->value > tmp2->value){
            link(&tmp1, &tmp2);
            printf("%d (%p) --> %d (%p)\n", tmp1->value, tmp1, tmp2->value, tmp2);
        }
        else if ((tmp1->next)->value < tmp2->value)
            tmp1 = tmp1->next;
        test_print((list1->value < list2->value) ? list1 : list2);
    }
    if (tmp1->value < tmp2->value)
        tmp1->next = tmp2;
    return (list1->value < list2->value) ? list1 : list2;
}
 
int main() {
    int n1, n2;
    int v1[LEN], v2[LEN];
    int i;
    struct node * list1, * list2;
 
    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
        scanf("%d", &v1[i]);
    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
        scanf("%d", &v2[i]);
    list1 = build(v1, n1);
    list2 = build(v2, n2);
 
    print(merge(list1, list2));
    putchar('\n');
    return 0;
}