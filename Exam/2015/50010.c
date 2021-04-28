/* 50010. Word Editor */
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define BUF 64
# define MAX_LEN 1024

static char * word, * array, * front_ptr, * tail_ptr, * last_pos;
int front_buf = BUF;

void reset(){
    char * newWord = (char *) malloc(sizeof(char) * (MAX_LEN + 1));
    memset(newWord, '0', sizeof(char) * MAX_LEN);
    int w = BUF;

    int wordLen = strlen(word);
    for (int i = 0; i < wordLen; ++i){
        if (word[i] != '_')
            newWord[w++] = word[i];
    }
    // for (char * tmp = word; tmp != tail_ptr; ++tmp)
    //     if (* tmp != '_')
    //         newWord[w++] = * tmp;

    newWord[w] = '\0';
    free(word);
    word = newWord;
    array = word + sizeof(char) * BUF;
    front_ptr = array;
    tail_ptr = word + sizeof(char) * w;
    // printf("test tail_ptr - 1 [%s]\n", tail_ptr - sizeof(char));
    front_buf = BUF;
    last_pos = word + sizeof(char) * MAX_LEN;
}

int main(void){
    word = (char *) malloc(sizeof(char) * (MAX_LEN + 1));
    memset(word, '0', sizeof(char) * MAX_LEN);

    array = word + sizeof(char) * BUF;
    scanf("%s", array);
    last_pos = word + sizeof(char) * MAX_LEN;
    front_ptr = array;
    tail_ptr = word + sizeof(char) * strlen(word);

    // int line = 1;
    char cmd[40], parameters[2][1];
    while (scanf("%s", cmd) != EOF){
        if (!strcmp(cmd, "end"))
            break;
        if (!strcmp(cmd, "replace")){
            scanf("%s %s", parameters[0], parameters[1]);
            int arrayLen = strlen(array);
            for (int i = 0; i < arrayLen; ++i)
                if (array[i] == parameters[0][0])
                    array[i] = parameters[1][0];
        }
        else if (!strcmp(cmd, "remove")){
            scanf("%s", parameters[0]);
            int arrayLen = strlen(array);
            for (int i = 0; i < arrayLen; ++i){
                if (array[i] == parameters[0][0])
                    array[i] = '_'; // 之後一次一起清掉
            }
        }
        else if (!strcmp(cmd, "addhead")){
            scanf("%s", parameters[0]);
            if (!front_buf) // 重設陣列
                reset();
            --front_ptr;
            --front_buf;
            * front_ptr = parameters[0][0];
        }
        else if (!strcmp(cmd, "addtail")){
            scanf("%s", parameters[0]);
            if (tail_ptr == last_pos) // 重設陣列
                reset();
            * tail_ptr = parameters[0][0];
            ++tail_ptr;
            * tail_ptr = '\0';
        }
        else {
            // printf("at line : %d\n", line);
            printf("invalid command %s\n", cmd);
            return 0;
        }
        // ++line;
        // printf("test front [%s]\n", front_ptr);
    }
    /* print result */
    for (char * tmp = front_ptr; tmp != tail_ptr; ++tmp)
        if (* tmp != '_')
            putchar(* tmp);
    puts("");
}

