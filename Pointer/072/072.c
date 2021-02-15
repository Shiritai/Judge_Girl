/* 72. Fill the Array */
// array of ptrs, ptr[0] : start pos, ptr[n-1] : end pos
void fill_array(int * ptr[], int n){
    int * tmpPtr = ptr[0], * tmpEnd;
    for (; tmpPtr <= ptr[n-1]; * tmpPtr = 0, tmpPtr++);
    for (int i = 0; i < n; ++i) * ptr[i] = i;
    tmpPtr = ptr[0];
    while (tmpPtr != ptr[n-1]){
        tmpEnd = tmpPtr+1;
        while (* tmpEnd == 0 && tmpEnd < ptr[n-1])  tmpEnd++;
        for (int add = (* (tmpPtr++)) + (* tmpEnd); tmpPtr < tmpEnd; ++tmpPtr)  * tmpPtr = add;
    }
}