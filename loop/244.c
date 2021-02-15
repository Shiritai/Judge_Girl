/* 244. Lottery */
# include <stdio.h>
int main(){
    int special[3], firstP[3];
    scanf("%d%d%d%d%d%d", &special[0], &special[1], &special[2],
        &firstP[0], &firstP[1], &firstP[2]);
    int lottery = 0, dollar = 0;
    while (scanf("%d", &lottery) == 1){
        for (int i = 0; i < 3; i++){
            if (lottery == special[i])
                dollar += 2000000;
            if (lottery == firstP[i])
                dollar += 200000;
            else if ((lottery - firstP[i]) % 10000000 == 0)
                dollar += 40000;
            else if ((lottery - firstP[i]) % 1000000 == 0)
                dollar += 10000;
            else if ((lottery - firstP[i]) % 100000 == 0)
                dollar += 4000;
            else if ((lottery - firstP[i]) % 10000 == 0)
                dollar += 1000;
            else if ((lottery - firstP[i]) % 1000 == 0)
                dollar += 200;
        }
    }
    printf("%d", dollar);
    return 0;
}