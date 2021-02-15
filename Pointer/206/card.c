/* 206. Card Shuffling */
# include <stdio.h>
# include "card.h"
void shuffle(int *deck[]){
    int idx = 0, i, j;
    for (i = 0; i < 10000, deck[i] != NULL; i++, idx++); // count idx
    int hl_idx = (idx + 1) / 2; // half idx
    int* tmp_ptr_idx[idx];
    for (i = 0, j = 0; j <= hl_idx; i += 2, j++){
        tmp_ptr_idx[i] = deck[j];
        tmp_ptr_idx[i+1] = deck[hl_idx+j];
    }
    deck = tmp_ptr_idx;
    return;
}
void print(int *deck[]){
    int cnt = 0, i;
    for (i = 0; i < 10000, deck[i] != NULL; i++, cnt++); // count cnt
    if (cnt == 0)
        return;
    for (i = 0; i < cnt-1; i++)
        printf("%d ", *deck[i]);
    printf("%d", *deck[cnt-1]);
    return;
}