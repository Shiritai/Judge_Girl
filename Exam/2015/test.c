# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct node {
    struct n {
        int data;
        char chr;
    };
    struct n * Meow;
} node;
struct node * newNode(int data, char chr){
    node * tmpNode = (node *) malloc(sizeof(node));
    tmpNode->Meow->data = data;
    tmpNode->Meow->chr = chr;
    return tmpNode;
}

enum {
    INT, CHAR
};

typedef union {
    int u_intVal;
    char u_charVal;
} union_V;

typedef struct V {
    int type;
    union_V data;
} V;

typedef struct K {
    int data;
    char chr;
    V value;
} K;

int main(void){
    // node * tmp = newNode(1, 'a');
    // node * tmp2 = tmp;
    // printf("%p %p\n", tmp, tmp2);
    // putchar(tmp2->Meow->chr);
    // K tmp = {.data = 1, .chr = 'a', .value.type = INT, .value.data.u_intVal = 10};
    // K tmp2 = tmp;
    // K tmp3 = tmp2;
    // tmp2.chr = 'b';
    // tmp3.value.data.u_intVal = 20;
    // printf("%p %p %p\n", &tmp, &tmp2, &tmp3);
    // printf("%d %c %d\n", tmp.data, tmp.chr, tmp.value.data.u_intVal);
    // printf("%d %c %d\n", tmp2.data, tmp2.chr, tmp2.value.data.u_intVal);
    // printf("%d %c %d\n", tmp3.data, tmp3.chr, tmp3.value.data.u_intVal);
    char * tmp = "IamPEroiko!";
    char tmp2[15];
    memmove(tmp2, tmp, sizeof(char) * 3);
    strcpy(tmp2 + 3, tmp + 4);
    // memmove(tmp2 + 3, tmp + 4, sizeof(char) * 6);
    // tmp2[9] = '\0';
    // strncpy(tmp2, tmp, 3);
    // strncat(tmp2, tmp + 4, 3);
    puts(tmp2);

}