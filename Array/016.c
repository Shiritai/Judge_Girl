/* 16. Even and Odd */
# include <stdio.h>
int main(void){
    int num;
    int Arr[1000] = {0};
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
        scanf("%d", &Arr[i]);
    int Odd[1000] = {0}, Even[1000] = {0};
    int odd_num = 0, even_num = 0;
    for (int i = 0; i < num; i++){
        if (Arr[i] % 2 == 1){ // odd
            Odd[odd_num] = Arr[i];
            odd_num++;
        }
        else {
            Even[even_num] = Arr[i];
            even_num++;
        }
    }
    printf("%d", Odd[0]);
    for (int i = 1; i < odd_num; i++)
        printf(" %d", Odd[i]);
    printf("\n%d", Even[0]);
    for (int i = 1; i < even_num; i++)
        printf(" %d", Even[i]);
}