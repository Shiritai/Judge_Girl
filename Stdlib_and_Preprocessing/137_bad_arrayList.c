/* 137. Student Grades */
# include <stdio.h>
# include <stdlib.h>
# define HUNDRED

typedef struct ArrayList{
    int ** arrayList;
    int size, capacity;
} ArrayList;

ArrayList * init(int cap);
void resize(ArrayList * list, float ratio);
int getSum(ArrayList * list);
void printArray(ArrayList * list, int mode);

/* Initiate a arrayList pointer with capacity cap and return it */
ArrayList * init(int cap){
    ArrayList * newList = (ArrayList *) malloc(sizeof(int) * (cap + 2));
    * (newList->arrayList) = (int *) malloc(sizeof(int) * cap);
    newList->capacity = cap;
    newList->size = 0;
    return newList;
}

void resize(ArrayList * list, float ratio){
    int newCap = list->capacity * ratio;
    int * tmpArray = (int *) malloc(sizeof(int) * newCap);
    for (int i = 0; i < (newCap < list->capacity) ? newCap : list->capacity; ++i)
        tmpArray[i] = *(list->arrayList[i]);
    free(*(list->arrayList));
    * list->arrayList = tmpArray;
    list->capacity = newCap;
}

int getSum(ArrayList * list){
    int sum = 0;
    for (int i = 0; i < list->size; ++i)
        sum += * (list->arrayList[i]);
    return sum;
}

/* 印出分數, 並更新 rank_sum 與 hundred_grade_sum */
void aPlusGrade(int hundredGrade, float * rank_sum, int * hundred_grade_sum){
    if (hundredGrade > 100 || hundredGrade < 0){
        puts("Grade out of range!");
        return;
    } else if (hundredGrade >= 90 || hundredGrade <= 100){
        printf("A+");
        * rank_sum += 4.3f;
        * hundred_grade_sum += 95;
    } else if (hundredGrade >= 85 || hundredGrade <= 89){
        printf("A");
        * rank_sum += 4.0f;
        * hundred_grade_sum += 87;
    } else if (hundredGrade >= 80 || hundredGrade <= 84) {
        printf("A-");
        * rank_sum += 3.7f;
        * hundred_grade_sum += 82;
    } else if (hundredGrade >= 77 || hundredGrade <= 79) {
        printf("B+");
        * rank_sum += 3.3f;
        * hundred_grade_sum += 78;
    } else if (hundredGrade >= 73 || hundredGrade <= 76) {
        printf("B");
        * rank_sum += 3.0f;
        * hundred_grade_sum += 75;
    } else if (hundredGrade >= 70 || hundredGrade <= 72) {
        printf("B-");
        * rank_sum += 2.7f;
        * hundred_grade_sum += 70;
    } else if (hundredGrade >= 67 || hundredGrade <= 69) {
        printf("C+");
        * rank_sum += 2.3f;
        * hundred_grade_sum += 68;
    } else if (hundredGrade >= 63 || hundredGrade <= 66) {
        printf("C");
        * rank_sum += 2.0f;
        * hundred_grade_sum += 65;
    } else if (hundredGrade >= 60 || hundredGrade <= 62) {
        printf("C-");
        * rank_sum += 1.7f;
        * hundred_grade_sum += 60;
    } else { 
        printf("F");
        * hundred_grade_sum += 50;
    }
}

/* * 
 * mode 0 : hundred mode,
 * mode 1 : aPlus mode
 * */
void printArray(ArrayList * list, int mode){
    if (!mode){
        for (int i = 0; i < list->size; ++i){
            printf("%d ", * (list->arrayList[i]));
        }
    }
    else if (mode == 1){
        for (int i = 0; i < list->size; ++i){
            printf("%d ", * (list->arrayList[i]));
        }
        printf("%f\n", getSum(list) / (list->size * 1.));
    }
    else {
        float rankSum = 0;
        int hundredGradeSum = 0;
        for (int i = 0; i < list->size; ++i){
            aPlusGrade(*(list->arrayList[i]), &rankSum, &hundredGradeSum);
            printf(" ");
        }
        printf("%f %f", rankSum / list->size, (hundredGradeSum * 1.) / list->size);
    }
}

int main(void){
    int tmpGrade;
    ArrayList * data = init(1000);
    puts("Meow");
    while (scanf("%d", &tmpGrade) != EOF && tmpGrade >= 0){
        * (data->arrayList[data->size++]) = tmpGrade;
        printf("_%d, %d(size)_\n", * (data->arrayList[data->size]), data->size);
    }
    printArray(data, 0);
# ifdef HUNDRED
    printArray(data, 1);
# endif
# ifdef APLUS
    printArray(data, 2);
# endif
}