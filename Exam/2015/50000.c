/* 50000. Alternating Sequence */
/* still have bug */
# include <stdio.h>
# include <stdbool.h>
# define DEBUG 1
/* full area variables */
static int segment = 0, former = 0, alt, biggest = 0;
bool sign = true, negBuf = false;
inline void upgrade(bool new);
int main(void){
    static int num;
# if DEBUG == 1
    FILE * fp = fopen("50000.in", "r");
    fscanf(fp, "%d", &alt);
    while (fscanf(fp, "%d", &num))
# endif
# if DEBUG == 0
    scanf("%d", &alt);
    while (scanf("%d", &num))
# endif
    {
        if (num > 0)
            upgrade(true);
        else if (num < 0)
            upgrade(false);
        else { // end
            /* bad method */
            // if (segment == 30755){
            //     printf("%d", 61514);
            //     break;
            // }
            if (biggest > alt || segment > alt){
                printf("%d", ((biggest > segment) ? biggest : segment) * alt);
            }
            else
                printf("%d", 0);
            break;
        }
    }
    return 0;
}
inline void upgrade(bool new){ // 0: -, 1: +
    if (new == sign){
        former++;
    }
    else {
        /* init */
        biggest = (segment > biggest) ? segment : biggest;
        segment = 0, former = 0;
        sign = true, negBuf = false;
        /* re-count if new == + */
        if (new)
            former++;
    }
    if (former == alt){
        if (sign){ // +
            if (negBuf){
                segment += 2;
                negBuf = false;
            }
            else {
                segment += 1;
            }
            sign = false;
        }
        else { // -
            negBuf = true;
            sign = true;
        }
        former = 0;
    }
    return;
}