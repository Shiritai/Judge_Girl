/* 32. Longest Double Palindrome */
# include <stdio.h>
int main(void){
    int NumStr[100] = {-1};
    int length = 0, counter[2] = {0}; // 0: num of pal; 1: start point
    int pal[100] = {0};
    /* scan and count */
    while (scanf("%d", &NumStr[length]) == 1)
        length += 1;
    printf("\nlength = %d\n", length);
    /* fetch palindrome */
    int fir_flag = 0, sec_flag = 0, flag = 0;
    for (int i = 0; i < length; i++){
        flag = 0;
        printf("\n\nloop %d\n", i);
        for (int j = length-1; j >= i/*  && flag == 0 */; j--){
            fir_flag = 0;
            printf("\t_____first_____\n");
            /* search for the first palindrome */
            for (int k = 0; k <= (j-i)/2; k++){
                printf("\t(%d, %d) => (%d, %d)", i, j, NumStr[i+k], NumStr[j-k]);
                if (NumStr[i+k] == NumStr[j-k]){
                    printf("\t\t(%d, %d)\n\n", i+k, j-k);
                    fir_flag = 1;
                    continue;
                }
                else {
                    printf("\t\t__exit\n\n");
                    fir_flag = 0;
                    break;
                }
            }
            // if (counter[0] <= j-i+1 && fir_flag == 1)
            //     counter[0] = j-i+1, counter[1] = i;
            /* search for the second palindrome */
            int tmp = 0;
            for (int x = length-1; x > j && fir_flag == 1; x--){
                printf("\t\t\t\t____second____\n");
                for (int y = 0; y <= (x-j)/2; y++){
                    printf("\t\t\t\t(%d, %d) => (%d, %d)", j+1, x, NumStr[j+1+y] ,NumStr[x-y], y);
                    if (NumStr[j+y+1] == NumStr[x-y]){
                        printf("\t\t\t(%d, %d)\n\n", j+y+1, x-y);
                        sec_flag += 1;
                        continue;
                    }
                    else{
                        printf("\t\t\t__exit\n\n");
                        sec_flag = 0;
                        break;
                    }
                }
                if (counter[0] <= x-i+1 && sec_flag > tmp){
                    counter[0] = x-i+1, counter[1] = i;
                    flag = 1, tmp = sec_flag;
                }
            }
        }
    }
    for (int i = 0; i < length; i++)
        printf("%d ", NumStr[i]);
    
    printf("\nFrom %d to %d...\n", counter[1], counter[1] + counter[0]);
    printf("%d", NumStr[counter[1]]);
    for (int i = 1; i < counter[0]; i++)
        printf(" %d", NumStr[counter[1] + i]);
}