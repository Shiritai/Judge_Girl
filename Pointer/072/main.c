#include <stdio.h>
void fill_array(int * ptr[], int n){
    int * tmpPtr = ptr[0], * tmpEnd;
    for (; tmpPtr <= ptr[n-1]; * tmpPtr = 0, tmpPtr++);
    for (int i = 0; i < n; ++i)
        * ptr[i] = i;
    tmpPtr = ptr[0];
    while (tmpPtr != ptr[n-1]){
        tmpEnd = tmpPtr+1;
        while (* tmpEnd == 0 && tmpEnd < ptr[n-1]){
            tmpEnd++;
        }
        tmpPtr++;
        for (int add = (* (tmpPtr-1)) + (* tmpEnd); tmpPtr < tmpEnd; ++tmpPtr)
            * tmpPtr = add;
    }
}
int main() {
    int arr[100] = {};
    int *ptr[100];
    int n = 6, m = 0;
    int A[100] = {0, 5, 6, 9, 3, 12};
    for (int i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m)    m = A[i];
    }
    fill_array(ptr, n);
    for (int i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}