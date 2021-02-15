/* 223. Tiles */ // edit version 裡 type 2, 4 寫反了... 哭阿
# include <stdio.h>
# define CENTER_TYPE 5
/* a "strict" tile object */
typedef struct tile { // "strict" tile object 的 「缺口大小」 等於 「長度的一半」，故僅需 len_ 表形狀
    int type_, len_, x_, y_;
} tile;
/* rotate method */
inline int Clk_trans(int a) {return (a == 1) ? 4 : a-1;} // rotate clockwise
inline int ctClk_trans(int a) {return (a == 4) ? 1 : a+1;} // rotate counterclockwise
/* generate component tiles */
tile compo_gen(int type, tile mom){
    tile tmp;
    switch (type){
        case 1: 
            tmp =  (tile) {.type_ = 1, .len_ = mom.len_ / 2, .x_ = (mom.x_ - mom.len_ / 4), .y_ = (mom.y_ - mom.len_ / 4)};
            break;
        case 2: 
            tmp =  (tile) {.type_ = 2, .len_ = mom.len_ / 2, .x_ = (mom.x_ + mom.len_ / 4), .y_ = (mom.y_ - mom.len_ / 4)};
            break;
        case 3: 
            tmp =  (tile) {.type_ = 3, .len_ = mom.len_ / 2, .x_ = (mom.x_ + mom.len_ / 4), .y_ = (mom.y_ + mom.len_ / 4)};
            break;
        case 4: 
            tmp =  (tile) {.type_ = 4, .len_ = mom.len_ / 2, .x_ = (mom.x_ - mom.len_ / 4), .y_ = (mom.y_ + mom.len_ / 4)};
            break;
        case CENTER_TYPE: 
            tmp =  (tile) {.type_ = mom.type_, .len_ = mom.len_ / 2, .x_ = mom.x_, .y_ = mom.y_};
            break;
    }
    return tmp;
}
/* main recur func */
void print_tile(tile cur){
    if (cur.len_ == 2){ // a printable tile
        printf("%d %d %d\n", cur.type_, cur.x_, cur.y_);
        return;
    }
    else { // divide to smaller tiles
        print_tile(compo_gen(CENTER_TYPE, cur));
        print_tile(compo_gen(cur.type_, cur));
        print_tile(compo_gen(Clk_trans(cur.type_), cur));
        print_tile(compo_gen(ctClk_trans(cur.type_), cur));
    }
}
/* call "strict" tiles */
void call_recur(int m, int center){
    while (center > 0){
        print_tile((tile) {.len_ = m * 2, .type_ = 1, .x_ = center, .y_ = center});
        center -= m;
        m *= 2;
    }
}

int main(void){
    int l, m;
    scanf("%d%d", &l, &m);
    call_recur(m, l - m);
    return 0;
}