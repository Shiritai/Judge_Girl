/* 10059. Complex Number */
# include "complex.h"
void init(complex *c, float a, float b){
    c->r = a, c->i = b;
}
void complex_print(complex *x){
    printf("%.3f", x->r);
    if (x->i > 0)
        printf("+");
    printf("%.3fi\n", x->i);
}
complex complex_add(complex *x, complex *y){
    return (complex) {x->r + y->r, x->i + y->i};
}
complex complex_sub(complex *x, complex *y){
    return (complex) {x->r - y->r, x->i - y->i};
}
complex complex_mul(complex *x, complex *y){
    return (complex) {x->r * y->r - x->i * y->i, x->r * y->i + x->i * y->r};
}