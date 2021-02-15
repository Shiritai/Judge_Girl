#include <stdio.h>
typedef unsigned long long Set;
void init(Set *set);
void add(Set *set, int i);
void has(Set set, int i);
Set setUnion(Set a, Set b);
Set setIntersect(Set a, Set b);
Set setDifference(Set a, Set b);
int main()
{
    Set a, b, c;

    init(&a);
    add(&a, 3);
    add(&a, 5);
    add(&a, 2);

    init(&b);
    add(&b, 3);
    add(&b, 7);
    add(&b, 9);

    c = setUnion(a, b);
    has(c, 2);
    has(c, 3);
    has(c, 5);
    has(c, 7);
    has(c, 9);

    c = setIntersect(a, b);
    has(c, 2);
    has(c, 3);
    has(c, 5);
    has(c, 7);
    has(c, 9);

    c = setDifference(a, b);
    has(c, 2);
    has(c, 3);
    has(c, 5);
    has(c, 7);
    has(c, 9);

    return 0;
}
/* 275. Set */
# define BitLen (sizeof(Set) * 4)
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
Set setDifference(Set a, Set b){ // 不是「差集」...哭
    return a ^ b;
}