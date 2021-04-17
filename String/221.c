/* 221. Typesetting  */
# include <stdio.h>
# include <string.h>
# include <assert.h>

int main(void){
    int line_len, buf_len = 0, buf_order = 0;
    scanf("%d", &line_len);
    char buf[256][256], word[256];
    while (scanf("%s", word) != EOF){
        // if (!strcmp(word, "-1")){
        //     int diff = line_len - buf_len - (--buf_order); // 需要訪問 buf[0 ~ buf_order]
        //     for (int i = 0; i < buf_order; ++i){ // 訪問到倒數第二個, i.e. buf[buf_order - 1]
        //         printf("%s ", buf[i]);
        //         if (i < diff % buf_order){ // diff / order 需要將作為餘數的空白印出
        //             for (int j = 0; j < diff / buf_order + 1; ++j){
        //                 putchar(' ');
        //             }
        //         }
        //         else {
        //             for (int j = 0; j < diff / buf_order; ++j){
        //                 putchar(' ');
        //             }
        //         }
        //     }
        //     printf("%s\n", buf[buf_order]);
        //     return 0;
        // }
        // if (!strcmp(word, "peek")){
        //     printf("current buf : [%s]\n", buf[buf_order - 1]);
        //     printf("buf order : [%d]\n", buf_order);
        //     printf("buf length : [%d]\n", buf_len);
        //     continue;
        // }
        int word_len = strlen(word);
        /* 印出 */
        if (buf_len + word_len + buf_order > line_len){
            if (buf_order == 1){
                printf("%s", buf[0]);
                for (int i = 0; i < line_len - buf_len; ++i)
                    putchar(' ');
                puts("");
            }
            else {
                int diff = line_len - buf_len - (--buf_order); // 需要訪問 buf[0 ~ buf_order]
                for (int i = 0; i < buf_order; ++i){ // 訪問到倒數第二個, i.e. buf[buf_order - 1]
                    printf("%s ", buf[i]);
                    if (i < diff % buf_order){ // diff / order 需要將作為餘數的空白印出
                        for (int j = 0; j < diff / buf_order + 1; ++j){
                            putchar(' ');
                        }
                    }
                    else {
                        for (int j = 0; j < diff / buf_order; ++j){
                            putchar(' ');
                        }
                    }
                }
                printf("%s\n", buf[buf_order]);
            }
            buf_len = 0;
            buf_order = 0;
        }
        if (buf_len + word_len + buf_order <= line_len){ // buf_order 同時表達間格數與階數
            strcpy(buf[buf_order++], word);
            buf_len += word_len;
            // sprintf(buf, "%s %s", buf, word);
        }
    }
    if (buf_order == 1){
        printf("%s", buf[0]);
        for (int i = 0; i < line_len - buf_len; ++i)
            putchar(' ');
        puts("");
    }
    else {
        int diff = line_len - buf_len - (--buf_order); // 需要訪問 buf[0 ~ buf_order]
        for (int i = 0; i < buf_order; ++i){ // 訪問到倒數第二個, i.e. buf[buf_order - 1]
            printf("%s ", buf[i]);
            if (i < diff % buf_order){ // diff / order 需要將作為餘數的空白印出
                for (int j = 0; j < diff / buf_order + 1; ++j){
                    putchar(' ');
                }
            }
            else {
                for (int j = 0; j < diff / buf_order; ++j){
                    putchar(' ');
                }
            }
        }
        printf("%s\n", buf[buf_order]);
    }
}