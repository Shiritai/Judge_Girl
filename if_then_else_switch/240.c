/* 240. Square, Diamond, and Rectangle */
# include <stdio.h>
# include <stdlib.h>
int ResultPrinter(int x);
int main(){
    int count;
    scanf("%d", &count);
    int save_data[100000];
    /* read and mark */
    for (int i = 0; i < count; i++){
        int data[8];
        /* scan data */
        for (int j = 0; j < 8; j++)
            scanf("%d", &(data[j]));
        /* fixed a point to be origin. Meanwhile, make vecA, vecB, vecC */
        for (int j = 0; j < 4; j++){
            data[2*j] -= data[6];
            data[2*j+1] -= data[7];
        }
        data[6] = 0, data[7] = 0;
        /* determine sorted vec */
        int a = 0;
        while (a < 3){
            if (data[0]*data[3] - data[1]*data[2] < 0){
                data[0] ^= data[2] ^= data[0] ^= data[2];
                data[1] ^= data[3] ^= data[1] ^= data[3];
            }
            else if (data[0]*data[3] - data[1]*data[2] > 0){
                if (data[2]*data[5] - data[3]*data[4] < 0){
                    data[2] ^= data[4] ^= data[2] ^= data[4];
                    data[3] ^= data[5] ^= data[3] ^= data[5];
                    continue;
                }
                else
                    break;
            }
            else{
                break;
            }
            a++;
        }
        /* whether 4 sides are the same */
        /* determine side vector */
        /* side 1 */
        data[6] = data[2];
        data[7] = data[3];
        data[2] -= data[0];
        data[3] -= data[1];
        /* side 3 */
        data[6] -= data[4];
        data[7] -= data[5];
        /* compute the length of 4 side */
        int SameSide[4];
        for (int j = 0; j < 4; j++)
            SameSide[j] = data[2*j] * data[2*j] + data[2*j+1] * data[2*j+1];
        /* branch of same side */
        if (SameSide[0] == SameSide[1] && SameSide[1] == SameSide[2] && SameSide[2] == SameSide[3]){
            if (data[0] * data[2] + data[1] * data[3] == 0){
                save_data[i] = 0; // square mark
            }
            else
                save_data[i] = 1; // diamond mark
        }
        else {
            if (data[0] * data[2] + data[1] * data[3] == 0
                && data[4] * data[6] + data[5] * data[7] == 0
                && data[2] * data[6] + data[3] * data[7] == 0)
                save_data[i] = 2; // rectangle mark
            else 
                save_data[i] = 3; // others
        }
    }
    /* print result */
    for (int i = 0; i < count; i++)
        ResultPrinter(save_data[i]);
}

int ResultPrinter(int x){
    switch (x){
    case 0:
        printf("square\n");
        break;
    case 1:
        printf("diamond\n");
        break;    
    case 2:
        printf("rectangle\n");
        break;
    case 3:
        printf("other\n");
        break;
    case 4:
        printf("___DNE___\n");
        break;
    default:
        printf("Something's wrong...\n");
        break;
    }
}