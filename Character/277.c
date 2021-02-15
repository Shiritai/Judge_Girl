/* 277. Digits */
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <assert.h>
int main(void){
    char input[10];
    int width, height, line, len;
    while (scanf("%s%d%d", input, &width, &height) == 3){
        assert(height & 1);
        len = strlen(input);
        for (line = 0; line < height; ++line){
            if (line == 0){
                for (int i = 0; i < len; ++i){
                    printf(" ");
                    for (int j = width-3; j > 0; --j){
                        if (input[i] != '1' && input[i] != '4')
                            printf("%c", input[i]);
                        else 
                            printf(" ");
                    }
                    printf("  ");
                }
                puts("");
            }
            else if (line == height-1){
                for (int i = 0; i < len; ++i){
                    printf(" ");
                    for (int j = width-3; j > 0; --j){
                        if (input[i] != '1' && input[i] != '4' && input[i] != '7' && input[i] != '9')
                            printf("%c", input[i]);
                        else 
                            printf(" ");
                    }
                    printf("  ");
                }
                puts("");
            }
            else if (line == height/2){
                for (int i = 0; i < len; ++i){
                    printf(" ");
                    for (int j = width-3; j > 0; --j){
                        if (input[i] != '0' && input[i] != '1' && input[i] != '7')
                            printf("%c", input[i]);
                        else 
                            printf(" ");
                    }
                    printf("  ");
                }
                puts("");
            }
            else if (line < height/2){
                for (int i = 0; i < len; ++i){
                    switch (input[i]){
                        case '0': case '4': case '7': case '8': case '9':{
                            printf("%c", input[i]);
                            for (int j = width - 3; j > 0; --j)
                                printf(" ");
                            printf("%c ", input[i]);
                            break;
                        }
                        case '1': case '2': case '3':{
                            for (int j = width - 2; j > 0; --j)
                                printf(" ");
                            printf("%c ", input[i]);
                            break;
                        }
                        case '5': case '6':{
                            printf("%c", input[i]);
                            for (int j = width - 1; j > 0; --j)
                                printf(" ");
                            break;
                        }
                        default:
                            break;
                    }
                }
                puts("");
            }
            else {
                for (int i = 0; i < len; ++i){
                    switch (input[i]){
                        case '0': case '6': case '8':{
                            printf("%c", input[i]);
                            for (int j = width - 3; j > 0; --j)
                                printf(" ");
                            printf("%c ", input[i]);
                            break;
                        }
                        case '1': case '3': case '4': case '5': case '7': case '9':{
                            for (int j = width - 2; j > 0; --j)
                                printf(" ");
                            printf("%c ", input[i]);
                            break;
                        }
                        case '2':{
                            printf("%c", input[i]);
                            for (int j = width - 1; j > 0; --j)
                                printf(" ");
                            break;
                        }
                        default:
                            break;
                    }
                    
                }
                puts("");
            }
        }
    }
    return 0;
}