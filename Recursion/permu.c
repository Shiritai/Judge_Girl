// C program to print all permutations with duplicates allowed 
#include <stdio.h> 
#include <string.h> 
/* Function to swap values at two pointers */
void swap(char* x, char* y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
 
/* Function to print permutations of string 
   This function takes three parameters: 
   1. String 
   2. Starting index of the string 
   3. Ending index of the string. */
void permute(char* a, int l, int r) 
{ 
    if (l == r) 
        printf("%s\n", a); 
    else { 
        for (int i = l; i <= r; i++) { 
            swap((a + l), (a + i)); 
            permute(a, l + 1, r); 
            swap((a + l), (a + i)); // backtrack 
        } 
    } 
} 
/* Driver program to test above functions */
int main() 
{ 
    char str[] = "ABC"; 
    int n = strlen(str); 
    permute(str, 0, n - 1); 
    return 0; 
} 
// void permute(int * cur, int l, int r){
//     if (l == r){
//         for (int i = 0; i < num; ++i)
//             printf("%d%c", *(cur+i), " \n"[i == num - 1]);
//     }
//     else {
//         /* 反的 */
//         // for (int i = 0; i <= r - l; ++i){
//         //     swap(cur + r - i, cur + r);
//         //     permute(cur, l, r - 1);
//         //     swap(cur + r - i, cur + r);
//         // }
//         /* 正的, 但非要求 */
//         // for (int i = 0; i <= r - l; ++i){
//         //     swap(cur + l, cur + l + i);
//         //     permute(cur, l + 1, r);
//         //     swap(cur + l, cur + l + i);
//         // }
//         /* 正的, 也不合要求 */
//         // for (int i = l; i <= r; ++i){
//         //     swap(cur + l, cur + i);
//         //     permute(cur, l + 1, r);
//         //     swap(cur + l, cur + i);
//         // }
//     }       
// }