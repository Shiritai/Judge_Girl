/* 10052. Expected Value Syntax Parser */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <assert.h>
# define DS fourDiscardfiveSave
char string[10000];
double parser(char * ptr, int last_index);
double fourDiscardfiveSave(double x){
    double tmp = (x > 0) ? x : -x;
    int sig = (x > 0) ? 1 : -1;
    if (((int) (1000 * tmp)) % 10 >= 5)
        return sig * ((int) (100 * tmp + 1)) / 100.0;
    else 
        return sig * ((int) (100 * tmp)) / 100.0;
}
int main(void){
    while (fgets(string, 0x7fffffff, stdin)){
        string[(int) (strlen(string)-1)] = '\0';
        printf("%.2f\n", DS(parser(string, (int) strlen(string))));
    }    
    return 0;
}
double parser(char * ptr, int last_index){
    if (isdigit(* ptr))
        return DS(atof(ptr));
    else { // split to three elements
        int pos = 0, left = 0, cnt;
        double p, expr1, expr2;
        char tmP[100];

        /* find p */
        while (ptr[pos] != ' ')    ++pos;
        strncpy(tmP, ptr+1, pos-1);
        tmP[pos] = '\0';
        p = atof(tmP);

        /* find parser(expr1) */
        ++pos; // ptr[pos] == '(' || ptr[pos] == number[0]
        if (isdigit(ptr[pos]) || ptr[pos] == '.' || ptr[pos] == '-'){
            for (left = pos; ptr[pos] != ' ' && ptr[pos] != ')'; ++pos);
            strncpy(tmP, ptr+left, pos-left);
            tmP[pos-left] = '\0';
            expr1 = atof(tmP);
        }
        else {
            assert(ptr[pos] == '(');
            for (left = pos, cnt = 0; !(cnt == 1 && ptr[pos] == ')'); ++pos){
                if (ptr[pos] == '(')
                    ++cnt;
                else if (ptr[pos] == ')')
                    --cnt;
            }
            strncpy(tmP, ptr+left, pos-left+1);
            tmP[pos-left+1] = '\0';
            expr1 = parser(tmP, pos - left);
            ++pos;
        }

        /* find parser(expr2) */
        ++pos; // ptr[pos] == '(' || ptr[pos] == number[0]
        if (isdigit(ptr[pos]) || ptr[pos] == '.' || ptr[pos] == '-'){
            for (left = pos; ptr[pos] != ' ' && ptr[pos] != ')'; ++pos);
            strncpy(tmP, ptr+left, pos-left);
            tmP[pos-left] = '\0';
            expr2 = atof(tmP);
        }
        else {
            assert(ptr[pos] == '(');
            for (left = pos, cnt = 0; !(cnt == 1 && ptr[pos] == ')'); ++pos){
                if (ptr[pos] == '(')
                    ++cnt;
                else if (ptr[pos] == ')')
                    --cnt;
            }
            strncpy(tmP, ptr+left, pos-left+1);
            tmP[pos-left+1] = '\0';
            expr2 = parser(tmP, pos - left);
        }

        /* return combined result */
        return DS(p * (expr1 + expr2) + (1 - p) * (expr1 - expr2));
    }
}