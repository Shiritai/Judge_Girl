/* 10032. String Subset */
# include <stdio.h>
# include <string.h>
# include <assert.h>
# include <stdlib.h>
typedef struct linked_dict {
    char word[501];
    struct linked_dict * next; 
} Dict;
void print_dict(Dict * start){
    while (start != NULL){
        printf("%s\n", start->word);
        start = start->next;
    }
    return;
}
void init(Dict ** head, char * in_word){
    assert(*head == NULL);
    *head = (Dict *) malloc(sizeof(Dict));
    strcpy((*head)->word, in_word);
    (*head)->next = NULL;
    return;
}
void insert(Dict ** head, char * in_word){
    Dict * start = * head, * prev = NULL;
    int add_first = 1;
    while (start != NULL){
        if (strcmp(start->word, in_word) > 0)
            break;
        else if (strcmp(start->word, in_word) == 0)
            return;
        prev = start;
        start = start->next;
        add_first = 0;
    }
    Dict * newNode = (Dict *) malloc(sizeof(Dict));
    assert(newNode != NULL);
    strcpy(newNode->word, in_word);
    if (add_first){
        *head = newNode;
        newNode->next = start;
    }
    else {
        newNode->next = start;
        prev->next = newNode;
    }
    return;
}
int main(void){
    char input[501], * ptr = input;
    int len = strlen(input);
    scanf("%s", input);
    Dict * head = NULL;
    init(&head, input);
    for (int i = 0; i < len; ++i){
        char tmp[501] = "";
        for (int j = 1; j <= len - i; ++j){
            strncpy(tmp, ptr+i, j);
            tmp[strlen(tmp)] = '\0';
            insert(&head, tmp);
        }
    }
    print_dict(head);
    return 0;
}