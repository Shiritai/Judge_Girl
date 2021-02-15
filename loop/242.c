/* 242. Three Circles */
# include <stdio.h>
# define sq(a) a*a
int main(){
    int cases = 0;
    scanf("%d", &cases);
    /* variables */
    int case_rec = cases;
    long long circle[3][3] = {0};
    int counter[] = {0};
    long long CooRange[2][2];
        /* take high coo */  // min 64 bit num, which is 9223372036854775807 in decimal
    CooRange[0][0] = 0x7fffffffffffffff, CooRange[0][1] = 0x7fffffffffffffff;
        /* take low coo */  // min 64 bit num, which is -9223372036854775808 in decimal
    CooRange[1][0] = 0x8000000000000000, CooRange[1][1] = 0x8000000000000000; 
    /* main */
    while (cases > 0){
        /* scan circles */
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                scanf("%lld", &circle[i][j]);
            }
        }
        /* determine some (x, y) one circle by one circle */
        /* find the range of (x, y) */
        for (int i = 0; i < 3; i++){
            /* take low */
            CooRange[0][0] = (CooRange[0][0] > circle[i][0] + circle[i][2]) ? (circle[i][0] + circle[i][2]) : CooRange[0][0];
            CooRange[0][0] = (CooRange[0][0] > circle[i][0] - circle[i][2]) ? (circle[i][0] - circle[i][2]) : CooRange[0][0];
            CooRange[0][1] = (CooRange[0][1] > circle[i][1] + circle[i][2]) ? (circle[i][1] + circle[i][2]) : CooRange[0][1];
            CooRange[0][1] = (CooRange[0][1] > circle[i][1] - circle[i][2]) ? (circle[i][1] - circle[i][2]) : CooRange[0][1];
            /* take high */
            CooRange[1][0] = (CooRange[1][0] < circle[i][0] + circle[i][2]) ? (circle[i][0] + circle[i][2]) : CooRange[1][0];
            CooRange[1][0] = (CooRange[1][0] < circle[i][0] - circle[i][2]) ? (circle[i][0] - circle[i][2]) : CooRange[1][0];
            CooRange[1][1] = (CooRange[1][1] < circle[i][1] + circle[i][2]) ? (circle[i][1] + circle[i][2]) : CooRange[1][1];
            CooRange[1][1] = (CooRange[1][1] < circle[i][1] - circle[i][2]) ? (circle[i][1] - circle[i][2]) : CooRange[1][1];
        }
        printf("init\n");
        for (int i = 0; i < 2; i++)
            printf("(%lld, %lld)\t", CooRange[i][0], CooRange[i][1]);
        printf("\n");
        int sq_radius[3] = {0};
        for (int i = 0; i < 3; i++)
            sq_radius[i] = sq(circle[0][i]);
        /* count the points in the domain */
        for (long long x = CooRange[0][0]; x <= CooRange[1][0]; x++){
            for (long long y = CooRange[0][1]; y <= CooRange[1][1]; y++){
                int sq_dx[3] = {sq(x-circle[0][0]), sq(x-circle[1][0]), sq(x-circle[2][0])};
                int sq_dy[3] = {sq(y-circle[0][1]), sq(y-circle[1][1]), sq(y-circle[2][1])};
                /* circle 0 */
                if (sq_dx[0] + sq_dy[0] <= sq_radius[0] \
                    && sq_dx[1] + sq_dy[1] > sq_radius[1] \
                    && sq_dx[2] + sq_dy[2] > sq_radius[2])
                        counter[cases]++, printf("C0\t(%lld, %lld)\n", x, y);
                /* circle 1 */
                else if (sq_dx[0] + sq_dy[0] > sq_radius[0] \
                    && sq_dx[1] + sq_dy[1] <= sq_radius[1] \
                    && sq_dx[2] + sq_dy[2] > sq_radius[2])
                        counter[cases]++, printf("C1\t(%lld, %lld)\n", x, y);
                /* circle 2 */
                else if (sq_dx[0] + sq_dy[0] > sq_radius[0] \
                    && sq_dx[1] + sq_dy[1] > sq_radius[1] \
                    && sq_dx[2] + sq_dy[2] <= sq_radius[2])
                        counter[cases]++, printf("C2\t(%lld, %lld)\n", x, y);
                /* 3 circles */
                else if (sq_dx[0] + sq_dy[0] <= sq_radius[0] \
                    && sq_dx[1] + sq_dy[1] <= sq_radius[1] \
                    && sq_dx[2] + sq_dy[2] <= sq_radius[2])
                        counter[cases]++, printf("ALL\t(%lld, %lld)\n", x, y);
            }
        }
        cases--;
    }
    for (int i = case_rec; i > 0; i--)
        printf("%d\n", counter[i]);
}