/* 50010. Word Editor */
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define BUF 1024
# define MAX_LEN 16384

static char * word, * array, * front_ptr, * tail_ptr, * last_pos, * newWord;
int front_buf = BUF;

void reset(){
    newWord = (char *) malloc(sizeof(char) * MAX_LEN);
    memset(newWord, '0', sizeof(char) * MAX_LEN);
    int wordLen = strlen(word);
    int w = BUF;
    for (int i = 0; i < wordLen; ++i){
        if (word[i] != '_')
            newWord[w++] = word[i];
    }
    newWord[w] = '\0';
    free(word);
    word = newWord;
    array = word + sizeof(char) * BUF;
    front_ptr = array;
    tail_ptr = word + sizeof(char) * w;
    // printf("test tail_ptr - 2 [%s]\n", tail_ptr - sizeof(char) * 2);
    front_buf = BUF;
    last_pos = word + sizeof(char) * MAX_LEN;
    
}

int main(void){
    word = (char *) malloc(sizeof(char) * MAX_LEN);
    char cmd[400], parameters[2][1];
    memset(word, '0', sizeof(char) * MAX_LEN);
    array = word + sizeof(char) * BUF;
    last_pos = word + sizeof(char) * MAX_LEN;

    front_ptr = array;

    scanf("%s", array);

    tail_ptr = word + sizeof(char) * strlen(word);
    // puts(word);
    // puts(array);
    // int line = 1;
    while (scanf("%s", cmd) != EOF){
        if (!strcmp(cmd, "end"))
            break;
        int arrayLen = strlen(array);
        if (!strcmp(cmd, "replace")){
            scanf("%s %s", parameters[0], parameters[1]);
            for (int i = 0; i < arrayLen; ++i)
                if (array[i] == parameters[0][0])
                    array[i] = parameters[1][0];
        }
        else if (!strcmp(cmd, "remove")){
            scanf("%s", parameters[0]);
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

