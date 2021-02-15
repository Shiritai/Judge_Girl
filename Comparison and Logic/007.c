# include <stdio.h>
# include <stdbool.h>
int main(){
    int a;
    scanf("%d", &a);
    bool x = !(a % 3 == 0 && a % 5 == 0 && a % 7 != 0);
    printf("%d", x);
}