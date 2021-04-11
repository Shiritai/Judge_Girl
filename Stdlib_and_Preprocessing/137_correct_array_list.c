/* 137. Student Grades */
# include <stdio.h>
# include <stdlib.h>

int * arrayList;
int size, capacity;

void init(int cap);
void resize(float ratio);
int getSum();
void printArray(int mode);

/* Initiate a arrayList pointer with capacity cap and return it */
void init(int cap){
    arrayList = (int *) malloc(sizeof(int));
    capacity = cap;
    size = 0;
}

void resize(float ratio){
    int newCap = capacity * ratio;
    int * tmpArray = (int *) malloc(sizeof(int) * newCap);
    for (int i = 0; i < (newCap < capacity) ? newCap : capacity; ++i)
        tmpArray[i] = arrayList[i];
    free(arrayList);
    arrayList = tmpArray;
    capacity = newCap;
}

int getSum(){
    int sum = 0;
    for (int i = 0; i < size; ++i)
        sum += arrayList[i];
    return sum;
}

/* 印出分數, 並更新 rank_sum 與 hundred_grade_sum */
void aPlusGrade(int hundredGrade, float * rank_sum, int * hundred_grade_sum){
    if (hundredGrade > 100 || hundredGrade < 0){
        puts("Grade out of range!");
        return;
    } else if (hundredGrade >= 90 && hundredGrade <= 100){
        printf("A+");
        * rank_sum += 4.3f;
        * hundred_grade_sum += 95;
    } else if (hundredGrade >= 85 && hundredGrade <= 89){
        printf("A");
        * rank_sum += 4.0f;
        * hundred_grade_sum += 87;
    } else if (hundredGrade >= 80 && hundredGrade <= 84) {
        printf("A-");
        * rank_sum += 3.7f;
        * hundred_grade_sum += 82;
    } else if (hundredGrade >= 77 && hundredGrade <= 79) {
        printf("B+");
        * rank_sum += 3.3f;
        * hundred_grade_sum += 78;
    } else if (hundredGrade >= 73 && hundredGrade <= 76) {
        printf("B");
        * rank_sum += 3.0f;
        * hundred_grade_sum += 75;
    } else if (hundredGrade >= 70 && hundredGrade <= 72) {
        printf("B-");
        * rank_sum += 2.7f;
        * hundred_grade_sum += 70;
    } else if (hundredGrade >= 67 && hundredGrade <= 69) {
        printf("C+");
        * rank_sum += 2.3f;
        * hundred_grade_sum += 68;
    } else if (hundredGrade >= 63 && hundredGrade <= 66) {
        printf("C");
        * rank_sum += 2.0f;
        * hundred_grade_sum += 65;
    } else if (hundredGrade >= 60 && hundredGrade <= 62) {
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
 * mode !0 : aPlus mode
 * */
void printArray(int mode){
    if (!mode){
        for (int i = 0; i < size; ++i){
            printf("%d ", arrayList[i]);
        }
        printf("%.1f\n", getSum() / (size * 1.));
    }
    else {
        float rankSum = 0;
        int hundredGradeSum = 0;
        for (int i = 0; i < size; ++i){
            aPlusGrade(arrayList[i], &rankSum, &hundredGradeSum);
            printf(" ");
        }
        printf("%.1f %.1f", rankSum / size, (hundredGradeSum * 1.) / size);
    }
}

int main(void){
    int tmpGrade;
    init(1000);
    while (scanf("%d", &tmpGrade) != EOF && tmpGrade >= 0)
        arrayList[size++] = tmpGrade;
# ifdef HUNDRED
    printArray(0);
# elif defined APLUS
    printArray(1);
# endif
}