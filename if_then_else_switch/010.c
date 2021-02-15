# include <stdio.h>
int main(){
    int n, i, a = 1;
    scanf("%d%d", &n, &i);
    for (int j = 0; j < i; j++)
        a *= n;
    printf("%d", a);
}