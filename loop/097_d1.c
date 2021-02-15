/* 97. Bicycle and Parking Lot */
# include <stdio.h>
# include <stdlib.h>
int main(){
    /* read data */
    /* input parking lot */
    int n;
    scanf("%d", &n);
    /* X[], Y[] be the coordinate of the parking lots */
    int X[n], Y[n], capacity[n];
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &(X[i]), &(Y[i]), &(capacity[i]));
    /* input illegal bicycle */
    int m;
    scanf("%d", &m);
    int x[m], y[m];
    for (int i = 0; i < m; i++)
        scanf("%d%d", &(x[i]), &(y[i]));
    /* place bikes */
    int distance[10] = {0}; // decide where to put bike
    int pointer[10][10] = {0};  // first dimension is the num of the bike
                        // second dimension is the num of its nearer lot, from 0 to n
    /* 對每組座標分析要分到哪裡 */
    int num[10] = {0}; // num of each parking lots
    for (int i = 0; i < m; i++){
        printf("___________No.%d bike's term___________\n", i);
        /* compute distance */
        for (int j = 0; j < n; j++){
            distance[j] = abs(x[i] - X[j]) + abs(y[i] - Y[j]);
        //_________________________________________________
            printf("distance[%d] = %d\n", j, distance[j]);
        //_________________________________________________
        }
        /* determine the lower distance 傳遞給 pointer */
        for (int k = 0; k < n; k++){
            pointer[i][k] = 0;
            for (int j = 1; j < n; j++){
                if (distance[k] > distance[j])
                    pointer[i][k] = j;
                else if (k != j && distance[k] == distance[j]){
                    pointer[i][k] = (x[k] < x[j])? k:j; 
                }
                else if (k == j){
                    printf("k == j, No.%d\n", k);
                }
            }
        }
        for (int k = 0; k < n; k++){
            printf("pointer[%d][%d] = %d\n", i, k, pointer[i][k]);
        }
        /* park the bike */
        for (int k = 0; k < n; k++){
            if (num[pointer[i][k]] == capacity[pointer[i][k]]){
                continue;
            }
            else if (num[pointer[i][k]] < capacity[pointer[i][k]])
                num[pointer[i][k]]++;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", num[i]);
}
/*
//_________________________________________________
printf("\n", );
//_________________________________________________
*/