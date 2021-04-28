/* Preperasion for 50011. Spell Checker */
/* Trie */
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <assert.h>
# include "BSTMap.h"
# define true 1
# define false 0

typedef struct trie_t Trie;

struct trie_t {
    tNode_t * root;
    int size;
};

tNode_t * newTrieNode(_Bool isWord){
    tNode_t * newTrieNode = (tNode_t *) malloc(sizeof(tNode_t));
    newTrieNode->isWord = isWord;
    newTrieNode->order = 0;
    newTrieNode->next = newMap();
    return newTrieNode;
}

Trie * newTrie(void){
    Trie * newTrie = (Trie *) malloc(sizeof(Trie));
    newTrie->root = newTrieNode(false);
    newTrie->size = 0;
    return newTrie;
}

int getTrieSize(Trie * trie){ return trie->size; }

void addTrieString(Trie * trie, char * str){
    tNode_t * cur = trie->root;

    for (int i = 0, length = strlen(str); i < length; ++i){
        V * tmp = getMapV(cur->next, K_Char_Gen(str[i]));
        if (tmp == NULL)
            addMapData(cur->next, K_Char_Gen(str[i]), V_Trie_Node_Ptr_Gen(newTrieNode(false)));
        tmp = getMapV(cur->next, K_Char_Gen(str[i]));
        assert(tmp->data.trieNodePtrVal != NULL);
        cur = tmp->data.trieNodePtrVal;
    }
    if (!cur->isWord){
        cur->isWord = true;
        cur->order = ++(trie->size);
    }
}

// _Bool trieNodeContains(tNode_t * cur, char * str){
//     for (int i = 0, length = strlen(str); i < length; ++i){
//         V * tmp = getMapV(cur->next, K_Char_Gen(str[i]));
//         if (tmp == NULL)
//             return 0;
//         assert(tmp->data.trieNodePtrVal != NULL);
//         cur = tmp->data.trieNodePtrVal;
//     } 
//     return cur->isWord;
// }


int getTrieStringOrder(tNode_t * cur, char * str){
    for (int i = 0, length = strlen(str); i < length; ++i){
        V * tmp = getMapV(cur->next, K_Char_Gen(str[i]));
        if (tmp == NULL)
            return 0;
        assert(tmp->data.trieNodePtrVal != NULL);
        cur = tmp->data.trieNodePtrVal;
    } 
    return cur->isWord;
}

_Bool trieContains(Trie * trie, char * str){
    // return trieNodeContains(trie->root, str);
    return getTrieStringOrder(trie->root, str) != 0;
}

int main(void){
    Trie * head = newTrie();
    addTrieString(head, "Meow");
    printf("%d\n", trieContains(head, "Meow"));
    printf("%d\n", trieContains(head, "Me"));
    printf("%d\n", trieContains(head, "Meows"));
    printf("%d\n", trieContains(head, "A Meow"));
    addTrieString(head, "A Meow");
    printf("%d\n", trieContains(head, "Meow"));
    printf("%d\n", trieContains(head, "Me"));
    printf("%d\n", trieContains(head, "Meows"));
    printf("%d\n", trieContains(head, "A Meow"));
}