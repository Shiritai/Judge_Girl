/* 50040. Magic Number */
# include <stdio.h>
int main(void){
    int m;
    scanf("%d", &m);
    printf("%d\n", !(m & 1) && (m > 10000 || m < 1000) && m > 0);
}