/* 232. What day is Today? */
# include <stdio.h>
int NormalYear_DayFinder(int month, int date, int fix);
int LeapYear_DayFinder(int month, int date, int fix);
int main(){
    /* initialization and input */
    /* year: 0: input year; 1: flag (leap or not) */
    /* time: 0: month; 1: date; 2: day */
    int year[2], day_0, num, time[10][3];
    scanf("%d%d%d", &year[0], &day_0, &num);
    for (int i = 0; i < num; i++)
        scanf("%d%d", &time[i][0], &time[i][1]);
    /* determine  whether it's normal year or leap year */
    year[1] = ((year[0] % 4 == 0 && year[0] % 100 != 0) || year[0] % 400 == 0) ? 1:0; // flag of leap year
    /* distribute the date */
    for (int i = 0; i < num; i++){
        /* normal year */
        if (year[1] == 0){
            time[i][2] = NormalYear_DayFinder(time[i][0], time[i][1], day_0);
        }
        else if (year[1] == 1){
            time[i][2] = LeapYear_DayFinder(time[i][0], time[i][1], day_0);
        }
    }
    for (int i = 0; i < num; i++)
        printf("%d\n", time[i][2]);
}
int NormalYear_DayFinder(int month, int date, int fix){
    /* return error situation */
    if (month > 12 || month < 1)
        return -1;
    else if (date < 1)
        return -2;
    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && date > 31)
        return -2;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && date > 30)
        return -2;
    else if (month == 2 && date > 28)
        return -2;
    /* compute the day */
    date += (fix-1);
    switch (month)
    {
    case 1: case 10:
        return date % 7;
        break;
    case 5:
        return (date + 1) % 7;
        break;
    case 8:
        return (date + 2) % 7;
        break;
    case 2: case 3: case 11:
        return (date + 3) % 7;
        break;
    case 6:
        return (date + 4) % 7;
        break;
    case 9: case 12:
        return (date + 5) % 7;
        break;
    case 4: case 7:
        return (date + 6) % 7;
        break;
    default:
        printf("W_T_F_Normal\n");
        break;
    }
}
int LeapYear_DayFinder(int month, int date, int fix){
    /* return error situation */
    if (month > 12 || month < 1)
        return -1;
    else if (date < 1)
        return -2;
    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && date > 31)
        return -2;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && date > 30)
        return -2;
    else if (month == 2 && date > 29)
        return -2;
    /* compute the day */
    date += (fix-1);
    switch (month)
    {
    case 1: case 4: case 7:
        return date % 7;
        break;
    case 10:
        return (date + 1) % 7;
        break;
    case 5:
        return (date + 2) % 7;
        break;
    case 2: case 8:
        return (date + 3) % 7;
        break;
    case 3: case 11:
        return (date + 4) % 7;
        break;
    case 6:
        return (date + 5) % 7;
        break;
    case 9: case 12:
        return (date + 6) % 7;
        break;
    default:
        printf("W_T_F_Leap\n");
        break;
    }
}