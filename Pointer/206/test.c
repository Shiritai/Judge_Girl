/* 128. City Roads */
# include <stdio.h>
# define size 109
int main(void){
    int cnt = 0, i;
    int matrix[size] = {0};
    int* deck[size+1];
    for (i = 0; i < size; i++)
        deck[i] = &(matrix[i]);
    deck[size] = NULL;
    for (i = 0; i < 10000, deck[i] != NULL; i++, cnt++); // test this
    printf("%d", cnt);
}