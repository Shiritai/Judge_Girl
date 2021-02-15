/* 235. Pachinko */
# include <stdio.h>
# define Len 15

typedef struct {
    int numer, donom;
} frac;

frac div_gcd(int x, int y){
    if (x == 0)
        return (frac) {0, 1};
    if (y == 0 && x != 0)
        return (frac) {1, 0};
    int a = x, b = y;
    while (b > 0){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    x /= a, y /= a;
    return (frac) {x, y};
}

frac add(frac a, frac b){
    if (a.numer != 0 && b.numer != 0)
        return div_gcd(a.numer * b.donom + b.numer * a.donom, a.donom * b.donom);
    else if (a.numer == 0 && b.numer != 0)
        return b;
    else if (a.numer != 0 && b.numer == 0)
        return a;
    else 
        return (frac) {0, 1};
}

int main(void){
    /* init */
    int data[Len*(Len+1)/2][2] = {}, num, moto_ind = 0, ato_ind = 1, data_ind = 0;
    frac result[2][Len+1], tmp;
    result[0][0].numer = 1, result[0][0].donom = 1;
    /* scan and simplify input */
    scanf("%d", &num);
    for (int i = 0; i < num * (num+1) / 2; ++i){
        scanf("%d%d", &tmp.numer, &tmp.donom);
        tmp = div_gcd(tmp.numer, tmp.donom);
        data[i][0] = tmp.numer, data[i][1] = tmp.donom;
    }
    /* compute */
    for (int i = 0; i < num; ++i){ // No.i line
        /* init result table */
        for (int j = 0; j <= i; ++j){
            result[ato_ind][j] = (frac) {0, 1};
            result[ato_ind][j+1] = (frac) {0, 1};
        }
        /* add & divide & take gcd */
        for (int j = 0; j <= i; ++j, ++data_ind){
            result[ato_ind][j] = add(result[ato_ind][j], div_gcd(result[moto_ind][j].numer * data[data_ind][0], result[moto_ind][j].donom * (data[data_ind][0] + data[data_ind][1])));
            result[ato_ind][j+1] = add(result[ato_ind][j+1], div_gcd(result[moto_ind][j].numer * data[data_ind][1], result[moto_ind][j].donom * (data[data_ind][0] + data[data_ind][1])));
        }
        /* swap result index */
        if (moto_ind)
            moto_ind = 0, ato_ind = 1;
        else 
            moto_ind = 1, ato_ind = 0;
    }
    /* print */
    for (int i = 0; i <= num; ++i){
        printf("%d/%d\n", result[moto_ind][i].numer, result[moto_ind][i].donom);
    }
}