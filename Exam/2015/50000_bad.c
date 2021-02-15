/* 50000. Alternating Sequence */
# include <stdio.h>
# include <stdbool.h>
# define limit_seg 100000
int main(void){
    int alt, length, tmp = 1, i, j, tmp_i;
    static int seq[limit_seg] = {0};
    scanf("%d", &alt);
    for (length = 0;; length++){
        scanf("%d", &tmp);
        if (tmp == 0)
            break;
        else if (tmp > 0)
            seq[length] = 1;
        else 
            seq[length] = 0;
    }
    int alt_long = 0, neg_to_pos;
    bool signal, flag;
    for (i = 0; i < length; i++){
        if (seq[i] == 1){
            signal = true, flag = true;
            tmp_i = i, neg_to_pos = 0;
            /* compute alternating sequence */
            while (flag){
                for (j = 0; j < alt && flag; j++){
                    if (seq[j + tmp_i + neg_to_pos] != signal)
                        flag = false;
                }
                if (flag){
                    neg_to_pos += j;
                    if (signal){ // add output index only if passed a positive segment 
                        tmp_i += neg_to_pos;
                        neg_to_pos = 0;
                    }
                }
                signal = (signal) ? false : true; // switch signal
            }
            alt_long = (alt_long < tmp_i - i) ? tmp_i - i: alt_long;
        }
    }
    printf("%d", alt_long);
    return 0;
}