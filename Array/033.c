/* 33. Intersections */
# include <stdio.h>
int main(void){
    int edge;
    scanf("%d", &edge);
    /* make the city which real edge is consist of 0 */
    int city[102][102] = {0};
    int counter[4] = {0};
    for (int i = 1; i < edge+1; i++){
        for (int j = 1; j < edge+1; j++)
            scanf("%d", &city[i][j]);
    }
    for (int i = 1; i < edge+1; i++){
        for (int j = 1; j < edge+1; j++){
            if (city[i][j] == 1){
                /* special */
                switch (city[i+1][j] + city[i-1][j] + 4 * (city[i][j+1] + city[i][j-1]))
                {
                case 10:
                    counter[0]++;
                    break;
                case 6: case 9:
                    counter[1]++;
                    break;
                case 5:
                    counter[2]++;
                    break;
                case 1: case 4:
                    counter[3]++;
                    break;
                default:
                    break;
                } 
            }
        }
    }
    for (int i = 0; i < 4; i++)
        printf("%d\n", counter[i]);
}