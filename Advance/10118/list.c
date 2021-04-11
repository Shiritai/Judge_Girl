#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
 
Node * mk_list(int n) {
    Node * head = (Node *) malloc(sizeof(Node));
    head->v = sp_rand(), head->next = NULL;
    Node * prev = head;
    for (int i = 1; i < n; i++) {
        Node * u = (Node *) malloc(sizeof(Node));
        u->v = sp_rand(), u->next = NULL;
        prev->next = u;
        prev = u;
    }
    return head;
}
void rm_list(Node *head) {
    Node * prev = head;
    while (head->next != NULL){
        prev = head, head = head->next;
        free(prev);
    }
    free(head);
}