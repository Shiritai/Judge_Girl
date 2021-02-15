/* 14. Print the Sequence Backward */
# include <stdio.h>
int main(void){
    int num;
    int Arr[100000] = {0};
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
        scanf("%d", &Arr[i]);
    printf("%d", Arr[num-1]);
    for (int i = num-2; i >= 0; i--)
        printf(" %d", Arr[i]);
}