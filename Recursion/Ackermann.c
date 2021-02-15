/* Ackermann func.: generate big numbers */
# include <stdio.h>
# include <stdint.h>
# include <assert.h>
int64_t ack(int a, int b);
int main(void){
    int a, b;
    scanf("%d%d", &a, &b);
    assert(a >= 0 && b >= 0);
    fprintf(stdout, "%lld", ack(a, b));
}
int64_t ack(int a, int b){
    if (a == 0)
        return b+1;
    else if (a > 0 && b == 0)
        return ack(a-1, 1);
    else if (a > 0 && b > 0)
        return ack(a-1, ack(a, b-1));
    else{
        printf("Error\n");
        return -1;
    }
}