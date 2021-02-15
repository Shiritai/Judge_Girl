# include <stdio.h>
# include <ctype.h>

int test(int x){
    printf("%d\n", x);
}
int main(void){
    // test(2);
    printf("%d %d %d %d %d\n", isalnum('('), isspace('('), isdigit('('), isascii('('), iscntrl('('));
}