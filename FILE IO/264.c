/* 264. Byte Frequency Count */
# include <stdio.h>
# include <assert.h>
# define range 65536
int main(void){
    char name[202];
    short num[range] = {0}, tmp, ans[2] = {0}; // 0: times, 1: the short number
    int i, size;
    scanf("%s", name);
    FILE * data = fopen(name, "rb");
    fread(&size, sizeof(int), 1, data); // note ~
    for (i = 0; i < size; i++){
        fread(&tmp, sizeof(short), 1, data);
        num[tmp + range/2]++;
    }
    for (i = 0; i < range; i++){
        if (num[i] >= ans[0])
            ans[0] = num[i], ans[1] = i - range/2;
    }
    printf("%hd\n%hd", ans[1], ans[0]);
    fclose(data);
    return 0;
}