# include <stdio.h>
# include <stdbool.h>
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    bool x = (a+b>c && b+c>a && a+c>b);
    printf("%d", x);
}