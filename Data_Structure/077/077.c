/* 77. Get the i-th Element in a List */
/* method : generate "node->prev" */
# include <stdio.h>
# include "node.h"
struct node * getNode(struct node * head, unsigned int i){
    unsigned int indice = 0;
    head->prev = NULL;
    struct node * current = head;
    while (current->next != NULL){
        (current->next)->prev = current;
        current = current->next; // traverse
        ++indice;
    }
    if (i > indice) return NULL;
    while (i > 0)   current = current->prev, --i;
    return current;
}