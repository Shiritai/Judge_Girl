# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# define fDfS fourDiscardfiveSave
double fourDiscardfiveSave(double x){
    if (((int) (1000 * x)) % 10 >= 5)
        return ((int) (100 * x + 1)) / 100.0;
    else 
        return ((int) (100 * x)) / 100.0;
}
char string[10];
int main(void){
    // strcpy(string, "123");
    // printf("%d\n", (int) strlen(string)); 
    // strcpy(string, "1234");
    // printf("%d\n", (int) strlen(string)); 
    printf("%f\n", fDfS(1.125));
    // char * str1 = "Eroiko", * str2 = "Eroiko_";
    // printf("%d\n", strcmp(str1, str2));
    // int *ptr = NULL;
    // printf("%p\n", ptr);
    // char str1[10] = "Meow", str2[10];
    // sprintf(str2, "%s", str1);
    // puts(str2);
    // printf("%d", isspace('1'));
    // int tmp = 0, tmp2;
    // ++tmp, tmp2 = tmp;
    // tmp++, tmp2 = tmp;
    // tmp2 = tmp, ++tmp;
    // int str = strlen(".1");
    // printf("%.5llf\n", atof(".12"));
}