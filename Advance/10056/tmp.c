# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int comp(const void * data1, const void * data2){
    return strcmp((char *) data1, (char *) data2);
}

int main(void){
    char a[4][40] = {"Eroiko", "JoJo", "Senjyougahara", "Hanekawa"};
    qsort(a, 4, sizeof(a[0]), comp);
    for (int i = 0; i < 4; ++i)
        printf("%s\n", a[i]);
}