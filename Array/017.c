/* 17. Column Average */
# include <stdio.h>
int main(void){
    int Row, Col;
    scanf("%d%d", &Row, &Col);
    int Matrix[2000] = {0};
    for (int i = 0; i < Row; i++){
        for (int j = Col; j < 2*Col; j++){
            scanf("%d", &Matrix[j]);
            Matrix[j-Col] += Matrix[j];
        }
    }
    for (int i = 0; i < Col; i++)
        printf("%d\n", Matrix[i]/Row);
}