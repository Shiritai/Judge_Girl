# include <stdio.h>
# define abs(x) ((x) > 0 ? (x) : (-(x)))
int main(){
    /* read data */
    /* input parking lot */
    int n;
    scanf("%d", &n);
    /* 0: x-coord.; 1: y-coord.; 2: capacity;
        3: (for later, temp) distance between some bike and all park lot;
        4: (for later, temp) placement order data;
        5: (for later, data storage) num of bikes */
    int Park_lot_data[10][6] = {0};
    // Park_lot_data[10][3] = 2147483647; // assurance, may delete later
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &Park_lot_data[i][0], &Park_lot_data[i][1], &Park_lot_data[i][2]);
    /* input illegal bicycle */
    int m;
    scanf("%d", &m);
    int Bike_data[100000][2] = {0};
    for (int i = 0; i < m; i++)
        scanf("%d%d", &Bike_data[i][0], &Bike_data[i][1]);
    /* main computation */
    /* do one bike in each loop */
    for (int i = 0; i < m; i++){
        /////////////////////////////////
        /* compute the distance */
        for (int j = 0; j < n; j++)
            Park_lot_data[j][3] = abs(Bike_data[i][0] - Park_lot_data[j][0]) + abs(Bike_data[i][0] - Park_lot_data[j][1]);
        /////////////////////////////////
        /* now Park_lot_data[0~n-1][3] has the distance between some bike and 0 ~ n-1 parking lot */
        /* decide the parking place */
        /////////////////////////////////
        /* bubble sort +: order mark */
        /* concept: each time deliver the max/min element to the LHS/MHS */
        /* mark the order */
        for (int j = 0; j < n; j++){
            Park_lot_data[j][4] = j;
        }
        /* sort */
        for (int j = n-2; j >= 0; j--){ // sort range
            for (int k = 0; k <= j; k++){
                int sort_flag = 0; // for abbreviation
                /* swap order w.r.t. distance */
                if (Park_lot_data[k][3] > Park_lot_data[k+1][3])
                    sort_flag = 1;
                /* swap order when situation of same distance occur */
                else if (Park_lot_data[k][3] == Park_lot_data[k+1][3]){
                    /* same x coord. */
                    if (Park_lot_data[k][0] > Park_lot_data[k+1][0])
                        sort_flag = 1;
                    /* same y coord. */
                    else if (Park_lot_data[k][0] == Park_lot_data[k+1][0]){
                        if (Park_lot_data[k][1] > Park_lot_data[k+1][1])
                            sort_flag = 1;
                    }
                }
                /* swap the marked term */
                if (sort_flag == 1){
                    Park_lot_data[k][3] ^= Park_lot_data[k+1][3] ^= Park_lot_data[k][3] ^= Park_lot_data[k+1][3];
                    Park_lot_data[k][4] ^= Park_lot_data[k+1][4] ^= Park_lot_data[k][4] ^= Park_lot_data[k+1][4];
                }
            }
        }
        /////////////////////////////////
        /* now Park_lot_data[0~n-1][4] has the order of the nearest parking place, ordered by 0~n-1 */
        //_________________________________________________________test
        printf("\n_____________Bike  No.%d_____________\n\n", i);
        for (int j = 0; j < n; j++)
            printf("Park_lot_data[%d][4] = %d\n", j, Park_lot_data[j][4]);
        //_________________________________________________________test
        /* place the bike */
        int num = 0, boo_or = 0;
        while (num < n && boo_or == 0){
            /* place bike */
            if (Park_lot_data[(Park_lot_data[num][4])][5] < Park_lot_data[(Park_lot_data[num][4])][2]){
                Park_lot_data[(Park_lot_data[num][4])][5]++;
                boo_or = 1;
            }
            /* try place to the secondary parking lot */
            else{
                num++;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", Park_lot_data[i][5]);
}