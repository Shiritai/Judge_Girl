# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct string_count {
  char seen[80];
  int count;
} StrCnt;
 
/* *
 * if compare_and_add finds a match, 
 * it will return 1 
 * otherwise, it will return 0.
 * */
int compare_and_add(char * string, StrCnt strings[]){
    int i = 0;
    for (; strings[i].count; ++i){
        if (!strcmp(string, strings[i].seen)){
            ++(strings[i].count);
            return 1;
        }
    }
    strings[i].count = 1;
    strcpy(strings[i].seen, string);
    return 0;
}

int comp(const void * data1, const void * data2){
    StrCnt * a = (StrCnt *) data1, * b = (StrCnt *) data2;
    return (a->count != b->count) ? a->count - b->count : strcmp(a->seen, b->seen);
}
	

void print(StrCnt strings[]){
    for (int i = 0; strings[i].count; ++i){
        printf("%d %s\n", strings[i].count, strings[i].seen);       
    }
}

void sort(StrCnt strings[]){
    int size = 0;
    for (; strings[size].count; ++size);
    qsort(strings, size, sizeof(strings[0]), comp);
}
/* 
int main() {
    struct string_count strings[20];
    int i;
    for( i=0 ; i<20 ; i++ )
        strings[i].count = 0;
    compare_and_add( "This", strings );
    compare_and_add( "is", strings );
    compare_and_add( "an", strings );
    compare_and_add( "apple,", strings );
    compare_and_add( "and", strings );
    compare_and_add( "this", strings );
    compare_and_add( "is", strings );
    compare_and_add( "a", strings );
    compare_and_add( "book.", strings );
    sort( strings );
    print( strings );
    return 0;
} */