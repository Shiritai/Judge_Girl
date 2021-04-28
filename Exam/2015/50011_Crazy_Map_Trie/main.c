/* 50011. Spell Checker */

# include "Trie.h"
# define MAXLEN 101


// char ** getAllTrie(Trie * trie){
//     char result[trie->size][MAXLEN];
//     memset(result, "0", sizeof(char) * MAXLEN * trie->size);
//     tNode_t * cur = trie->root;

//     while (){
        
//     }
// }



int main(void){
    Trie * trie = newTrie();
    int num;
    scanf("%d", &num);
    char tmpStr[MAXLEN];
    while (num > 0){
        scanf("%s", tmpStr);
        addTrieString(trie, tmpStr);
        --num;
    }
    scanf("%d", &num);
    while (num > 0){
        scanf("%s", tmpStr);
        // printf("%d\n", trieContains(trie, tmpStr));
        printf("%d\n", trieContains(trie, tmpStr));
        --num;
    }
}