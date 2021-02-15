/* 210. SQL Database */
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# define lenLimit 80
# define dataNum 52
# define DEBUG 0
typedef struct data_SQL {
    char lastname[lenLimit], firstname[lenLimit], ID[lenLimit];
    int salary, age;
} SQL;
int wanted(char * str);
void condCheck(SQL * data, char * op1, char * opt, char * op2, int * tag, int range, int printlen);
void printdata(SQL * data, int * printTag, int len);
int main(void){
    int n, i;
    scanf("%d", &n);
    SQL data[dataNum] = {"", "", "", 0, 0}; // initialization
    /* input data */
    SQL * sPtr = data;
    for (i = 0; i < n; sPtr++, i++){
        scanf("%s %s %s %d %d\n", &sPtr->lastname, &sPtr->firstname, \
            &sPtr->ID, &sPtr->salary, &sPtr->age);
    }
# if DEBUG == 1 //i.e. print check in my definition 
    sPtr = data;
    for (i = 0; i < n; sPtr++, i++){
        printf("%s_%s_%s_%d_%d\n", sPtr->lastname, sPtr->firstname, \
            sPtr->ID, sPtr->salary, sPtr->age);
    }
# endif
    /* search engine */
    int search;
    char seastr[10000], operator[2], operand1[lenLimit], operand2[lenLimit];
    scanf("%d\n", &search);
    for (; search > 0; search--){
        fgets(seastr, 0x7fffffff, stdin);
        char * start = seastr, delemiter[] = " ";
        int mark[1000] = {0}, mNum = 0;
        bool whereCond = false;
        /* skip "select" */
        start = strtok(start, delemiter);
        /* load search */
        start = strtok(NULL, delemiter);
        while (start != NULL){
            mark[mNum] = wanted(start);
            // printf("mark[%d] = %d\n", mNum, mark[mNum]);
            if (!mark[mNum]){ // where
                start = strtok(NULL, delemiter);
                strcpy(operand1, start);
                start = strtok(NULL, delemiter);
                strcpy(operator, start);
                start = strtok(NULL, "\n"); // since the last word is '\n'
                strcpy(operand2, start);
                break; // end of loop
            }
            start = strtok(NULL, delemiter);
            mNum++;
        }
        /* manipulate search and print */
        condCheck(data, operand1, operator, operand2, mark, n, mNum);
    }
    return 0;
}
int wanted(char * str){
    if (!strcmp(str, "lastname")){
        return 5;
    }
    else if (!strcmp(str, "firstname")){
        return 4;
    }
    else if (!strcmp(str, "ID")){
        return 3;
    }
    else if (!strcmp(str, "salary")){
        return 2;
    }
    else if (!strcmp(str, "age")){
        return 1;
    }
    else if (!strcmp(str, "where")){
        return 0;
    }
    else 
        printf("Something is wrong\n");
    return -1;
}
void condCheck(SQL * data, char * op1, char * opt, char * op2, int * tag, int range, int printlen){
    /* clarify condition */
    int i;
    SQL * ptr = data;
    switch (wanted(op1)){
        case 1:
            for (i = 0; ptr != NULL && i < range; ptr++, i++){
                if (!strcmp(opt, "==")){
                    if (ptr->age == atoi(op2))
                        printdata(ptr, tag, printlen);
                }
                else if (!strcmp(opt, ">")){
                    if (ptr->age > atoi(op2))
                        printdata(ptr, tag, printlen);
                }
                else if (!strcmp(opt, "<")){
                    if (ptr->age < atoi(op2))
                        printdata(ptr, tag, printlen);
                }
            }
            break;
        case 2:
            for (i = 0; ptr != NULL && i < range; ptr++, i++){
                if (!strcmp(opt, "==")){
                    if (ptr->salary == atoi(op2))
                        printdata(ptr, tag, printlen);
                }
                else if (!strcmp(opt, ">")){
                    if (ptr->salary > atoi(op2))
                        printdata(ptr, tag, printlen);
                }
                else if (!strcmp(opt, "<")){
                    if (ptr->salary < atoi(op2))
                        printdata(ptr, tag, printlen);
                }
            }
            break;
        case 3:
            for (i = 0; ptr != NULL && i < range; ptr++, i++){
                if (!strcmp(opt, "==")){
                    if (!strcmp(ptr->ID, op2))
                        printdata(ptr, tag, printlen);
                }
                else if (!strcmp(opt, "!=")){
                    if (strcmp(ptr->ID, op2))
                        printdata(ptr, tag, printlen);
                }
            }
            break;
        case 4:
            for (i = 0; ptr != NULL && i < range; ptr++, i++){
                if (!strcmp(opt, "==")){
                    if (!strcmp(ptr->firstname, op2))
                        printdata(ptr, tag, printlen);
                }
                else if (!strcmp(opt, "!=")){
                    if (strcmp(ptr->firstname, op2))
                        printdata(ptr, tag, printlen);
                }
            }
            break;
        case 5:
            for (i = 0; ptr != NULL && i < range; ptr++, i++){
                if (!strcmp(opt, "==")){
                    if (!strcmp(ptr->lastname, op2))
                        printdata(ptr, tag, printlen);
                }
                else if (!strcmp(opt, "!=")){
                    if (strcmp(ptr->lastname, op2) != 0)
                        printdata(ptr, tag, printlen);
                }
            }
            break;
        default:
            break;
    }
}
void printdata(SQL * data, int * printTag, int len){
    int i;
    for (i = 0; i < len-1; i++){ // print to the second last section for print format
        switch (printTag[i]){
            case 5:
                printf("%s ", data->lastname);
                break;
            case 4:
                printf("%s ", data->firstname);
                break;
            case 3:
                printf("%s ", data->ID);
                break;
            case 2:
                printf("%d ", data->salary);
                break;
            case 1:
                printf("%d ", data->age);
                break;
            default:
                break;
        }
    }
    switch (printTag[len-1]){
        case 5:
            printf("%s\n", data->lastname);
            break;
        case 4:
            printf("%s\n", data->firstname);
            break;
        case 3:
            printf("%s\n", data->ID);
            break;
        case 2:
            printf("%d\n", data->salary);
            break;
        case 1:
            printf("%d\n", data->age);
            break;
        default:
            break;
    }
    return;
}