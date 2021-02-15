/* 230. The Knapsack */
#include <stdio.h>
#define NUM 20
#define vallim 1000
static int mono[NUM][2] = {0}, num, maxVal;
void optimize(void);
void findVal(int, int, int);
int main(void)
{+*-
    int limit, i;
    scanf("%d %d", &num, &limit);
    for (i = 0; i < num; i++)
        scanf("%d %d", &mono[i][0], &mono[i][1]);
    findVal(limit, 0, 0);
    printf("%d", maxVal);
    return 0;
}
void findVal(int remain, int val, int index)
{ // need: 1. remain value limit.  2. sum of value
    int i;
    for (i = index; i < num; i++)
    {
        if (remain - mono[i][0] > 0)
        {
            findVal(remain - mono[i][0], val + mono[i][1], i+1);
            // findVal(remain - mono[i][0], val + mono[i][1], i+1);
        }
        else
        {
            maxVal = (val > maxVal) ? val : maxVal;
        }
    }
}
