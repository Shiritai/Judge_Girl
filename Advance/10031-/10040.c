/* 10040. Dictionary & Substring */
# include <stdio.h>
# include <string.h>
int main(void){
    char dict[200][50] = {""};
    int n, q;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%s", dict[i]);
    scanf("%d", &q);
    char tmp[50];
    for (int i = 0; i < q; ++i){
        scanf("%s", tmp);
        int times = 0;
        for (int j = 0; j < n; ++j){
            if (strstr(dict[j], tmp) != NULL)
                ++times;
        }
        printf("%d\n", times);
    }
}