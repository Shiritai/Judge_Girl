/* 202. Mixed Fractions */
# include <stdio.h>
# include <stdlib.h>
# define ADD 0
# define SUB 1
# define MUL 2
# define DIV 3

int gcd(int x1, int x2);
int main(){
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    int m1 = abs(a)*c+b;
    int m2 = abs(e)*g+f;
    int dom = c*g;
    int int_3 = 0, m3 = 0;
    /* consider a negative num */
    if (a < 0)
        m1 *= -1;
    if (e < 0)
        m2 *= -1;
    switch (d)
    {
    case ADD :
        printf("\n__ADD__\n\n");
        m3 = m1 * g + m2 * c;
        break;
    case SUB :
        printf("\n__SUB__\n\n");
        m3 = m1 * g - m2 * c;
        break;
    case MUL :
        printf("\n__MUL__\n\n");
        m3 = m1 * m2; //molecular
        break;
    case DIV :
        printf("\n__DIV__\n\n");
        m3 = m1 * g; //molecular
        dom = m2 * c; // dominator
        if (dom < 0){
            dom *= -1;
            m3 *= -1;
        }
        break;
    default:
        printf("W_T_F\n");
        break;
    }
    printf("m3 = %d || dom = %d\n", m3, dom);
    /* proper fractionalize */
    /* be care of negative issue */
    int head = 1;
    if (abs(m3) >= dom){
        if (m3 > 0){
            int_3 += m3 / dom; // int
            m3 -= int_3 * dom; // molecular
        }
        else if (m3 < 0){
            head = -1, m3 = -m3;
            int_3 += m3 / dom; // int
            m3 -= int_3 * dom; // molecular
        }
    }
    else{}
    int assure_0 = (m3 != 0)? 0:1; // make sure m3 != 0, if that happens, make check_gcd = 1 and make dom = 1
    printf("int_3 = %d || m3 = %d || dom = %d || assure_0 = %d\n", int_3, m3, dom, assure_0);
    /* sure there is no common factor in molecular and dominator */
    if (assure_0 == 1){
        dom = 1;
    }
    else if (assure_0 == 0){
        printf("inside gcd check\n");
        int check_gcd = gcd(m3, dom);
        if(check_gcd != 1){
            m3 /= check_gcd, dom /= check_gcd;
            printf("gcd_fixed by gcd() = %d >>  m3 = %d || dom = %d\n", check_gcd, m3, dom);
        }
    }
    /* add back the negative issue */
    int_3 *= head;
    printf("%d\n%d\n%d", int_3, m3, dom);
}
int gcd(int x1, int x2){
    int i = 0;
    /* make sure x1 to be positive when return */
    x1 = (x1 > 0)? x1:-x1;
    /* make x1 the biggest before Euclidean algorithm */
    if (x1 < x2)   
        x1 ^= x2 ^= x1 ^= x2;
    /* test */
    printf("\n\n__inside function gcd__\nx1 = %d || x2 = %d\n", x1, x2);
    /* Euclidean algorithm */
    while (x1 % x2 != 0 && x2 != 1 && x1 != 0 && x2 != 0 && i < 100){
        i++;
        printf("loop No.%d\n", i);
        if (x1 > x2){
            x1 -= x2;
            if (x1 < x2)
                x1 ^= x2 ^= x1 ^= x2;
        }
    }
    /* make sure x2 to be positive when return */
    x2 = (x2 > 0)? x2:-x2;
    printf("x2 = %d\n__left function gcd__\n\n", x2);
    return x2;
}