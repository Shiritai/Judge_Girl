/* 215. Chicken, Rabbit and Crab */
#include <stdio.h>
int main(){
    int ani_sum, foot_sum, tail_sum;
    scanf("%d%d%d", &ani_sum, &foot_sum, &tail_sum);

    int twice_chicken = -4*tail_sum + 8*ani_sum - foot_sum;
    int twice_rabbit = 6*tail_sum - 8*ani_sum + foot_sum;
    int twice_crab = ani_sum - tail_sum;

    if (twice_chicken >= 0 && twice_rabbit >= 0 && twice_crab >= 0 && twice_chicken % 2 == 0 && twice_rabbit % 2 == 0)
        printf("%d\n%d\n%d",
            twice_chicken / 2,
            twice_rabbit / 2,
            twice_crab);
    else printf("0");
}