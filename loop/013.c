/* 13. Print a Repeated Pattern */
# include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j <= i; j++)
            printf("%d", j);
    }
}