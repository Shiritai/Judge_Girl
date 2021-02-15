/* 10045. Function Invocation */
# include <stdio.h>
int f(int x);
int g(int x);
int h(int x);
int main(void){
    int tmp;
    scanf("%d", &tmp);
    printf("%d\n", f(tmp));
    return 0;
}
int f(int x){
    int tmp = x-h(x);
    if (tmp > 0)
        return f(x-1) - h(x);
    else if (tmp < 0)
        return f(g(x)) - g(x);
    else
        return 1;
}
int g(int x){
    if (x <= 2)
        return x*x-1;
    else 
        return 2;
}
int h(int x){
    if (x < 2)
        return -1;
    else 
        return 2 + h(x-1) - h(x-2);
}