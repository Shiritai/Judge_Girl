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

void link(node ** tmp1_link, node ** tmp2){
    if ((* tmp2)->next != NULL){
        node * tmp_next = (* tmp1_link)->next, * tmp2_res = (* tmp2)->next;
        (* tmp1_link)->next = (* tmp2);
        (* tmp2)->next = tmp_next;
        printf("%d --> %d --> %d\n", (* tmp1_link)->value, (* tmp2)->value, ((* tmp2)->next)->value); // debug
        * tmp1_link = tmp_next;
        * tmp2 = tmp2_res;
    }
    else {
        node * tmp_next = (* tmp1_link)->next;
        (* tmp1_link)->next = (* tmp2);
        (* tmp2)->next = tmp_next;
        printf("%d --> %d --> %d\n", (* tmp1_link)->value, (* tmp2)->value, ((* tmp2)->next)->value); // debug
    }
    return;
}

node * merge(node * list1, node * list2){
    node * tmp1 = list1, * tmp2 = list2;
    while (1){
        if (tmp1->next != NULL && tmp2->next != NULL){
            if (tmp1->value < tmp2->value){
                if ((tmp1->next)->value > tmp2->value)
                    link(&tmp1, &tmp2);
                else
                    tmp1 = tmp1->next;
            }
            else if (tmp2->value < tmp1->value){
                if ((tmp2->next)->value > tmp1->value)
                    link(&tmp2, &tmp1);
                else
                    tmp2 = tmp2->next;
            }
            puts("a");
        }
        if (tmp1->next == NULL && tmp2->next != NULL){
            while (1){
                if (tmp2->next == NULL){
                    if (tmp1->value > tmp2->value)
                        tmp2->next = tmp1;
                    break;
                }
                else if (tmp2->value < tmp1->value && (tmp2->next)->value > tmp1->value){
                    link(&tmp2, &tmp1);
                    break;
                }
                else 
                    tmp2 = tmp2->next;
            }
            puts("b");
        }
        if (tmp1->next != NULL && tmp2->next == NULL){
            while (1){
                if (tmp1->next == NULL && tmp2->value > tmp1->value){
                    tmp1->next = tmp2;
                    break;
                }
                if (tmp1->value < tmp2->value && (tmp1->next)->value > tmp2->value){
                    link(&tmp1, &tmp2);
                    break;
                }
                else
                    tmp1 = tmp1->next;
            }
            puts("c");
        }
        if (tmp1->next == NULL && tmp2->next == NULL) {
            if (tmp1->value < tmp2->value)
                tmp1->next = tmp2;
            else
                tmp1->next = tmp2;
            puts("d");
            break;
        }
        printf("tmp1 : %d, tmp2 : %d\n", tmp1->value, tmp2->value);
    }
    puts("go_to_print");
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