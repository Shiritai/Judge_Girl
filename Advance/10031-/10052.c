/* 10052. Expected Value Syntax Parser */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <assert.h>
# define fDfS fourDiscardfiveSave
char string[10000];
double parser(char * ptr, int last_index);
double fourDiscardfiveSave(double x){
    if (((int) (1000 * x)) % 10 >= 5)
        return ((int) (100 * x + 1)) / 100.0;
    else 
        return ((int) (100 * x)) / 100.0;
}
int main(void){
    while (fgets(string, 0x7fffffff, stdin)){
        string[(int) (strlen(string)-1)] = '\0';
        puts(string);
        printf("%.2f\n", fDfS(parser(string, (int) strlen(string))));
    }    
    return 0;
}
double parser(char * ptr, int last_index){
    printf("> call parser with\n> string : \"%s\", last_index : %d\n", ptr, last_index);
    if (isdigit(* ptr)){
        printf("> tmp result : \"%s\" --> %f\n", ptr, atof(ptr));
        return atof(ptr);
    }
    else { // split to three elements
        int pos = 0, left = 0, cnt;

        puts(">> find p");
        /* find p */
        while (ptr[pos] != ' ')    ++pos;
        char tmP[100];
        strncpy(tmP, ptr+1, pos-1);
        tmP[pos] = '\0'; // 註解掉試試
        double p = atof(tmP), expr1, expr2;
        printf(">>> p : \"%s\" --> %f\n", tmP, p);

        puts(">> find expr1");
        /* find parser(expr1) */
        ++pos; // ptr[pos] == '(' || ptr[pos] == number[0]
        if (isdigit(ptr[pos]) || ptr[pos] == '.' || ptr[pos] == '-'){
            for (left = pos; ptr[pos] != ' ' && ptr[pos] != ')'; ++pos)   printf(">>>> pos : [%d] --> %c\n", pos, ptr[pos]);
            strncpy(tmP, ptr+left, pos-left);
            tmP[pos-left] = '\0'; // 註解掉試試
            expr1 = atof(tmP);
            printf(">>> expr1 (dir) : \"%s\" --> %f\n", tmP, expr1);
        }
        else {
            assert(ptr[pos] == '('); // 註解掉試試
            for (left = pos, cnt = 0; !(cnt == 1 && ptr[pos] == ')'); ++pos){
                if (ptr[pos] == '(')
                    ++cnt;
                else if (ptr[pos] == ')')
                    --cnt;
            }
            strncpy(tmP, ptr+left, pos-left+1);
            tmP[pos-left+1] = '\0';
            expr1 = parser(tmP, pos - left);
            printf(">>> expr1 (call) : \"%s\" --> %f\n", tmP, expr1);
            ++pos;
        }
        puts(">> find expr2");
        /* find parser(expr2) */
        ++pos; // ptr[pos] == '(' || ptr[pos] == number[0]
        if (isdigit(ptr[pos]) || ptr[pos] == '.' || ptr[pos] == '-'){
            for (left = pos; ptr[pos] != ' ' && ptr[pos] != ')'; ++pos)   printf(">>>> pos : [%d] --> %c\n", pos, ptr[pos]);
            strncpy(tmP, ptr+left, pos-left);
            tmP[pos-left] = '\0'; // 註解掉試試
            expr2 = atof(tmP);
            printf(">>> expr2 (dir) : \"%s\" --> %f\n", tmP, expr2);
        }
        else {
            assert(ptr[pos] == '('); // 註解掉試試
            for (left = pos, cnt = 0; !(cnt == 1 && ptr[pos] == ')'); ++pos){
                if (ptr[pos] == '(')
                    ++cnt;
                else if (ptr[pos] == ')')
                    --cnt;
            }
            strncpy(tmP, ptr+left, pos-left+1);
            tmP[pos-left+1] = '\0';
            expr2 = parser(tmP, pos - left);
            printf(">>> expr2 (call) : \"%s\" --> %f\n", tmP, expr2);
        }

        /* return combined result */
        puts("> ------------------------------");
        return p * (expr1 + expr2) + (1 - p) * (expr1 - expr2);
    }
}