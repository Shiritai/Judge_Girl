/* 32. Longest Double Palindrome */
# include <stdio.h>
int main(void){
    int NumStr[100] = {-1};
    int length = 0, counter[2] = {0}; // 0: num of pal; 1: start point
    int pal[100] = {0};
    /* scan and count */
    while (scanf("%d", &NumStr[length]) == 1)
        length += 1;
    /* fetch palindrome */
    int fir_flag = 0, sec_flag = 0;
    for (int i = 0; i < length; i++){
        for (int j = length-1; j >= i; j--){
            fir_flag = 0;
            /* search for the first palindrome */
            for (int k = 0; k <= (j-i)/2; k++){
                if (NumStr[i+k] == NumStr[j-k]){
                    fir_flag = 1;
                    continue;
                }
                else {
                    fir_flag = 0;
                    break;
                }
            }
            /* search for the second palindrome */
            int tmp = 0;
            for (int x = length-1; x > j && fir_flag == 1; x--){
                for (int y = 0; y <= (x-j)/2; y++){
                    if (NumStr[j+y+1] == NumStr[x-y]){
                        sec_flag += 1;
                        continue;
                    }
                    else{
                        sec_flag = 0;
                        break;
                    }
                }
                if (counter[0] <= x-i+1 && sec_flag > tmp){
                    counter[0] = x-i+1, counter[1] = i, tmp = sec_flag;
                }
            }
        }
    }
    printf("%d", NumStr[counter[1]]);
    for (int i = 1; i < counter[0]; i++)
        printf(" %d", NumStr[counter[1] + i]);
}