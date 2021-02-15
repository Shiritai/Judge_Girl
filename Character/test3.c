# include <stdio.h>
int main(void){
    char str[100];
    while (fgets(str, 0x7fffffff, stdin)){
        printf("%s", str);
    }
    
}