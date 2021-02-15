/* 10059. Complex Number */
#ifndef _COMPLEX_H
#define _COMPLEX_H
# include <stdio.h>
// # include <stdlib.h>

typedef struct cplx{
    float r, i;
} complex;
 
void init(complex *c, float a, float b);
void complex_print(complex *x);
complex complex_add(complex *x, complex *y);
complex complex_sub(complex *x, complex *y);
complex complex_mul(complex *x, complex *y);
#endif