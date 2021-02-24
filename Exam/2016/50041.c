/* 50041. Mountains */
# include <stdio.h>
# define abs(x) (x) > 0 ? (x) : -(x)

int main(void){
    int n, cost = 0, m1, m2;
    scanf("%d", &n);
    scanf("%d%d", &m1, &m2);
    _Bool moto = m2 > m1, tmp; // 0 : downhill, 1 : uphill
    cost += (moto) ? (abs(m2 - m1)) * 3 : (abs(m2 - m1)) * 2;
    while (scanf("%d", &m1) == 1/*  && m1 != -1 */){
        tmp = m1 > m2;
        cost += (tmp) ? ((moto) ? (abs(m2 - m1)) * 4 : (abs(m2 - m1)) * 3) : ((moto) ? (abs(m2 - m1)) * 3 : (abs(m2 - m1)) * 2);
        moto = tmp, m2 = m1;
    }
    printf("%d\n", cost);
}