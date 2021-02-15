/* 275. Set */
# include <stdio.h>
# include "set.h"
# define BitLen (sizeof(Set) * 4)
/* "某"LLU 或 "某"ULL, 其中 LL 可為 ll, UU 可為 uu, 都表示 unsigned long long */
void init(Set *set){
    * set = 0LLU;
    return;
}
void add(Set * set, int i){
    Set mask = 1LLU << i;
    * set |= mask;
    return;
}
void has(Set set, int i){
    Set mask = 1LLU << i;
    if (set & mask)
        printf("set has %d\n", i);
    else
        printf("set does not have %d\n", i);
    return;
}
Set setUnion(Set a, Set b){
    return a | b;
}
Set setIntersect(Set a, Set b){
    return a & b;
}
Set setDifference(Set a, Set b){ // 不是「差集」...
    return a ^ b;
}