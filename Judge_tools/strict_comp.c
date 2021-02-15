# include <stdio.h>
int main(int argc, char * argv[]){
    FILE * fp1 = fopen(argv[1], "r");
    FILE * fp2 = fopen(argv[2], "r");
    char comp1, comp2;
    while ((comp1 = fgetc(fp1)) != EOF && (comp2 = fgetc(fp2)) != EOF){
        if (comp1 == comp2)
            continue;
        else 
            printf("diff : %c <--> %c\n", comp1, comp2);
    }
    return 0;
}