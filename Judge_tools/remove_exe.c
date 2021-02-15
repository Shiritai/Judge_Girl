/* remove redundant .exe */
# include <stdio.h>
# include <io.h> // file manipulation
# include <string.h>
int main(void){
    long cntlCode; // catch control code
    int num = 0, flag = 0;
    struct _finddata_t file_info; // structure of file information
    cntlCode = _findfirst("*.exe", &file_info);
    if (strcmp(file_info.name, "remove_exe.exe") != 0){
        puts("____deleted file list____");
        flag = 1;
        ++num;
        printf("No.%d\t\"%s\"\n", num, file_info.name);
        remove(file_info.name);
    }
    while (_findnext(cntlCode, &file_info) == 0){
        if (strcmp(file_info.name, "remove_exe.exe") != 0){
            if (!flag){
                puts("____deleted file list____");
                flag = 1;
            }
            ++num;
            printf("No.%d\t\"%s\"\n", num, file_info.name);
            remove(file_info.name);
        }
    }
    if (flag)
        printf("deleted %d files\n", num);
    else 
        puts("executable file does not exist");
}