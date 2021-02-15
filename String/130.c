/* 130. Similar Strings */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define Len 10000
#define abs(x) ((x > 0) ? x : (-x))
bool check_1(char str1[], char str2[]);
bool check_2(char str1[], char str2[]);
int main(void)
{
    char str[2][Len] = {'\0'};
    int n, i;
    fscanf(stdin, "%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s%s", str[0], str[1]);
        if (check_1(str[0], str[1]) || check_2(str[0], str[1]))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
bool check_1(char str1[], char str2[])
{
    int size1 = strlen(str1), size2 = strlen(str2);
    if (size1 != size2)
        return false;
    int i, cnt = 0;
    for (i = 0; i < size1 && cnt <= 1; i++)
    {
        if (str1[i] != str2[i])
        {
            if (str1[i] == str2[i + 1] && str1[i + 1] == str2[i])
                i++, cnt++;
            else
                return false;
        }
    }
    if (cnt <= 1)
        return true;
    return false;
}
bool check_2(char str1[], char str2[])
{
    int size1 = strlen(str1), size2 = strlen(str2), i, j;
    if (abs((size1 - size2)) != 1)
        return false;
    int check = 0, bigone = (size1 > size2) ? 1 : 2;
    for (i = 0, j = 0; i < size1 && j < size2 && check <= 1;)
    {
        if (str1[i] != str2[j])
        {
            if (bigone == 1)
                i++;
            else if (bigone == 2)
                j++;
            check++;
        }
        else
            i++, j++;
    }
    if (check <= 1)
        return true;
    return false;
}