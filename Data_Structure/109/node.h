#ifndef _NODE_H
#define _NODE_H
 
typedef struct node {
    struct node *left;
    struct node *right;
    int data;
} Node;
 
void print_all_paths(struct node *root);
 
#endif