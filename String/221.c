/* 221. Typesetting  */
# include <stdio.h>
# include <string.h>
# include <assert.h>
# include <stdbool.h>
# define sentLen 256
# define DEBUG 0
// # define artiLen 100000
int main(void){
    int limit;
    char word[sentLen], line[sentLen][sentLen] = {""}; // CR = carriage return
    // static char article[artiLen] = ""; // 換一個方針，直接印出
# if DEBUG == 0
    scanf("%d", &limit);
# endif
# if DEBUG == 1
    FILE * fp = fopen("testdata.txt", "r");
    assert(fp != NULL);
    fscanf(fp, "%d", &limit);
# endif
    /* operatants */
    int chars = 0, wordcnt = 0, moreblk = 0, avgblk = 0, lastblk = 0, i, j;
    bool addflag = false, noAdditionalBlk = false;
    /* loop of typesetting */
# if DEBUG == 0  
    while (scanf("%s", word)/*  && word[0] != '~' */)
# endif
# if DEBUG == 1
    while (fscanf(fp, "%s", word) != EOF)
# endif
    {
        if (chars == 0){
            strcpy(line[wordcnt], word);
            wordcnt++;
            chars += strlen(word) + 1;
        }
        else if (chars + strlen(word) < limit){
            strcpy(line[wordcnt], word);
            wordcnt++;
            chars += strlen(word) + 1;
        }
        else if (chars + strlen(word) == limit){
            strcpy(line[wordcnt], word);
            wordcnt++;
            chars += strlen(word);
            noAdditionalBlk = true;
        }
        else {
    # if DEBUG == 1
            printf("< chars + strlen(word) >= limit >\n");
    # endif
            /* space count */
            moreblk = limit - chars;
            avgblk = moreblk / (wordcnt - 1);
            lastblk = moreblk % (wordcnt - 1);
            printf("%s", line[0]);
            /* print */
            for (i = 1; i < wordcnt; i++){
                if (lastblk >= 0)
                    addflag = true;
                else
                    addflag = false;
                /* print more space(s) */
                for (j = 0; j < (avgblk + 1 * addflag); j++)
                    printf(" ");
                /* print word */
                printf(" %s", line[i]);
                lastblk--;
            }
            printf("\n");
            /* initialize */
            chars = 0, wordcnt = 0;
    # if DEBUG == 1
            for (i = 0; i < limit-1; i++)
                printf("-");
            printf("^\n\n");
    # endif
            /* read word, since this branch hasn't deal with the new input */
            if (chars == 0){
                strcpy(line[wordcnt], word);
                wordcnt++;
                chars += strlen(word) + 1;
            }
            else if (chars + strlen(word) < limit){
                strcpy(line[wordcnt], word);
                wordcnt++;
                chars += strlen(word) + 1;
            }
            else if (chars + strlen(word) == limit){
                strcpy(line[wordcnt], word);
                wordcnt++;
                chars += strlen(word);
                noAdditionalBlk = true;
            }
        }
        if (chars == limit){
            /* print */
    # if DEBUG == 1
            printf("< chars == limit >\n");
    # endif
            printf("%s", line[0]); // there should be 2 spaces at the first time
            if (!noAdditionalBlk)
                printf(" ");
            for (i = 1; i < wordcnt; i++){
                printf(" %s", line[i]);
            }
            printf("\n");
            /* initialize */
            chars = 0, wordcnt = 0;
            noAdditionalBlk = false;
    # if DEBUG == 1
            for (i = 0; i < limit-1; i++)
                printf("-");
            printf("^\n\n");
    # endif
        }
    }
    if (chars != 0){
    # if DEBUG == 1
            printf("< last line >\n");
    # endif
        /* space count */
        moreblk = limit - chars;
        avgblk = moreblk / (wordcnt - 1);
        lastblk = moreblk % (wordcnt - 1);
        printf("%s", line[0]);
        /* print */
        for (i = 1; i < wordcnt; i++){
            if (lastblk >= 0)
                addflag = true;
            else
                addflag = false;
            /* print more space(s) */
            for (j = 0; j < (avgblk + 1 * addflag); j++)
                printf(" ");
            /* print word */
            printf(" %s", line[i]);
            lastblk--;
        }
        printf("\n");
    # if DEBUG == 1
        for (i = 0; i < limit-1; i++)
            printf("-");
        printf("^\n\n");
    # endif
    }
# if DEBUG == 1
    fclose(fp);
# endif
    return 0;
}