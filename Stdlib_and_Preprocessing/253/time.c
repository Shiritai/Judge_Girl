/* 253. Time Object */
# include <stdio.h>
# include "time.h"

void initTime(Time *time){
    time->hour = 0;
    time->minute = 0;
    time->second = 0;
}
void setTime(Time *time, int hour, int minute, int second){
    time->hour = hour;
    time->minute = minute;
    time->second = second;
}
void addTime(Time *time, int hour, int minute, int second){
    time->second += second;
    int carryout = time->second / 60;
    time->second %= 60;
    time->minute += minute + carryout;
    carryout = time->minute / 60;
    time->minute %= 60;
    time->hour = (time->hour + hour + carryout) % 24;
}
void printTime(Time *time){
# ifdef H24
    printf("%02d%cm:%02d:%02d\n", time->hour, time->minute, time->second);
# else
    printf("%02d%cm:%02d:%02d\n", (time->hour >= 12) ? (time->hour - 12 + ((time->hour == 12) ? 12 : 0)) : (time->hour + ((!time->hour) ? 12 : 0)), ((time->hour >= 12) ? 'p' : 'a'), time->minute, time->second);
# endif
}