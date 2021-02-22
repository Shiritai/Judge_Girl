#ifndef _NODE_H
#define _NODE_H
 
typedef struct node {
    int value;
    struct node * next;
} node;
 
node * merge(node *, node *);
 
#endif