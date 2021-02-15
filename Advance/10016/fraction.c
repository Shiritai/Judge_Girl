#include "fraction.h"
Frac normal(long long a, long long b) {
    long long x = a, y = b;
    while (y != 0){
        long long tmp = y;
        y = x % y;
        x = tmp;
    }
    return (Frac) {a/x, b/x};
}
Frac add(Frac x, Frac y) {return normal((x.a * y.b + y.a * x.b), x.b*y.b);}
Frac subtract(Frac x, Frac y) {return normal((x.a * y.b - y.a * x.b), x.b*y.b);}
Frac multipy(Frac x, Frac y) {return normal(x.a*y.a, x.b*y.b);}
Frac divide(Frac x, Frac y) {return normal(x.a*y.b, x.b*y.a);}