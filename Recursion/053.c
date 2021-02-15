/* 53. Permutation */
# include <stdio.h>
# define num 9
static int i, N; // for for loop and whole range access
void P(int, int*);
int main(void){
    int set[num], * setPtr = &set;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &set[i]);
    P(N, setPtr);
    return 0;
}
void P(int range, int* list){
    
}