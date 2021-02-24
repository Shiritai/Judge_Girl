/* 50116. Play with digits */
# include <stdio.h>
# define REFRESH 110
int main(void){
    int digit, num_digit = 0, num_zero = 0, odd = 0, even = 0, odd_even_flag = 0, mod_cnt = REFRESH;
    while (scanf("%d", &digit) == 1/*  && digit != -2 */){
        if (!mod_cnt)
            mod_cnt = REFRESH, odd %= 11, even %= 11;
        if (!digit)
            num_zero++;
        if (odd_even_flag)
            odd += digit;
        else
            even += digit;
        num_digit++, mod_cnt--;
        odd_even_flag = !odd_even_flag;
    }
    printf("%d\n%d\n%d\n%d\n", num_digit, !(digit & 1), num_zero, !((odd - even) % 11));
}