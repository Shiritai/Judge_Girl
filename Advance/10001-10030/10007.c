/* 10007. Count of Segments */
# include <stdio.h>
# include <stdbool.h>
# include <string.h> // strlen()
int main(void){
    int num = 0, cnt, swt;
    char input[1024];
    while(scanf("%d\n", &num) != EOF){
        fgets(input, 0x7fffffff, stdin);
        cnt = 1;
        swt = input[0] - '0';
        for (int i = 2; i < (int) strlen(input); i+=2){
            if ((input[i] - '0') != swt){
                ++cnt;
                swt = !swt;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}