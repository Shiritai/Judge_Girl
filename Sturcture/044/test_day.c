# include <stdio.h>

typedef unsigned int UI;

typedef struct Date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
} Date;

UI month_days(UI month, UI year){
    switch (month){
        case 1u: case 3u: case 5u: case 7u: case 8u: case 10u: case 12u:
            return 31u;
        case 4u: case 6u: case 9u: case 11u:
            return 30u;
        case 2u:
            return ((!(year & 3u) && year % 100u) || !(year % 400u)) ? 29u : 28u;
        default :
            return 0u;
    }
}

UI day_cnt(struct Date a, struct Date b){
    UI result = 1u;
    if (a.year < b.year){
        for (UI i = a.year + 1; i < b.year; ++i){
            result += ((!(i & 3) && i % 100) || !(i % 400)) ? 366 : 365;
        }
        for (UI i = a.month + 1; i <= 12; ++i){
            result += month_days(i, a.year);
        }
        for (UI i = b.month - 1; i >= 1; --i){
            result += month_days(i, b.year);
        }
        result += month_days(a.month, a.year) - a.day + b.day;
    }
    else {
        if (a.month != b.month){
            for (UI i = a.month + 1; i < b.month; ++i){
                result += month_days(i, a.year);
            }
            result += month_days(a.month, a.year) - a.day + b.day;
        }
        else 
            result += b.day - a.day;
    }
    return result;
}

int main(void){
    Date tmp1, tmp2;
    while (scanf("%u%u%u%u%u%u", &tmp1.year, &tmp1.month, &tmp1.day, &tmp2.year, &tmp2.month, &tmp2.day) == 6)
        printf("result : %u\n", day_cnt(tmp1, tmp2));
}