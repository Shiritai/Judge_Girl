/* 77. Get the i-th Element in a List */
#ifndef _NODE_H
#define _NODE_H
 
struct node {
    struct node * next;
    struct node * prev;
};
struct node * getNode(struct node * head, unsigned int i);
#endif /* NODE_H */