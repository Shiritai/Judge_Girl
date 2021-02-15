# include <stdio.h>
# include <assert.h>
# include <stdlib.h>
# define print_file main
int print_file(int argc, char * argv[]){
    for (int i = 1; i < argc; ++i){
        printf("------------------------------------\n");
        printf("File : %s\n----------\n", argv[i]);
        FILE * fp = fopen(argv[i], "r");
        assert(fp != NULL);
        int c;
        for (; (c = fgetc(fp)) != EOF; putchar(c));
        printf("\n------------------------------------\n");
    }
    return 0;
}