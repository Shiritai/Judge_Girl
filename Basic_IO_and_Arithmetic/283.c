#include <stdio.h>
int main(){
    int ani_sum, foot_sum, tail_sum;
    scanf("%d%d%d", &ani_sum, &foot_sum, &tail_sum);

    printf("%d\n%d\n%d",
        (-4*tail_sum + 8*ani_sum - foot_sum) / 2,
        (6*tail_sum - 8*ani_sum + foot_sum) / 2,
        ani_sum - tail_sum);
}