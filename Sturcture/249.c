/* 249. staffs */
/* digraph! (tree) */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# define staffNum 32

typedef struct employee {
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
    struct employee * upPtr;
} staff;

staff * staffs[staffNum];
int staff_ind = 0;

void build_link(void){
    for (int i = 0; i < staff_ind; ++i){
        for (int j = 0; j < staff_ind; ++j){
            if (staffs[i]->boss_id == staffs[j]->id){
                staffs[i]->upPtr = staffs[j];
                break;
            }
        }
    }
}

staff * init(staff * tmp){
    staff * new = (staff *) malloc(sizeof(staff));
    assert(new != NULL);
    strcpy(new->first_name, tmp->first_name);
    strcpy(new->last_name, tmp->last_name);
    new->id = tmp->id, new->boss_id = tmp->boss_id;
    new->upPtr = NULL;
    return new;
}

staff * find_staff(staff * only_name){
    for (int i = 0; i < staff_ind; ++i){
        if (!strcmp(only_name->first_name, staffs[i]->first_name) && !strcmp(only_name->last_name, staffs[i]->last_name))
            return staffs[i];
    }
    return NULL;
}

char * relation(staff * a, staff * b){
    staff * tmpA = a, * tmpB = b;
    while (tmpA != NULL && tmpA != tmpA->upPtr){
        if (tmpA->upPtr == b)
            return "subordinate";
        tmpA = tmpA->upPtr;
    }
    while (tmpB != NULL && tmpB != tmpB->upPtr){
        if (tmpB->upPtr == a)
            return "supervisor";
        tmpB = tmpB->upPtr;
    }
    if (tmpA != tmpB)
        return "unrelated";
    else 
        return "colleague";
}

int main(void){
    int n, m;
    staff tmp1, tmp2;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d%s%s%d", &tmp1.id, tmp1.first_name, tmp1.last_name, &tmp1.boss_id);
        staffs[staff_ind] = init(&tmp1);
        ++staff_ind;
    }
    build_link();
    scanf("%d", &m);
    while (m > 0){
        scanf("%s%s%s%s", tmp1.first_name, tmp1.last_name, tmp2.first_name, tmp2.last_name);
        puts(relation(find_staff(&tmp1), find_staff(&tmp2)));
        --m;
    }
    return 0;
}