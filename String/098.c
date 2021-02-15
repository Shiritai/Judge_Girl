/* 98. Food Ingredients in Common */
# include <stdio.h>
# include <string.h>
# include <assert.h>
# include <ctype.h>
# define nameLen 64
# define ingNum 10
# define foodNum 100
# define compNum 100000
# define DEBUG 0
typedef struct food{
    char name[nameLen];
    int cnt;
    char ing[ingNum][nameLen];
} Food;
void Common(char * a, int na, char * b, int nb);
int main(void){
    int i, j, k;
    int n;
    scanf("%d", &n);
    Food list[foodNum] = {"", 0, {""}}; // structure needs initialization
    /* input data */
    for (i = 0; i < n; i++){
        scanf("%s", &(list[i].name));
        scanf("%d", &(list[i].cnt));
        for (j = 0; j < list[i].cnt; j++)
            scanf("%s", &(list[i].ing[j]));
        // fooPtr++; // move to the next Food
    }
    /* input compare foods */
    int m;
    static char comp[compNum][2][nameLen] = {{""}};
    scanf("%d", &m);
    for (i = 0; i < m; i++)
        scanf("%s%s", comp[i][0], comp[i][1]);
    /* output data check */
# if DEBUG == 1 // usage of #
    printf("\n_____About foods_____\n");
    for (i = 0; i < n; i++){
        printf("\nFood name: %s\n", list[i].name);
        printf("There are %d ingred:\n", list[i].cnt);
        for (j = 0; j < list[i].cnt; j++)
            printf("\t%3d: %s\n", j, list[i].ing[j]);
    }
    printf("\n_____About comp_____\n");
    for (i = 0; i < m; i++)
        printf("%s\t%s\n", comp[i][0], comp[i][1]);
    printf("\n_____test end_____\n\n");
# endif
    /* send to Common */
    char * ptr[2];
    int numRec[2] = {0};
    for (i = 0; i < m; i++){
        ptr[0] = NULL, ptr[1] = NULL;
        for (j = 0; j < n; j++){
            for (k = 0; k < 2; k++)
                if (strncmp(comp[i][k], list[j].name, strlen(list[j].name)) == 0){
                    ptr[k] = list[j].ing[0], numRec[k] = list[j].cnt; // warning
                    // printf("cnt[%d] = %d\n", k, numRec[k]);
                }
            if (ptr[0] != NULL && ptr[1] != NULL){
                // printf("0: %s__%d; 1: %s__%d\n", ptr[0], numRec[0], ptr[1], numRec[1]);
                Common(ptr[0], numRec[0], ptr[1], numRec[1]);
                break;
            }
        }
    }
    return 0;
}
void Common(char * a, int na, char * b, int nb){ // maybe na, nb are unnecessary
    int i, j, k;
    char ans[ingNum][nameLen] = {""}; // for print
    char ingB[ingNum][nameLen] = {""};
    char * start = b, delemiter[] = " ";
    for (i = 0; i < nb; i++){
        strcpy(ingB[i], (start + (nameLen * i)));
    }
    // /* strtok method */
    // i = 0;
    // start = strtok(start, delemiter);
    // strcpy(ingB[i], start);
    // while (start != NULL){
    //     i++;
    //     strcpy(ingB[i], (start + nameLen));
    //     start = strtok(NULL, delemiter);
    // }
    /* fetched data check */
# if DEBUG == 1
    // i = 0;
    while (j < nb){
        printf("ingB[%d] = %s\n", j, ingB[j]);
        j++;
    }
# endif
    /* compare a, b */
    int ansCnt = 0;
    start = a;
    for (i = 0; i < na; i++){
        if (strcmp(ingB[i], (start + (nameLen * i))) == 0){
            strcpy(ans[ansCnt], ingB[i]);
            ansCnt++;
        }
    }

    // char tmp[nameLen];
    // start = strtok(a, delemiter);
    // while (start != NULL){
    //     for (i = 0; i < nb; i++){
    //         if (strcmp(start, ingB[i]) == 0){
    //             strcpy(ans[ansCnt], start);
    //             printf("ans[%d] = %s\n", ansCnt, ans[ansCnt]);
    //             ansCnt++;
    //         }
    //     }
    //     start = strtok(NULL, delemiter);
    // }

    /* practice not using strtok */
    // char tmp[nameLen], * zeroPtr, * ingBPtr = ingB[ingNum];
    // for (i = 0; i < na; i++){
    //     zeroPtr = strchr(a, ' ');
    //     assert(zeroPtr != NULL);
    //     * zeroPtr = '\0';
    //     strcpy(tmp, a);
    //     printf("test tmp = %s", tmp);
    //     for (; isprint(* ingBPtr); ingBPtr += nameLen){
    //         if (strcmp(tmp, ingBPtr) == 0){
    //             strcpy(ans[ansCnt], ingBPtr);
    //             ansCnt++;
    //         }
    //     }
    //     a = zeroPtr + nameLen; // move to the next data
    // }
    /* print */
    if (ansCnt >= 1){
        /* dictionary sort */
        char * ansPtr[ingNum], * tmpPtr;
        /* init of ansPtr */
        for (i = 0; i < ansCnt; i++){
            ansPtr[i] = ans[i];
        }
        /* bubble sort + strcmp */
        for (i = ansCnt - 2; i >= 0; i--){
            for (j = 0; j <= i; j++){
                if (strcmp(ansPtr[j], ansPtr[j+1]) > 0){
                    tmpPtr = ansPtr[j];
                    ansPtr[j] = ansPtr[j+1];
                    ansPtr[j+1] = tmpPtr;
                }
            }
        }
        printf("%s", ansPtr[0]);
        for (i = 1; i < ansCnt; i++)
            printf(" %s", ansPtr[i]);
        printf("\n");
    }
    else
        printf("nothing\n");
}