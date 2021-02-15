/* 238. Subset Sum */
# include <stdio.h>
// # include <stdbool.h>
# define SETLEN 15
static int N, set[SETLEN] = {0}, list[SETLEN*10] = {0}; // const
void make_list(int, int); // 概念 取與不取, need 1. sum of before  2. index
int main(void){
    int i, tmp;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &set[i]);
    make_list(0, 0);
    while (scanf("%d", &tmp) != EOF){
        printf("%d\n", list[tmp]);
    }
    return 0;
}
void make_list(int sum, int index){
    /* terminate */
    if (index == N){
        list[sum]++;
        return;
    }
    /* recur */
    make_list(sum+set[index], index+1);
    make_list(sum, index+1);
}