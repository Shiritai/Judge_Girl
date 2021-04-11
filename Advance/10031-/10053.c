# include <stdio.h>

int table[16], sum[2] = {0, 0};
int result[3] = {0, 0, 0};
int play_table[16];
int n, last, turn;

void init(int n){
    sum[0] = sum[1] = 0, last = 0x7fffffff, turn = 0;
    for (int i = 0; i < n * n; ++i)
        table[i] = play_table[i];
}

int choose(int last_choose, int person){ // person = 0 : 先手, = 1 : 後手
    printf("person : %d\n", person);
    if (last_choose == 0x7fffffff)
        last_choose = 0;
    if (!person){
        for (int from = last_choose / n, i = 0; i < 3; ++i){
            if (table[from * 3 + i] != -1)
                return from * 3 + i;
        }
    }
    else {
        printf("last_ch : %d\n", last_choose);
        for (int from = last_choose % n, i = 0; i < 3; ++i){
            printf("from : %d\n", from);
            if (table[from + i * 3] != -1)
                return from + i * 3;
        }
    }
    return -1; // can't choose!
}
int depth = 0;
void play(){
    int choosen;
    if ((choosen = choose(last, turn)) != -1){
        /* 消去 */
        int rec = table[choosen];
        sum[turn] += rec;
        table[choosen] = -1;
        turn = !turn;
        play();
        printf("depth : %d\n", depth++);
        /* 復原 */
        table[choosen] = rec;
        sum[turn] -= rec;
        turn = !turn;
    }
    if (sum[0] > sum[1])
        ++result[0];
    else if (sum[0] < sum[1])
        ++result[1];
    else 
        ++result[2];
}

int main(void){
    // scanf("%d", &n);
    // for (int i = 0, in; i < n * n; ++i){
    //     scanf("%d", &in);
    //     play_table[i] = in;
    // }
    // init(n);
    // play();
    // printf("%d %d %d\n", result[0], result[1], result[2]);
    for (int i = 0; i < 9; ++i)
        table[i] = i;
    n = 3;
    printf("%d", choose(1, 1));
}