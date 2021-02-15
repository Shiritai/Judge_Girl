/* 223. Tiles */
# include <stdio.h>
# include <stdlib.h>
# define CENTER_TYPE 5

int call_debug = 0, printNum = 0;

typedef struct tile {
    int type_; // 1, 2, 3, 4
    int len_; // 2 ^ n
    int x_, y_;
} tile;

inline int Clk_trans(int a) {return (a == 4) ? 1 : a+1;}
inline int ctClk_trans(int a) {return (a == 1) ? 4 : a-1;}

tile compo_gen(int type, tile mom){
    switch (type){
        case 1: 
            return (tile) {.type_ = 1, .len_ = mom.len_ / 2, .x_ = (mom.x_ - mom.len_ / 4), .y_ = (mom.y_ - mom.len_ / 4)};
        case 2: 
            return (tile) {.type_ = 2, .len_ = mom.len_ / 2, .x_ = (mom.x_ - mom.len_ / 4), .y_ = (mom.y_ + mom.len_ / 4)};
        case 3: 
            return (tile) {.type_ = 3, .len_ = mom.len_ / 2, .x_ = (mom.x_ + mom.len_ / 4), .y_ = (mom.y_ + mom.len_ / 4)};
        case 4: 
            return (tile) {.type_ = 4, .len_ = mom.len_ / 2, .x_ = (mom.x_ + mom.len_ / 4), .y_ = (mom.y_ - mom.len_ / 4)};
        case CENTER_TYPE: 
            return (tile) {.type_ = mom.type_, .len_ = mom.len_ / 2, .x_ = mom.x_, .y_ = mom.y_};
    }
    puts("error");
    return (tile) {0, 0, 0, 0};
}

// inline int num_of_tile(int l){
//     int i;
//     for (i = 0; l > 0; l >>= 1, ++i);
//     return i - 2;
// }

void print_tile(tile cur){
    ++call_debug;
    if (call_debug > 1024){
        puts("kill");
        exit(0);
    }
    if (cur.len_ == 2){
        ++printNum;
        puts("------");
        printf("%d %d %d\n", cur.type_, cur.x_, cur.y_);
        puts("------");
        return;
    }
    else {
        printf("\tcall 1\n");
        print_tile(compo_gen(CENTER_TYPE, cur));
        printf("\tcall 2\n");
        print_tile(compo_gen(cur.type_, cur));
        printf("\tcall 3\n");
        print_tile(compo_gen(Clk_trans(cur.type_), cur));
        printf("\tcall 4\n");
        print_tile(compo_gen(ctClk_trans(cur.type_), cur));
    }
}

void call_recur(int m, int center){
    while (center > 0){
        puts("call_recur");
        print_tile((tile) {.len_ = m * 2, .type_ = 1, .x_ = center, .y_ = center});
        center -= m;
        m *= 2;
    }
}

int main(void){
    int l, m;
    scanf("%d%d", &l, &m);
    call_recur(m, l - m);
    printf("printed : \"%d\" pairs", printNum);
    return 0;
}