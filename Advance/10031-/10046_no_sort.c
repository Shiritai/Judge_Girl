/* 10046. Derangement */
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
char dict[10];
int ind = 0, limit[100][2] = {};
int n, m;
void init(void){
    for (int i = 0; i < m; ++i)
        limit[i][0] = 0, limit[i][1] = 0;
    memset(dict, 0, sizeof(char) * n);
    ind = 0;
    return;
}
void swap(char * a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
int check_derange(int place, int alpha){
    for (int i = 0; i < m; ++i){
        if (limit[i][0] == dict[alpha] - 'A' + 1 && limit[i][1] == place+1)
            return 0;
    }
    return 1;
}
void permute(int head){
    if (head == n-1){
        if (check_derange(n-1, n-1))
            puts(dict);
    }
    else {
        for (int i = head; i < n; ++i){
            if (check_derange(head, i)){
                swap((dict+head), (dict+i));
                permute(head+1);
                swap((dict+head), (dict+i));
            }
        }
    }
}
int main(void){
    while (scanf("%d%d", &n, &m) == 2){
        for (int i = 0; i < n; ++i)
            dict[i] = i + 'A';
        for (int i = 0; i < m; ++i)
            scanf("%d%d", &limit[i][0], &limit[i][1]);
        permute(0);
        init();
    }
    return 0;
}