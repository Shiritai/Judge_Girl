# include <stdio.h>
# include <stdbool.h>
# include <string.h>
long long all_cp(int n, int m, char mode, char * str);
int main(void){
    int m, n;
    char mode[10], repeat[4] = "";
    printf("____input \"-1\" to exit____\n");
    printf("Noted that: n -> balls, m -> boxes\n");
    printf("mode: P/p -> Permutation, C/c -> Combination\n");
    while (1){
        printf("\nmode >>> ");
        scanf("%s", mode);
        if (strlen(mode) > 1){
            printf("         ^----- Bad mode, please retry.\n");
            continue;
        }
        printf("n >>> ");
        scanf("%d", &n);
        if (n < 0)
            break;
        printf("m >>> ");
        scanf("%d", &m);
        if (m < 0)
            break;
        printf("with repetition >>> ");
        scanf("%s", repeat);
        if (strcmp(repeat, "yes") * strcmp(repeat, "no") != 0)
            break;
        printf("\n>>> %lld\n", all_cp(n, m, mode[0], repeat));
    }
}
long long all_cp(int n, int m, char mode, char * str){
    if (n < m || n == 0)
        return 0LLU;
    else if (m == 0)
        return 1LLU;
    int i;
    long long tmp_result = 1;
    switch (mode){
    case 'P': case 'p':
        /* Permutation */
        if (strcmp(str, "yes") == 0){
            for (i = 0; i < m; i++)
                tmp_result *= n;
        }
        else {
            for (i = n; i > n-m; i--)
                tmp_result *= i;
        }
        break;
    case 'C': case 'c':
        /* Combination */
        if (strcmp(str, "yes") == 0)
            n += m-1;
        for (i = n; i > n-m; i--)
            tmp_result *= i;
        for (i = 2; i <= m; i++)
            tmp_result /= i;
        break;
    default:
        printf("\nunknown mode...\n");
        return 0;
    }
    return tmp_result;
}