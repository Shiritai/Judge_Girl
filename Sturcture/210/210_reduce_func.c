/* 210. SQL Database */
# include <stdio.h>
# include <string.h>
# include <stdlib.h> // atoi, itoa
# include <assert.h>

# define STR_LEN 82
# define USER_MAX 51

enum element {
    LASTNAME,
    FIRSTNAME,
    ID,
    SALARY,
    AGE
};

typedef struct person {
    char lastname[STR_LEN];
    char firstname[STR_LEN];
    char ID[STR_LEN];
    int salary;
    int age;
} person;

int n, m, select_col[8];
person data[USER_MAX];

void scan_data(int num){
    for (int i = 0; i < num; ++i)
        scanf("%s%s%s%d%d", data[i].lastname, data[i].firstname, data[i].ID, &data[i].salary, &data[i].age);
    return;
}

int select_(char * input){
    if (!strcmp(input, "lastname"))
        return LASTNAME;
    else if (!strcmp(input, "firstname"))
        return FIRSTNAME;
    else if (!strcmp(input, "ID"))
        return ID;
    else if (!strcmp(input, "salary"))
        return SALARY;
    else if (!strcmp(input, "age"))
        return AGE;
    else 
        return -1;
}

void print_selected_data(int ind, int selection, char * op, char * constant){
    /* deduce condition and filt satisfied data */
    _Bool selected[USER_MAX] = {};
    switch (selection){
        case LASTNAME: {
            if (!strcmp(op, "==")){
                for (int i = 0; i < n; ++i){
                    if (!strcmp(constant, data[i].lastname))
                        selected[i] = 1;
                }
            }
            else if (!strcmp(op, "!=")){
                for (int i = 0; i < n; ++i){
                    if (strcmp(constant, data[i].lastname))
                        selected[i] = 1;
                }
            }
            break;
        }
        case FIRSTNAME: {
            if (!strcmp(op, "==")){
                for (int i = 0; i < n; ++i){
                    if (!strcmp(constant, data[i].firstname))
                        selected[i] = 1;
                }
            }
            else if (!strcmp(op, "!=")){
                for (int i = 0; i < n; ++i){
                    if (strcmp(constant, data[i].firstname))
                        selected[i] = 1;
                }
            }
            break;
        }
        case ID:{
            if (!strcmp(op, "==")){
                for (int i = 0; i < n; ++i){
                    if (!strcmp(constant, data[i].ID))
                        selected[i] = 1;
                }
            }
            else if (!strcmp(op, "!=")){
                for (int i = 0; i < n; ++i){
                    if (strcmp(constant, data[i].ID))
                        selected[i] = 1;
                }
            }
            break;
        }
        case SALARY:{
            if (!strcmp(op, "==")){
                for (int i = 0; i < n; ++i){
                    if (data[i].salary == atoi(constant))
                        selected[i] = 1;
                }
            }
            else if (!strcmp(op, ">")){
                for (int i = 0; i < n; ++i){
                    if (data[i].salary > atoi(constant))
                        selected[i] = 1;
                }
            }
            else if (!strcmp(op, "<")){
                for (int i = 0; i < n; ++i){
                    if (data[i].salary < atoi(constant))
                        selected[i] = 1;
                }
            }
            break;
        }
        case AGE:{
            if (!strcmp(op, "==")){
                for (int i = 0; i < n; ++i){
                    if (data[i].age == atoi(constant))
                        selected[i] = 1;
                }
            }
            else if (!strcmp(op, ">")){
                for (int i = 0; i < n; ++i){
                    if (data[i].age > atoi(constant))
                        selected[i] = 1;
                }
            }
            else if (!strcmp(op, "<")){
                for (int i = 0; i < n; ++i){
                    if (data[i].age < atoi(constant))
                        selected[i] = 1;
                }
            }
            break;
        }
    }
    /* print */
    for (int i = 0; i < n; ++i){
        if (selected[i]){
            for (int j = 0; j < ind; ++j){
                switch (select_col[j]){
                    case LASTNAME:
                        printf("%s%c", data[i].lastname, " \n"[j == ind - 2]);
                        break;
                    case FIRSTNAME:
                        printf("%s%c", data[i].firstname, " \n"[j == ind - 2]);
                        break;
                    case ID:
                        printf("%s%c", data[i].ID, " \n"[j == ind - 2]);
                        break;
                    case SALARY:
                        printf("%d%c", data[i].salary, " \n"[j == ind - 2]);
                        break;
                    case AGE:
                        printf("%d%c", data[i].age, " \n"[j == ind - 2]);
                        break;
                }
            }
        }
    }
    return;
}

void cmd_select_(int num){
    for (int i = 0; i < num; ++i){
        char tmp[STR_LEN];
        scanf("%s", tmp);
        assert(!strcmp(tmp, "select"));
        int select_ind = 0;
        while (strcmp(tmp, "where")){
            scanf("%s", tmp);
            select_col[select_ind] = select_(tmp);
            ++select_ind;
        }
        assert(!strcmp(tmp, "where"));
        char operator[3], constant[STR_LEN];
        scanf("%s%s%s", tmp, operator, constant);
        print_selected_data(select_ind, select_(tmp), operator, constant);
    }
}

int main(void){
    scanf("%d", &n);
    scan_data(n);
    scanf("%d", &m);
    cmd_select_(m);
}