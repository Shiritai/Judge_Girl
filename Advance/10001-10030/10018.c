/* 10018. Find a Duplicate Number (Special Judge) */
# include <stdio.h> 
# define Len 100000
int main(void){
    static int numList[Len] = {0};
    int num, tmp;
    scanf("%d", &num);
    for (int i = 0; i < num; i++){
        scanf("%d", &tmp);
        if (numList[tmp] == 0)
            numList[tmp] = 1;
        else {
            printf("%d\n", tmp);
            return 0;
        }
    }
    return 0;
}