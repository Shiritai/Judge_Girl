/* 10019. String Trim (Presentation Error) */
# include <stdio.h>
# include <ctype.h>
# define Len 1000000
char * erase_space(char * str);
int main(void){
    static char source[Len] = "";
    while (fgets(source, 0x7fffffff, stdin)){
        char *q = erase_space(source);
        puts(q); // puts() will print a string until '\0' and automatically add a '\n' at the end
        // printf("%s", q); // both print method is ok
    }
    return 0;
}
char * erase_space(char * str){
    char * trimPtr = str;
    /* cut front space */
    while (isspace(*str)) // i.e. skip the spaces
        str++;
    /* cut back space */
    for (;*trimPtr;trimPtr++); // move to str's back
    trimPtr--;
    while (isspace(*trimPtr)) // replace spaces to '\0'
        *trimPtr = '\0', trimPtr--;
    return str;
}