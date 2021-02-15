/* 49. Sum, Maximum and Minimum */
# include <stdio.h>
int main(void){
    int N, m;
    scanf("%d%d", &N, &m);
    int nums[10000], compu[10000][4] = {0};
    /* init of compu */
    for (int i = 0; i < N; i++)
        compu[i][0] = i, compu[i][3] = 10000;
    for (int i = 0; i < N; i++){
        scanf("%d", &nums[i]);
        for (int j = 0; j < N; j++){
            if (nums[i] % m == compu[j][0]){
                compu[j][1] += nums[i];
                compu[j][2] = (compu[j][2] < nums[i]) ? nums[i] : compu[j][2];
                compu[j][3] = (compu[j][3] > nums[i]) ? nums[i] : compu[j][3];
            }
        }
    }
    for (int i = 0; i < m; i++)
        printf("%d %d %d\n", compu[i][1], compu[i][2], compu[i][3]);
}