# include <stdio.h>
# define sq(x) x*x
void demo (int* b){
    for (int i = 0; i < 3; i++)
        ++b[i];
}
int main (){
    // char str[10] = {'m', 'a', 'i', 'n', '{', '\n', '\n', '}'};
    // printf("%s", str);
    char cha = '\0';
    scanf("%c", &cha);
    printf("the %c's ASCII Code is : %d", cha, cha);
}