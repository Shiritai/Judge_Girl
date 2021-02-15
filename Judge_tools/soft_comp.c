# include <stdio.h>
int main(int argc, char * argv[]){
    FILE * fp1 = fopen(argv[1], "r");
    FILE * fp2 = fopen(argv[2], "r");
    char comp1 = '\0', comp2 = '\0';
    while (comp1 != EOF && comp2 != EOF){
        do { comp1 = fgetc(fp1);} while (comp1 == ' ' || comp1 == '\n');
        do { comp2 = fgetc(fp2);} while (comp2 == ' ' || comp2 == '\n');
        if (comp1 == comp2)
            continue;
        else 
            printf("diff : %c <--> %c\n", comp1, comp2);
    }
    return 0;
}