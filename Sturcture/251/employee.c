/* 251. Company, Again */
/* 原本就是這樣寫的...完美 */
# include "employee.h"
# include <stdio.h>

int relation(Employee *employee1, Employee *employee2) {
    Employee * tmp1 = employee1, * tmp2 = employee2;
    while (tmp1 != NULL && tmp1 != tmp1->boss){
        if (tmp1->boss == employee2)
            return 1;
        tmp1 = tmp1->boss;
    }
    while (tmp2 != NULL && tmp2 != tmp2->boss){
        if (tmp2->boss == employee1)
            return 2;
        tmp2 = tmp2->boss;
    }
    if (tmp1 != tmp2)
        return 4;
    else
        return 3;
}