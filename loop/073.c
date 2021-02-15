/* 73. 3n, 3n + 1, and 3n + 2 */
# include <stdio.h>
int main(){
    int tot, n;
    int count[3] = {0};
    scanf("%d", &tot);
    while (tot > 0){
        scanf("%d", &n);
        if (n % 3 == 0)
            count[0]++;
        else if (n % 3 == 1)
            count[1]++;
        else if (n % 3 == 2)
            count[2]++;
        tot--;
    }
    printf("%d %d %d", count[0], count[1], count[2]);
}