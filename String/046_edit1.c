/* 46. Play with Words */
/* linked list */
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <assert.h>
# define BLOCK_LEN 4

char * posREC[BLOCK_LEN];
int ind = 0, all_ind = 0;

typedef struct Node{
    char data[BLOCK_LEN];
    char for_end;
    struct Node * next;
    struct Node * prev;
} node;

void init(node ** start, node ** end){
    node * tmp1 = (node *) malloc(sizeof(node));
    node * tmp2 = (node *) malloc(sizeof(node));
    assert(tmp1 != NULL && tmp2 != NULL);
    tmp1->next = tmp2, tmp1->prev = NULL;
    strcpy(tmp1->data, "\0");
    tmp2->next = NULL, tmp2->prev = tmp1;
    strcpy(tmp2->data, "\0");
    * start = tmp1, * end = tmp2;
    ind += 2;
    return;
}

void insert(node ** start, node ** end, char * pos, char input){
    if (!strcmp(pos, "left")){
        left :;
        if (strlen((* start)->data) < BLOCK_LEN){
            char tmp[BLOCK_LEN] = "";
            tmp[0] = input, tmp[1] = '\0';
            strcat(tmp, (* start)->data);
            strcpy((* start)->data, tmp);
        }
        else {
            puts("gen new node (1)");
            node * new = (node *) malloc(sizeof(node));
            assert(new != NULL);
            new->data[0] = input, new->data[1] = '\0';
            new->prev = NULL, new->next = * start;
            * start = new;
            /* count ind */
            ++ind;
        }
    }
    else if (!strcmp(pos, "right")){
        right :;
        if (strlen((* end)->data) < BLOCK_LEN){
            int add_pos = (int) strlen((* end)->data);
            (* end)->data[add_pos] = input, (* end)->data[add_pos+1] = '\0';
        }
        else {
            puts("gen new node (2)");
            node * new = (node *) malloc(sizeof(node));
            assert(new != NULL);
            new->data[0] = input, new->data[1] = '\0';
            new->prev = * end, new->next = NULL;
            (* end)->next = new;
            * end = new;
            /* count ind */
            ++ind;
        }
    }
    else {
        int int_pos = atoi(pos) - 1;
        /* efficient jump */
        if (int_pos == 0)   goto left;
        if (int_pos == all_ind)   goto right;
        
        node * tmp = * start;
        while (tmp != NULL && int_pos > 0){
            int tmp_len = strlen(tmp->data);
            if (int_pos < tmp_len/*  && tmp_len <= BLOCK_LEN */){ // need to change moto string
                if (tmp_len == BLOCK_LEN) { // generate new node and pass the last char in the last node, then append input char
                    puts("tmp_len == BLOCK_LEN, gen new node and pass char, then append input");
                    node * new = (node *) malloc(sizeof(node));
                    assert(new != NULL);
                    new->data[0] = tmp->data[BLOCK_LEN - 1], new->data[1] = '\0';
                    new->prev = tmp, new->next = tmp->next;
                    tmp->next = new;
                    /* special case : last one */
                    if (new->next == NULL)
                        * end = new;
                    /* count ind */
                    ++ind;
                }
                char * tmpPtr = &tmp->data[int_pos], buf[BLOCK_LEN];
                buf[0] = input, buf[1] = '\0';
                tmp->data[BLOCK_LEN - 1] = '\0';
                strcat(buf, tmpPtr);
                strcpy((&tmp->data[int_pos]), buf);
                break;
            }
            else if (int_pos == tmp_len/*  && tmp_len < BLOCK_LEN */){
                if (tmp_len < BLOCK_LEN)
                    tmp->data[int_pos] = input, tmp->data[int_pos + 1] = '\0';
                else if (tmp_len == BLOCK_LEN){
                    puts("gen new node (3)");
                    node * new = (node *) malloc(sizeof(node));
                    assert(new != NULL);
                    new->data[0] = input, new->data[1] = '\0';
                    if (tmp->next != NULL){
                        new->prev = tmp, new->next = tmp->next;
                        (tmp->next)->prev = new, tmp->next = new;
                    }
                    else {
                        new->prev = tmp, new->next = NULL;
                        tmp->next = new;
                    }
                }
                /* count ind */
                ++ind;
                break;
            }
            int_pos -= tmp_len;
            tmp = tmp->next;
        }
    }
    ++all_ind;
    return;
}

