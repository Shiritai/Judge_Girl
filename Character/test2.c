#include <stdio.h>
int main(){
    char num[100];
    scanf("%s", &num);
    int cnt;
    for (cnt = 0; num[cnt] != '\0'; cnt++);
    if (!(num[cnt-1] % 2))
        printf("2's\n");
    else if (!(num[cnt-1] % 5))
        printf("5's\n");
    else if (num[cnt-1] < 45 || num[cnt-1] > 57)
        printf("Not a num\n");
}