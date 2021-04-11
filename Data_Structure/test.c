# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <assert.h>

/* replace the repStr in str with repInt */
void replace(char * str, char * repStr, int repInt, char * destination){
    memset(destination, 0, strlen(destination));
    char * target = strstr(str, repStr);
    assert(target != NULL);
    int i = 0;
    while (str + i != target)
        destination[i] = str[i], i++;
    while (str[i] != ' ')
        ++i;
    sprintf(destination, "%s%d%s", destination, repInt, str + i);
}

int main(void){
    // test(2);
    // char tmp[100] = "x_Meow21_456 = 110", * tmpPtr = tmp;
    char tmp[1000] = "Meow?";
    replace("( + 4 x_Meow )", "x_Meow", 100, tmp);
    puts(tmp);
}