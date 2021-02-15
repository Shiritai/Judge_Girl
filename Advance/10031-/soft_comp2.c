# include <stdio.h>
# include <ctype.h>
int main(int argc, char * argv[]){
    FILE * fp1 = fopen(argv[1], "r");
    FILE * fp2 = fopen(argv[2], "r");
    int line1 = 1, line2 = 1, diff_cnt = 0;
    char comp1 = '\0', comp2 = '\0';
    while (comp1 != EOF && comp2 != EOF){
        do { comp1 = fgetc(fp1); if (comp1 == '\n') line1++;} while (isspace(comp1));
        do { comp2 = fgetc(fp2); if (comp2 == '\n') line2++;} while (isspace(comp2));
        if (comp1 != comp2) {
            puts("--------------------------------");
            ++diff_cnt;
            printf("different char %d at : \nline %d in \"%s\" --> %c\nline %d in \"%s\" --> %c\n", diff_cnt, line1, argv[1], comp1, line2, argv[2], comp2);
        }
    }
    puts("--------------------------------");
    return 0;
}