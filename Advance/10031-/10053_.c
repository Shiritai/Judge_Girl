# include <stdio.h>

int table[16], sum[2] = {0, 0};
int result[3] = {0, 0, 0};
int play_table[16];
int n, last;

void init(int n){
    sum[0] = sum[1] = 0, last = 0x7fffffff;
    for (int i = 0; i < n * n; ++i)
        table[i] = play_table[i];
}

int choose(int last_choose, int person){ // person = 0 : 先手, = 1 : 後手
    if (last_choose == 0x7fffffff)
        last_choose = 1;
    if (!person){
        for (int from = last_choose / n, i = 0; i < 3; ++i){
            if (table[from * 3 + i] != -1)
                return from * 3 + i;
        }
    }
    else {
        for (int from = last_choose % n, i = 0; i < 3; ++i){
            if (table[from + i * 3] != -1)
                return from + i * 3;
        }
    }
    return -1; // can't choose!
}

void play(){
    init(n);
    int choosen, turn = 0;
    while ((choosen = choose(last, turn)) != -1){
        printf("\t%d\n", choosen);
        sum[turn] += table[choosen];
        table[choosen] = -1;
        printf("%d_%d\n", sum[0], sum[1]);
        turn = !turn;
    }
    printf("%d %d\n", sum[0], sum[1]);
    if (sum[0] > sum[1])
        ++result[0];
    else if (sum[0] < sum[1])
        ++result[1];
    else 
        ++result[2];
}

int main(void){
    scanf("%d", &n);
    for (int i = 0, in; i < n * n; ++i){
        scanf("%d", &in);
        play_table[i] = in;
    }
    play();
    printf("%d %d %d\n", result[0], result[1], result[2]);
}