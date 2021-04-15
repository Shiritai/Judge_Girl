# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <assert.h>

/* replace the repStr in source with repInt */
void replace(char * source, char * repStr, int repInt, char * destination){
    char * buf = (char *) malloc(sizeof(char) * strlen(destination));
    char * target = strstr(source, repStr);
    assert(target != NULL);
    int i = 0;
    while (source + i != target)
        buf[i] = source[i], i++;
    buf[strlen(buf) - 1] = '\0'; // 記得下斷點，這樣 sprintf 才知道要讀到哪
    while (source[i] != ' ')
        ++i;
    sprintf(buf, "%s %d%s", buf, repInt, source + i);
    strcpy(destination, buf);
}

int main(void){
    // test(2);
    // char tmp[100] = "x_Meow2 = 110", * tmpPtr = tmp;
    // char tmp[1000] = "Meow?";
    char tmp[1000] = "( + _01234567890abcdefghijklmnopqrst ( + _01234567890abcdefghijklmnopqrst ( + _01234567890abcdefghijklmnopqrst ( + _01234567890abcdefghijklmnopqrst ( + _01234567890abcdefghijklmnopqrst ( + _01234567890abcdefghijklmnopqrst ( + _01234567890abcdefghijklmnopqrst ( + _01234567890abcdefghijklmnopqrst ( + _01234567890abcdefghijklmnopqrst ( + _01234567890abcdefghijklmnopqrst _01234567890abcdefghijklmnopqrst ) ) ) ) ) ) ) ) ) )";
    int val;
    char var[64];
    sscanf("_01234567890abcdefghijklmnopqrst = 3\n", "%s = %d", var, &val);
    puts(var);
    while (strstr(tmp, var) != NULL)
        replace(tmp, var, val, tmp);
    // char tmp[1000] = "( + 4 x_Meow )";
    // replace(tmp, "x_Meow", 100, tmp);
    puts(tmp);
    // char tmp[100] = "123 eroiko, 124iwhrl8\n";
    // int val = 0;

    // sscanf(tmp, "%d", &val);
    // printf("%d\n", val);
}