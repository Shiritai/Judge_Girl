/* 109. Tree Path Printing */
# include <stdio.h>
# include "node.h"

int tmpArr[1001], size = 0;

void print_path_recur(Node * root){
    if (root->left == NULL && root->right == NULL){
        tmpArr[size] = root->data;
        for (int i = 0; i <= size; ++i){
            printf("%d%c", tmpArr[i], " \n"[i == size]);
        }
        return;
    }
    if (root != NULL){
        tmpArr[size++] = root->data;
        if (root->left != NULL)
            print_path_recur(root->left);
        if (root->right != NULL)
            print_path_recur(root->right);
        --size;
    }
}

/* Init tmpArr to start with the printing */
void print_all_paths(Node * root){
    size = 0;
    print_path_recur(root);
}
