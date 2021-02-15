#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/* link list */
/* build node */
typedef struct listnode
{
    char data;
    struct listnode *next;
    struct listnode *prev;
} ListNode;
/* build doubly linked list */
void genNode(char data, ListNode ** start, ListNode ** moto_head)
{
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    assert(new_node != NULL);
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (* moto_head == NULL)
    {
        * moto_head = new_node;
        return;
    }
    else if (* start != NULL)
    {
        ListNode * curr_tmp;
        curr_tmp = * start; // * start == head
        curr_tmp->next = new_node;
        new_node->prev = curr_tmp;
        return;
    }
    else {
        new_node->prev = * start; // * start == head
        * start = * moto_head;
    }
}
/* traverse and print inverse list */
void printList(ListNode *node)
{
    for (; node != NULL; node = node->next)
    {
        printf("%c ", node->data);
    }
}
/* delete linked list */
void delList(ListNode *node)
{
    while (node != NULL)
    {
        ListNode *next = node->next;
        free(node);
        node = next;
    }
}
/* pop */
ListNode * pop(ListNode * node, ListNode ** head)
{
    ListNode * moto = node->prev;
    free(node);
    * head = (moto == NULL) ? NULL : * head;
    return moto;
}
int main(void)
{
    char cmd[4] = "", pushChar;
    ListNode *head = NULL;
    ListNode *prev_node = NULL;
    while (scanf("%s", cmd))
    {
        if (!strcmp(cmd, "push"))
        {
            scanf("\n%c", &pushChar);
            genNode(pushChar, &prev_node, &head);
        }
        else if (!strcmp(cmd, "pop"))
        {
            if (head == NULL)
            {
                printf("empty\n");
            }
            else
            {
                if (prev_node != NULL){
                    printf("%c\n", prev_node->data);
                    prev_node = pop(prev_node, &head);
                }
                else {
                    printf("%c\n", head->data);
                    head = NULL;
                }
            }
        }
        else if (!strcmp(cmd, "list"))
        {
            if (head == NULL)
            {
                printf("\n");
            }
            else
            {
                printList(head);
                printf("\n");
            }
        }
        else
            break;
    }
    delList(head);
    return 0;
}