/* 242. Three Circles */
# include <stdio.h>
# define sq(a) a*a
int main(){
    int cases = 0;
    scanf("%d", &cases);
    /* variables */
    int case_rec = cases;
    long long int circle[3][3] = {0};
    int counter[] = {0};
    int cut_temp = 0;
    /* main */
    while (cases > 0){
        /* scan circles */
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                scanf("%d", &circle[i][j]);
            }
        }
        /* determine some (x, y) one by one circle */
        /* which is the square with each side = radius */
        for (int i = 0; i < 3; i++){
            for (long long int x = circle[i][0] - circle[i][2]; x <= circle[i][0] + circle[i][2]; x++){
                for (long long int y = circle[i][1] - circle[i][2]; y <= circle[i][1] + circle[i][2]; y++){
                    /* (x, y) that inside one circle */
                    if (sq(x - circle[i][0]) + sq(y - circle[i][1]) <= sq(circle[i][2])){
                        /* (x, y) is inside the other two circles */
                        if (i == 0){
                            if (sq(x - circle[1][0]) + sq(y - circle[1][1]) < sq(circle[1][2]) && 
                                sq(x - circle[2][0]) + sq(y - circle[2][1]) < sq(circle[2][2]))
                                    counter[cases]++, cut_temp = 1, printf("0\t(%lld, %lld)\n", x, y);
                            else if (sq(x - circle[1][0]) + sq(y - circle[1][1]) > sq(circle[1][2]) && 
                                sq(x - circle[2][0]) + sq(y - circle[2][1]) > sq(circle[2][2]))
                                    counter[cases]++, cut_temp = 1, printf("0\t(%lld, %lld)\n", x, y);
                        }
                        else if (i == 1){
                            if (sq(x - circle[0][0]) + sq(y - circle[0][1]) < sq(circle[0][2]) && 
                                sq(x - circle[2][0]) + sq(y - circle[2][1]) < sq(circle[2][2]))
                                    counter[cases]++, cut_temp = 1, printf("1\t(%lld, %lld)\n", x, y);
                            else if (sq(x - circle[0][0]) + sq(y - circle[0][1]) > sq(circle[0][2]) && 
                                sq(x - circle[2][0]) + sq(y - circle[2][1]) > sq(circle[2][2]))
                                    counter[cases]++, cut_temp = 1, printf("1\t(%lld, %lld)\n", x, y);
                        }
                        else if (i == 2){
                            if (sq(x - circle[1][0]) + sq(y - circle[1][1]) < sq(circle[1][2]) && 
                                sq(x - circle[0][0]) + sq(y - circle[0][1]) < sq(circle[0][2]))
                                    counter[cases]++, cut_temp = 1, printf("2\t(%lld, %lld)\n", x, y);
                            else if (sq(x - circle[1][0]) + sq(y - circle[1][1]) > sq(circle[1][2]) && 
                                sq(x - circle[0][0]) + sq(y - circle[0][1]) > sq(circle[0][2]))
                                    counter[cases]++, cut_temp = 1, printf("2\t(%lld, %lld)\n", x, y);
                        }
                    }
                    
                }
            }
        }
        cases--;
    }
    for (int i = case_rec; i > 0; i--)
        printf("%d\n", counter[i]);
}