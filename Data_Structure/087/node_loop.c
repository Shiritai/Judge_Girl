/* 87. Merge Lists */
# include <stdio.h>
# include "node.h"

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
        if (tmp1->value < tmp2->value && (tmp1->next)->value > tmp2->value)
            link(&tmp1, &tmp2);
        else if ((tmp1->next)->value < tmp2->value)
            tmp1 = tmp1->next;
    }
    if (tmp1->value < tmp2->value)
        tmp1->next = tmp2;
    return (list1->value < list2->value) ? list1 : list2;
}