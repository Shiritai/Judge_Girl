/* 89. File Encoding */
# include <stdio.h>
# include <assert.h>
# define MaxBuf 65536
int main(void){
    int XOR, tmpLen, i;
    scanf("%d", &XOR);
    FILE *test = fopen("test", "rb");
    FILE *test_enc = fopen("test.enc", "wb");
    assert(test != NULL && test_enc != NULL);
    char buf[MaxBuf];
    /* fread / fwrite */
    while ((tmpLen = fread(buf, sizeof(char), MaxBuf, test)) != 0){
        for (i = 0; i < tmpLen; i++){
            buf[i] ^= XOR;
        }
        fwrite(buf, sizeof(char), tmpLen, test_enc);
    }
    fclose(test), fclose(test_enc);
    return 0;
}