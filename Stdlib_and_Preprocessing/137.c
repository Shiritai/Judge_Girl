# include <stdio.h>

int main(void){
    int sum = 0, tmp, hundred_grade_sum = 0, cnt = 0;
    float rank_sum = 0.f;
    while (scanf("%d", &tmp) != EOF && tmp >= 0){
        ++cnt;
# ifdef HUNDRED
        printf("%d", tmp);
        sum += tmp;
# elif defined APLUS
        if (tmp > 100 || tmp < 0){
            puts("Grade out of range!");
            return 0;
        } else if (tmp >= 90 && tmp <= 100){
            printf("A+");
            rank_sum += 4.3f;
            hundred_grade_sum += 95;
        } else if (tmp >= 85 && tmp <= 89){
            printf("A");
            rank_sum += 4.0f;
            hundred_grade_sum += 87;
        } else if (tmp >= 80 && tmp <= 84) {
            printf("A-");
            rank_sum += 3.7f;
            hundred_grade_sum += 82;
        } else if (tmp >= 77 && tmp <= 79) {
            printf("B+");
            rank_sum += 3.3f;
            hundred_grade_sum += 78;
        } else if (tmp >= 73 && tmp <= 76) {
            printf("B");
            rank_sum += 3.0f;
            hundred_grade_sum += 75;
        } else if (tmp >= 70 && tmp <= 72) {
            printf("B-");
            rank_sum += 2.7f;
            hundred_grade_sum += 70;
        } else if (tmp >= 67 && tmp <= 69) {
            printf("C+");
            rank_sum += 2.3f;
            hundred_grade_sum += 68;
        } else if (tmp >= 63 && tmp <= 66) {
            printf("C");
            rank_sum += 2.0f;
            hundred_grade_sum += 65;
        } else if (tmp >= 60 && tmp <= 62) {
            printf("C-");
            rank_sum += 1.7f;
            hundred_grade_sum += 60;
        } else { 
            printf("F");
            hundred_grade_sum += 50;
        }
# endif
        printf(" ");
    }
# ifdef HUNDRED
    printf("%.1f\n", sum / (cnt * 1.));
# elif defined APLUS
    printf("%.1f %.1f\n", rank_sum / cnt, hundred_grade_sum / (cnt * 1.));
# endif
}