# include <stdio.h>
int main(void){
    char tmp;
    do
    {
        scanf("%c", &tmp);
    } while (tmp == ' ' || tmp == '\n');
    printf("%c", tmp);
}