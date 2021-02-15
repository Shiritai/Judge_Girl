/* 128. City Roads */
# include <stdio.h>
void intersection(int map[100][100], int result[4]){
    for (int i = 0; i < 4; i++)
        result[i] = 0;
    int ext_map[102][102] = {0};
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++)
            ext_map[i+1][j+1] = map[i][j];
    }
    int flag;
    for (int i = 1; i < 101; i++){
        for (int j = 1; j < 101; j++){
            if (map[i][j] == 1){
                flag = 4 * ext_map[i+1][j] + 4 * ext_map[i-1][j] + ext_map[i][j+1] + ext_map[i][j-1];
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
}