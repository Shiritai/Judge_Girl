/* 134. Reconstruct A Binary Tree */
# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * left, * right;
} Node;

int comp(const void * data1, const void * data2){
    int * ptr2 = (int *) data2;
    int * ptr1 = (int *) data1;
    return (ptr1[1] != ptr2[1]) ? ptr1[1] - ptr2[1] : ptr1[0] - ptr2[0];
}

Node * add(Node * cur, int data){
    if (cur == NULL){
        cur = (Node *)malloc(sizeof(Node));
        cur->data = data;
        cur->left = cur->right = NULL;
        return cur;
    }
    if (data < cur->data)
        cur->left = add(cur->left, data);
    else if (data > cur->data)
        cur->right = add(cur->right, data);
    return cur;
}
    
Node * rebuild(int arr[][2], int nums){
    Node * root = (Node *) malloc(sizeof(Node));
    root->data = arr[0][0];
    root->left = root->right = NULL;
    for (int i = 1; i < nums; i++){
        root = add(root, arr[i][0]);
    }
    return root;
}

int distToNull(Node * cur, int data){
    if (data == cur->data)
        return 0;
    int res = 0;
    for (; cur != NULL && cur->data != data; ++res){
        if (data < cur->data)
            cur = cur->left;
        else // data > cur->data
            cur = cur->right;
    }
    return res;
}

int dist(Node * cur, int data1, int data2){
    while (cur != NULL){
        if (data1 < cur->data && data2 < cur->data)
            cur = cur->left;
        else if (data1 > cur->data && data2 > cur->data)
            cur = cur->right;
        else break;
    }
    if (cur != NULL)
        return distToNull(cur, data1) + distToNull(cur, data2);
    else {
        puts("Error");
        return 0;
    }
}

void preOrder(Node * cur){
    if (cur != NULL){
        printf("%d\n", cur->data);
        preOrder(cur->left);
        preOrder(cur->right);
    }
}

int main(void){
    int nums, arr[1000][2], lineNum, tmpData1, tmpData2;

    scanf("%d", &nums);
    for (int i = 0; i < nums; ++i)
        scanf("%d%d", &arr[i][0], &arr[i][1]);

    qsort(arr, nums, sizeof(arr[0]), comp);

    Node * root = rebuild(arr, nums);

    // preOrder(root); // for debuging
    
    scanf("%d", &lineNum);
    while (lineNum > 0){
        scanf("%d%d", &tmpData1, &tmpData2);
        printf("%d\n", dist(root, tmpData1, tmpData2));
        --lineNum;
    }
}