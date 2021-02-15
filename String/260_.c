/* 260. String Fusion */
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdbool.h>
# include <assert.h>
# define Len 128
// int min(int a, int b);
void fusion(char * a, char * b);
int main(void){
    char result[Len] = "", input[Len];
    // FILE * fp = fopen("test", "w");
    // assert(fp != NULL);
    while (scanf("%s", input) != EOF){
        fusion(result, input);
        // printf("%s\n", result);
    }
    // fprintf(fp, "%s\n", result);
    printf("%s", result);
    // fclose(fp);
}
void fusion(char * a, char * b){
    char * backPtr = b, * re_backPtr = a;
    char tmp[Len];
    strcpy(tmp, a);
    if (strlen(a) == 0){
        strcat(a, b);
        return;
    }
    // printf("a[] = %p\n", a);
    re_backPtr = strchr(a, b[0]);
    // printf("before: %p\n", re_backPtr);
    bool check = true;
    int check_last;
    for (; re_backPtr != NULL && * re_backPtr != '\0'; backPtr = b, check = true){
        if (*re_backPtr == *backPtr){
            /* if b is the last few chars of a */
            check_last = strlen(re_backPtr);
            if (strncmp(re_backPtr, b, check_last) == 0){
                b += check_last;
                strcat(re_backPtr, b);
                return;
            }
            /* check if they can fusion together */
            for (; * re_backPtr != '\0'; re_backPtr++, backPtr++){
                if (* re_backPtr != * backPtr){
                    check = false;
                    break;
                }
            }
            if (check){
                strcat(a, backPtr);
                // printf("a[] = %s\n", a);
            }
        }
        else{
            // printf("re_backPtr = %p\n", re_backPtr);
            re_backPtr = strchr(re_backPtr, b[0]);
            // printf("after re_backPtr = %p\n", re_backPtr);
        }
    }
    if (strcmp(tmp, a) == 0)
        strcat(a, b);
    return;
}
// int min(int a, int b){
//     return (a < b) ? a : b;
// }