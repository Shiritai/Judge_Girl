/* 36. Calender */
# include <stdio.h>
int main(void){
    int year, month, first, len = 0;
    scanf("%d%d%d", &year, &month, &first);
    if (len > 12 || len < 1 || first > 6 || first < 0)
        printf("invalid\n");
    switch (month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            len = 31;
            break;
        case 4: case 6: case 9: case 11:
            len = 30;
            break;
        case 2:{
            if ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)))
                len = 29;
            else 
                len = 28;
            break;
        }
    }
    printf(" Su Mo Tu We Th Fr Sa\n=====================\n");
    int i;
    for (i = 0; i < first; ++i)
        printf("   ");
    for (i = 1; i <= len; ++i){
        printf(" %2d", i);
        if (!((i + first) % 7))
            printf("\n");
    }
    if ((i - 1 + first) % 7 != 0)
        printf("\n");
    printf("=====================\n");
    return 0;
}