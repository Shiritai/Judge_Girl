# include <stdio.h>
# include <assert.h>
void call(void){
    goto end;
    end:;
    puts("end in call");
}
int main(void){
    char tmp[10] = " "/* , * tmpPtr = tmp + 1 */;
    sprintf(tmp, "%sM", tmp);
    sprintf(tmp, "%se", tmp);
    sprintf(tmp, "%so", tmp);
    sprintf(tmp, "%sw", tmp/* +1 */);
    // sprintf(tmp, "%sw", tmpPtr);
    puts(tmp);
}