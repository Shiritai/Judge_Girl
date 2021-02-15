/* 225. Friends */
# include <stdio.h>
# include <assert.h>
# include <string.h>
# include <stdbool.h>
# define kazu 10000
typedef struct person {
    unsigned int id;
    char name[32];
} Person;
typedef struct friends {
    unsigned id1;
    unsigned id2;
} Friends;
int main(void){
    /* init and read file */
    int P, F, i;
    Person hito[kazu];
    Friends pair[kazu];
    FILE * fp = fopen("friends", "rb");
    assert(fp != NULL);
    fread(&P, sizeof(int), 1, fp);
    // for (i = 0; i < P; i++)
    fread(hito, sizeof(Person), P, fp);
    fread(&F, sizeof(int), 1, fp);
    fread(pair, sizeof(Friends), F, fp);
    /* read input */
    char a[32], b[32];
    unsigned int id_1, id_2;
    bool flag1, flag2;
    while (scanf("%s", a) && strcmp(a, "end") != 0){
        scanf("%s", b);
        /* find person */
        flag1 = false, flag2 = false;
        for (i = 0; i < P && !(flag1 && flag2); i++){
            if (strcmp(a, hito[i].name) == 0 && !flag1){
                id_1 = hito[i].id;
                flag1 = true;
            }
            if (strcmp(b, hito[i].name) == 0 && !flag2){
                id_2 = hito[i].id;
                flag2 = true;
            }
        }
        /* if more than 1 of the flags is not "true" */
        if (!(flag1 && flag2)){
            printf("no\n");
            continue;
        }
        flag1 = false;
        /* search friend list */
        for (i = 0; i < F && !flag1; i++){
            if ((id_1 == pair[i].id1 && id_2 == pair[i].id2) || (id_1 == pair[i].id2 && id_2 == pair[i].id1)){
                printf("yes\n");
                flag1 = true;
            }
        }
        if (!flag1)
            printf("no\n");
    }
    fclose(fp);
    return 0;
}