void delete(node ** start, node ** end, char * pos){
    if (!strcmp(pos, "left")){
        left :;
        if (strlen((* start)->data) >= 2){
            char buf[BLOCK_LEN];
            strcpy(buf, (* start)->data);
            strcpy((* start)->data, buf+1);
        }
        else if (strlen((* start)->data) == 1){
            if ((* start)->next != * end){
                node * tmp = * start;
                * start = (* start)->next;
                free(tmp);
                --ind;
            }
            else 
                (* start)->data[0] = '\0';
        }
        else if (strlen((* start)->data) == 0){
            char buf[BLOCK_LEN];
            strcpy(buf, ((* start)->next)->data);
            strcpy(((* start)->next)->data, buf+1);
        }
    }
    else if (!strcmp(pos, "right")){
        right :;
        if (strlen((* end)->data) >= 2)
            (* end)->data[strlen((* end)->data) - 1] = '\0';
        else if (strlen((* end)->data) == 1){
            if ((* end)->prev != * start){
                node * tmp = * end;
                * end = (* end)->prev;
                free(tmp);
                --ind;
            }
            else 
                (* end)->data[0] = '\0';
        }
        else if (strlen((* end)->data) == 0)
            ((* end)->prev)->data[strlen(((* end)->prev)->data) - 1] = '\0';
    }
    else {
        int int_pos = atoi(pos) - 1;
        assert(int_pos <= all_ind-1);
        /* efficient jump */
        if (!int_pos)   goto left;
        if (int_pos == all_ind - 1) goto right;

        node * tmp = * start;
        while (tmp != NULL && int_pos >= 0){
            int tmp_len = strlen(tmp->data);
            if (int_pos < tmp_len - 1){
                char buf[BLOCK_LEN];
                strncpy(buf, tmp->data, int_pos);
                buf[int_pos] = '\0';
                strcat(buf, tmp->data + int_pos + 1);
                strcpy(tmp->data, buf);
                /* free empty block */
                if (!strlen(tmp->data) && tmp->next != * end && tmp->prev != * start){
                    (tmp->prev)->next = tmp->next;
                    (tmp->next)->prev = tmp->prev;
                    free(tmp);
                    --ind;
                }
                break;
            }
            else if (int_pos == tmp_len - 1 && int_pos != 0){
                tmp->data[int_pos] = '\0';
            }
            else if (int_pos == 0 && tmp_len == 1){
                /* free empty block */
                if (tmp != * end && tmp != * start){
                    puts("peek");
                    (tmp->prev)->next = tmp->next;
                    (tmp->next)->prev = tmp->prev;
                    free(tmp);
                    --ind;
                }
                break;
            }
            int_pos -= tmp_len;
            tmp = tmp->next;
        }
    }
    --all_ind;
    return;
}

void print(node * start, void * out){
    node * tmp = start;
    if ((FILE *) out == stdout){
        while (tmp != NULL){
            putchar(tmp->data[0]);
            for (int i = 1; i < strlen(tmp->data); ++i)
                printf(" %c", tmp->data[i]);
            if ((int) strlen(tmp->data) > 0){
                putchar('~');
                tmp = tmp->next;
            }
            else
                tmp = tmp->next;
        }
        puts("");
    }
    else {
        char tmp_char = '\0';
        int cont_len = 0, tmp_len = 0;
        _Bool take = 0;
        while (tmp != NULL){
            for (int i = 0; i < strlen(tmp->data); ++i){
                if (!take){ // init
                    tmp_len = 1, tmp_char = tmp->data[i];
                    take = 1;
                }
                else if (tmp_char == tmp->data[i]){
                    ++tmp_len;
                }
                else if (tmp_char != tmp->data[i]){
                    if (tmp_len > cont_len){
                        cont_len = tmp_len;
                        sprintf((char *) out, "%c", tmp_char); // with format
                        // sprintf((char *) out, "%s %c %d", (char *) out, tmp_char, tmp_len); // with format
                    }
                    else if (tmp_len == cont_len){
                        sprintf((char *) out, "%s %c", (char *) out, tmp_char); // with format
                        // sprintf((char *) out, "%s %c %d", (char *) out, tmp_char, tmp_len); // with format
                        // strncat((char *) out, &tmp_char, 1); // just append
                    }
                    tmp_len = 1, tmp_char = tmp->data[i];
                }
            }
            tmp = tmp->next;
            // for (int i = 0; i < strlen(tmp->data); ++i)
            //     strncat((char *) out, &tmp->data[i], 1);
            // tmp = tmp->next;
        }
        if (tmp_len > cont_len){
            cont_len = tmp_len;
            sprintf((char *) out, "%c", tmp_char); // with format
            // sprintf((char *) out, "%s %c %d", (char *) out, tmp_char, tmp_len); // with format
        }
        else if (tmp_len == cont_len){
            sprintf((char *) out, "%s %c", (char *) out, tmp_char); // with format
            // sprintf((char *) out, "%s %c %d", (char *) out, tmp_char, tmp_len); // with format
            // strncat((char *) out, &tmp_char, 1); // just append
        }
        if (cont_len)
            sprintf((char *) out, "%s %d", (char *) out, cont_len); // with format
        else 
            sprintf((char *) out, "0");
    }
    return;
}

void count_conseq(node * start){
    char result[BLOCK_LEN] = "";
    print(start, result);
    puts(result);
}

void freeList(node * start){
    node * tmp = start;
    while (start != NULL){
        tmp = start;
        start = start->next;
        free(tmp);
    }
    return;
}

int main(void){
    char cmd[50], * cmdPtr, place[6] = "", inChar;
    node * head, * tail;
    init(&head, &tail);
    printf("head at %p with next --> %p, prev --> %p\n", head, head->next, head->prev);
    printf("last at %p with next --> %p, prev --> %p\n", tail, tail->next, tail->prev);
    while (fgets(cmd, 0x7fffffff, stdin)){
        cmdPtr = strtok(cmd, " ");
        if (!strcmp(cmdPtr, "insert")){
            cmdPtr = strtok(NULL, " ");
            strcpy(place, cmdPtr);
            // puts(place);
            cmdPtr = strtok(NULL, " ");
            inChar = * cmdPtr;
            // putchar(inChar);
            insert(&head, &tail, place, inChar);
        }
        else if(!strcmp(cmdPtr, "delete")){
            cmdPtr = strtok(NULL, " \n");
            strcpy(place, cmdPtr);
            // puts(place);
            delete(&head, &tail, place);
        }
        else if (!strcmp(cmdPtr, "call_data\n")){ // debug
            printf("all_ind : %d, ind : %d\n", all_ind, ind);
            continue;
        }
        else if (!strcmp(cmdPtr, "call_result\n")){ // debug
            count_conseq(head);
            continue;
        }
        print(head, stdout);
    }
    count_conseq(head);
    freeList(head);
    return 0;
}