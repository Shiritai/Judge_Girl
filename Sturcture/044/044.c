# include "book.h"
# include "date.h"

typedef unsigned int UI;

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

UI importance_cnt(UI tmp){
    while (!(tmp & 1))
        tmp >>= 1;
    UI i = 0u;
    tmp >>= 1;
    while (!(tmp & 1)){
        tmp >>= 1;
        ++i;
    }
    return i;
}

UI library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned){
    UI diff_days = day_cnt(date_borrowed, date_returned);
    // printf("diff_days : %d\n", diff_days);
    // printf("important_cnt : %d\n", importance_cnt(book.importance));
    switch (book.type){
        case NOVEL :{
            if (diff_days > 90u)
                return importance_cnt(book.importance) * (diff_days - 90u);
            else 
                return 0u;
        }
        case COMICS :{
            if (diff_days > 10u)
                return importance_cnt(book.importance) * (diff_days - 10u);
            else 
                return 0u;
        }
        case MANUAL :{
            if (diff_days > 100u)
                return importance_cnt(book.importance) * (diff_days - 100u);
            else 
                return 0u;
        }
        case TEXTBOOK :{
            if (diff_days > 5u)
                return importance_cnt(book.importance) * (diff_days - 5u);
            else 
                return 0u;
        }
    }
    return 0u;
}