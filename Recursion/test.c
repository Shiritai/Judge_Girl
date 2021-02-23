# include <stdio.h>
# include <string.h>

int edit_distance(char * str1, char * str2){
    if (strlen(str1) == 0)
        return (int) strlen(str2);
    else if (* str1 == * str2)
        return edit_distance(str1 + 1, str2 + 1);
    else 
        return 1 + edit_distance(str1 + 1, str2) + edit_distance(str1, str2 + 1);
}

int main(void){
    // printf("%d\n", edit_distance("apple", "applepie"));
    // scanf("%d");
    int tmp = 1, tmp_matrix[10] = {};
    while (scanf("%d%d", &tmp, &tmp_matrix[tmp]) == 2 && tmp < 10 && tmp >= 0);
    for (int i = 0; i < 10; ++i)    printf("%d ", tmp_matrix[i]);
}