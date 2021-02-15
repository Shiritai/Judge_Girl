/* 128. City Roads */
void intersection(int map[100][100], int result[4]){
    result[0] = 0;
    result[1] = 0;
    result[2] = 0;
    result[3] = 0;
    int cnt;
    for (int i = 0; i < 100; ++i){
        for (int j = 0; j < 100; ++j){
            if (map[i][j] == 1){
                cnt = 0;
                if (j - 1 >= 0)  if (map[i][j - 1] == 1) cnt += 4;   
                if (j + 1 < 100)  if (map[i][j + 1] == 1) cnt += 4;   
                if (i - 1 >= 0)  if (map[i - 1][j] == 1) cnt += 1;   
                if (i + 1 < 100)  if (map[i + 1][j] == 1) cnt += 1; 
                switch (cnt){
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
    return;
}