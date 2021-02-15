/* 128. City Roads */
# include <stdio.h>
void intersection(int map[100][100], int result[4]){
    for (int i = 0; i < 4; i++)
        result[i] = 0;
    int flag;
    /* within the edge of the city */
    for (int i = 1; i < 99; i++){
        for (int j = 1; j < 99; j++){
            flag = 4 * map[i+1][j] + 4 * map[i-1][j] + map[i][j+1] + map[i][j-1];
            if(map[i][j] == 1){
                switch (flag){
                case 10:
                    result[0]++;
                    break;
                case 6: case 9:
                    result[1]++;
                    break;
                case 5:
                    result[2]++;
                    break;
                case 1: case 4:
                    result[3]++;
                    break;
                default:
                    break;
                }
            }
        }
    }
    /* edge, except four corners */
    for (int i = 1; i < 99; i++){
        for (int j = 0; j < 100; j+=99){
            if (map[i][j] == 1){
                flag = map[i-1][j] + map[i+1][j] + 3 * map[i][(j == 0) ? 1 : 98];
                switch (flag){
                case 5:
                    result[1]++;
                    break;
                case 4:
                    result[2]++;
                    break;
                case 1: case 3:
                    result[2]++;
                    break;
                default:
                    break;
                }
            }
            if (map[j][i] == 1){
                flag = map[j][i-1] + map[j][i+1] + 3 * map[(j == 0) ? 1 : 98][i];
                switch (flag){
                case 5:
                    result[1]++;
                    break;
                case 4:
                    result[2]++;
                    break;
                case 1: case 3:
                    result[2]++;
                    break;
                default:
                    break;
                }
            }
        }
    }
    /* four corners */
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            if (map[99*i][99*j] == 1){
                flag = 2*map[99*i][(j == 0) ? 1:98] + map[(i == 0) ? 1:98][99*j];
                switch (flag)
                {
                case 3:
                    result[2]++;
                    break;
                case 1: case 2:
                    result[3]++;
                    break;
                default:
                    break;
                }
            }
        }
    }
}