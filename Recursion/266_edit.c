/* 266. Edit Distance */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct dict {
    char word[10];
    int index;
} dict;

int comp(const void * data1, const void * data2){
    dict * tmp1 = (dict *) data1, * tmp2 = (dict *) data2;
    return strcmp(tmp1 -> word, tmp2 -> word);
}

int edit_distance(char * str1, char * str2){
    if (strlen(str1) == 0)
        return (int) strlen(str2);
    else if (* str1 == * str2)
        return edit_distance(str1 + 1, str2 + 1);
    else 
        return 1 + edit_distance(str1 + 1, str2) + edit_distance(str1, str2 + 1);
}

int main(void){
    dict list[100];
    int ind = 0;
    while (scanf("%s", list[ind].word) != EOF && strcmp(list[ind].word, "-1")){
        list[ind].index = ind;
        ind++;
    }
    qsort(list, ind, sizeof(dict), comp);
    int min_val = 0x7fffffff, min_ind_1 = 0, min_ind_2 = 1;
    for (int i = 0; i < ind; ++i)
        puts(list[i].word);
    for (int i = 1; i < ind - 1; ++i){
        printf("i = %d\n", i);
        if (min_val > edit_distance(list[i].word, list[i + 1].word)){
            min_val = edit_distance(list[i].word, list[i + 1].word);
            min_ind_1 = list[i].index, min_ind_2 = list[i + 1].index;
        }
    }
    // for (int i = ind - 1; i >= 1; --i){
    //     for (int j = 0; j < i; ++j){
    //         if (min_val > edit_distance(list[i].word, list[j].word)){
    //             min_val = edit_distance(list[i].word, list[j].word);
    //             min_ind_1 = list[i].index, min_ind_2 = list[j].index;
    //         }
    //     }
    // }
    printf("%d %d %d\n", min_val, min_ind_1, min_ind_2);
}