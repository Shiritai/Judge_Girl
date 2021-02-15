/* 94. Tree Traversal */  // parser tree
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>

char * inPtr;

typedef struct tree{
    int data;
    struct tree * left;
    struct tree * right;
} tree;

tree * init(int num){
    tree * tmp = (tree *) malloc(sizeof(tree));
    tmp->left = tmp->right = NULL;
    tmp->data = num;
    return tmp;
}

tree * parser(void){
    /* skip redundant char */
    while (!isdigit(* inPtr) && * inPtr != '-' && * inPtr != '(')    ++inPtr;
    /* terminate condition */
    if (isdigit(* inPtr) || * inPtr == '-'){
        int num;
        sscanf(inPtr, "%d", &num); // take left digit
        while (isdigit(* inPtr) || * inPtr == '-')   ++inPtr; // move inPtr
        return init(num);
    }
    /* parser */
    else if (* inPtr == '('){
        tree * tmp = init(0);
        ++inPtr;
        tmp->left = parser();
        ++inPtr;
        tmp->right = parser();
        tmp->data = (tmp->left)->data + (tmp->right)->data;
        return tmp;
    }
    return init(0);
}

void traverse(tree * root, _Bool mode){
    if (root != NULL){
        if (!mode){
            printf("%d\n", root->data);
            traverse(root->left, !mode);
            printf("%d\n", root->data);
            traverse(root->right, !mode);
        }
        else {
            printf("%d\n", root->data);
            traverse(root->right, !mode);
            printf("%d\n", root->data);
            traverse(root->left, !mode);
        }
    }
    return;
}

void freeTree(tree * root){
    if (root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
    return;
}

int main(void){
    char input[4000];
    scanf("%s", input);
    inPtr = input;
    tree * root = parser();
    traverse(root, 0);
    freeTree(root);
    return 0;
}