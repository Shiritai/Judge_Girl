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

int edit_distance(char *, char *);


int main(void){
    dict list[100];
    int ind = 0;
    while (scanf("%s", list[ind].word) != EOF && strcmp(list[ind].word, "-1")){
        list[ind].index = ind+1;
        ind++;
    }
    qsort(list, ind, sizeof(dict), comp);
    /* test qsort */
    // for (int i = 0; i < ind; ++i)
    //     puts(list[i].word);
    int min_val = 0x7fffffff, min_ind_1 = list[0].index, min_ind_2 = list[1].index;
    min_val = edit_distance(list[0].word, list[1].word);
    // for (int i = 1; i <= ind - 1; ++i){
    //     printf("i = %d\n", i);
    //     if (min_val > edit_distance(list[i].word, list[i + 1].word)){
    //         min_val = edit_distance(list[i].word, list[i + 1].word);
    //         min_ind_1 = list[i].index, min_ind_2 = list[i + 1].index;
    //     }
    // }
    for (int i = ind - 1; i >= 1; --i){
        for (int j = 0; j < i; ++j){
            int tmp = edit_distance(list[i].word, list[j].word);
            if (min_val > tmp){
                min_val = tmp;
                min_ind_1 = list[i].index, min_ind_2 = list[j].index;
            }
        }
    }
    if (min_ind_1 > min_ind_2)
        min_ind_1 ^= min_ind_2 ^= min_ind_1 ^= min_ind_2;
    printf("%d %d %d\n", min_val, min_ind_1, min_ind_2);
}

inline int min(int a, int b){
    return a < b ? a : b;
}

int edit_distance(char * str1, char * str2){
    // printf("%s_%s\n", str1, str2);
    if (* str1 == '\0')
        return (int) strlen(str2);
    else if (* str2 == '\0')
        return (int) strlen(str1);
    else if (* str1 == * str2)
        return edit_distance(str1 + 1, str2 + 1);
    else 
        return 1 + min(edit_distance(str1 + 1, str2), edit_distance(str1, str2 + 1));
    // if (cur > min_val)
    //     return 0x7fffffff;
    // if (strlen(str1) == 0)
    //     cur += (int) strlen(str2);
    // else if (* str1 == * str2)
    //     cur += edit_distance(str1 + 1, str2 + 1);
    // else 
    //     cur += 1 + edit_distance(str1 + 1, str2) + edit_distance(str1, str2 + 1);
    // return cur;
}