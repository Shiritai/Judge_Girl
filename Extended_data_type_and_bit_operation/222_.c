/* 222. Bookshelf */
# include <stdio.h>
int main(void){
    short near[8] = {}, cur;
    while (scanf("%hd", &cur) != EOF && cur != -1){
        int flag = 1;
        for (int i = 0; i < 8 && flag; ++i){
            if (cur == near[i]){
                for (int j = i; j >= 0; --j){
                    near[j] = near[j-1];
                }
                near[0] = cur;
                flag = 0;
            }
        }
        if (flag) { // DNE in near shelf
            for (int i = 7; i >= 0; --i){
                near[i] = near[i-1];
            }
            near[0] = cur;
        }
    }
    printf("%hd", near[7]);
    for (int i = 6; i >= 0; --i){
        printf(" %hd", near[i]);
    }
    printf("\n");
    return 0;
}