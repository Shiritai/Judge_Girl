/* 65. Expression Tree */
# include <stdio.h>
# include <assert.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

typedef struct Node {
    char dataOp;
    int dataInt;
    struct Node * left, * right;
} Node;

char * dataString;
int readPos, readEnd;

int readInt(const char * string){
    int res;
    sscanf(string, "%d", &res);
    for (int i = 0; readPos != readEnd && string[i] != ' '; ++i, ++readPos);
    return res;
}

void readBlankParenthesis(){
    while (readPos != readEnd && (dataString[readPos] == ' ' || dataString[readPos] == '(' || dataString[readPos] == ')')){
        ++readPos;
    }
}

/* PreOrder */
Node * build(Node * cur){
    if (readPos != readEnd){
        readBlankParenthesis();
        /* Basis */
        if (isdigit(dataString[readPos])){
            if (cur == NULL){
                cur = (Node *) malloc(sizeof(Node));
            }
            cur->dataInt = readInt(dataString + readPos);
            cur->left = cur->right = NULL;
        }
        /* Recursion */
        else {
            if (cur == NULL){
                cur = (Node *) malloc(sizeof(Node));
                cur->left = cur->right = NULL;
            }
            readBlankParenthesis();
            cur->dataOp = dataString[readPos++];
            readBlankParenthesis();
            cur->left = build(cur->left);
            readBlankParenthesis();
            cur->right = build(cur->right);
        }
        return cur;
    }
    else {
        return cur;
    }
    return NULL;
}

/* i.e. Compute the "cur" tree */
int postOrderValue(Node * cur){
    assert(cur != NULL);
    if (cur->left == NULL && cur->right == NULL)
        return cur->dataInt;
    int data1 = postOrderValue(cur->left);
    int data2 = postOrderValue(cur->right);
    switch (cur->dataOp){
        case '+':
            return data1 + data2;
        case '-':
            return data1 - data2;
        case '*':
            return data1 * data2;
        case '/':
            return data1 / data2;
        default:
            return 0;
    }
}

/* For debuging */
void preOrder(Node * cur){
    assert(cur != NULL);
    if (cur->left == NULL && cur->right == NULL)
        printf("%d\n", cur->dataInt);
    else {
        printf("%c\n", cur->dataOp);
        preOrder(cur->left);
        preOrder(cur->right);
    }
}

char * str_certain_str(const char * string, const char * subStr){
    char * tmpTarget = strstr(string, subStr);
    while (tmpTarget != NULL && tmpTarget + strlen(subStr) != string){
        if (tmpTarget[strlen(subStr)] == ' ' || tmpTarget[strlen(subStr)] == '\0'){
            return tmpTarget;
        }
        tmpTarget = strstr(tmpTarget + strlen(subStr), subStr);
    }
    return tmpTarget;
}

/* replace the repStr in source with repInt */
void replace(char * source, char * repStr, int repInt, char * destination){
    char * buf = (char *) malloc(sizeof(char) * strlen(destination));
    char * target = str_certain_str(source, repStr);
    assert(target != NULL);
    int i = 0;
    while (source + i != target)
        buf[i] = source[i], i++;
    buf[strlen(buf) - 1] = '\0'; // 記得下斷點，這樣 sprintf 才知道要讀到哪
    while (source[i] != ' ')
        ++i;
    sprintf(buf, "%s %d%s", buf, repInt, source + i);
    strcpy(destination, buf);
}

int main(void){
    char str[1024], declaration[64], var[32];
    int value;
    fgets(str, 0x7fffffff, stdin);
    str[strlen(str) - 1] = '\0';
    while (fgets(declaration, 0x7fffffff, stdin) != NULL){
        if (!strcmp(declaration, "-1\n")){
            break;
        }
        sscanf(declaration, "%s = %d", var, &value);
        while (str_certain_str(str, var) != NULL){
            replace(str, var, value, str);
        }
        // puts(dataString);
    }
    dataString = str, readPos = 0, readEnd = strlen(dataString); // initialize
    Node * root = NULL;
    root = build(root);
    printf("%d\n", postOrderValue(root));
}