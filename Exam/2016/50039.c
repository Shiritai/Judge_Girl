/* 50039. Inner Product and Outer Product */
# include <stdio.h>
int main(void){
    int vec1[3] = {}, vec2[3] = {};
    scanf("%d%d%d%d%d%d", &vec1[0], &vec1[1], &vec1[2], &vec2[0], &vec2[1], &vec2[2]);
    printf("%d\n%d %d %d\n", vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2], vec1[1] * vec2[2] - vec1[2] * vec2[1], vec1[2] * vec2[0] - vec1[0] * vec2[2], vec1[0] * vec2[1] - vec1[1] * vec2[0]);
    return 0;
}