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

tNode_t * newTrieNode(int wordOrder){
    tNode_t * newTrieNode = (tNode_t *) malloc(sizeof(tNode_t));
    newTrieNode->wordOrder = wordOrder; // = 0 表示還沒有字
    newTrieNode->next = newMap();
    return newTrieNode;
}

Trie * newTrie(void){
    Trie * newTrie = (Trie *) malloc(sizeof(Trie));
    newTrie->root = newTrieNode(false);
    newTrie->size = 0;
    return newTrie;
}

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
    if (!cur->wordOrder)
        cur->wordOrder = ++(trie->size); // 為題目設計的, 因為需照順序印出
}

_Bool trieNodeContains(tNode_t * cur, char * str){
    return getTrieStringOrder(cur, str) != 0;
}

int getTrieStringOrder(tNode_t * cur, char * str){
    for (int i = 0, length = strlen(str); i < length; ++i){
        V * tmp = getMapV(cur->next, K_Char_Gen(str[i]));
        if (tmp == NULL)
            return 0;
        assert(tmp->data.trieNodePtrVal != NULL);
        cur = tmp->data.trieNodePtrVal;
    } 
    return cur->wordOrder;
}

_Bool trieContains(Trie * trie, char * str){
    // return trieNodeContains(trie->root, str);
    return getTrieStringOrder(trie->root, str) != 0;
}

/* 返回可能的 Pair_K_V <char, int> [pair_length], 
 * 其中 pair_length 儲存在 Pair_K_V[0] 的 key 
 * int 儲存 此字的 order
 */
Pair_K_V * replace_check(tNode_t * break_pt, char * str, int break_pos){
    int length = strlen(str);
    
    Pair_K_V * mapData = getAllPairs(break_pt->next);
    Pair_K_V * res = (Pair_K_V *) malloc(sizeof(Pair_K_V) * break_pt->next->size);
    int pair_length = 1; // 留一個位子存大小
    
    tNode_t * cur_tnode;
    int tmp_order;

    for (int i = 0; i < break_pt->next->size; ++i){
        /* 先前進一格 */
        cur_tnode = mapData[i].value.data.trieNodePtrVal;
        /* 確認是否略過一字 (replace) 後的單字存在, 並把略過的字符存下來 */
        for (int j = break_pos + 1; j < length; ++j){
            if (getMapV(cur_tnode->next, K_Char_Gen(str[j])) != NULL){
                if ((tmp_order = getTrieStringOrder(cur_tnode, str + j)) != 0){
                    res[pair_length].key.data.charKey = mapData[i].key.data.charKey;
                    res[pair_length++].value.data.intVal = tmp_order;
                }
            }
        }
    }
    res[0].key.data.intKey = pair_length;
    return res;
}

/* 第 0 位儲存 key : length of pair, value : common order */
Pair_K_V remove_check(tNode_t break_pt, char * str, int break_pos){
    int length = strlen(str);
    
    Pair_K_V * mapData = getAllPairs(break_pt->next); // 接下來有哪些字串
    Pair_K_V * res = (Pair_K_V *) malloc(sizeof(Pair_K_V) * break_pt->next->size);
    int pair_length = 1; // 留一個位子存大小
    
    tNode_t * cur_tnode;
    int tmp_order;

    for (int i = 0; i < break_pt->next->size; ++i){
        /* 先前進一格 */
        cur_tnode = mapData[i].value.data.trieNodePtrVal;
        /* 確認是否略過一字 (replace) 後的單字存在, 並把略過的字符存下來 */
        for (int j = break_pos + 1; j < length; ++j){
            if (getMapV(cur_tnode->next, K_Char_Gen(str[j])) != NULL){
                if ((tmp_order = getTrieStringOrder(cur_tnode, str + j)) != 0){
                    res[pair_length].key.data.charKey = mapData[i].key.data.charKey;
                    res[pair_length++].value.data.intVal = tmp_order;
                }
            }
        }
    }
    res[0].key.data.intKey = pair_length;
    return res;
}

Pair_K_V add_check(tNode_t break_pt, char * str, int break_pos){

}

/* 依照加入字典的順序比大小 */
int orderComp(const void * data1, const void * data2){
    Pair_K_V * p1 = (Pair_K_V *) data1;
    Pair_K_V * p2 = (Pair_K_V *) data2;
    return p1->value.data.intVal - p2->value.data.intVal;
}

/* Source 第一組資料是拿來讀屬性的, 因此特立此函式輔助結合 */
void write_Pair(Pair_K_V * destination, Pair_K_V * source){
    for (int i = 1, j = destination->key.data.intKey; i < source->key.data.intKey; ++i, ++j){
        destination[j] = source[i];
    }
}

/* 尋找相同 / 相似字 */
void * getTrieContains(Trie * trie, char * str){
    int length = strlen(str); // 字串長度
    // Pair_K_V * result = (Pair_K_V *) malloc(sizeof(Pair_K_V) * 3 * length);
    int pair_length = 1; // 儲存長度, 保留 0 號儲存 Pair_K_V (key) 長度

    tNode_t * cur = trie->root, * prev = trie->root, * next = NULL;

    if (trieContains(trie, str)){ // 直接有現成的單字
        printf(">%s\n", str);
        return;
    }

    Pair_K_V * replaceCheck = (Pair_K_V *) malloc(sizeof(Pair_K_V) * length + 1);
    replaceCheck[0].key.data.intKey = 1; // init
    Pair_K_V * removeCheck = (Pair_K_V *) malloc(sizeof(Pair_K_V) * length + 1);
    removeCheck[0].key.data.intKey = 1; // init
    Pair_K_V * addCheck = (Pair_K_V *) malloc(sizeof(Pair_K_V) * length + 2);
    addCheck[0].key.data.intKey = 1; // init

    Pair_K_V * checker; // 資料暫存器
    Pair_K_V * someMap; // 一份字典暫存器

    int rpl_size = 0;
    int rm_size = 0;
    int add_size = 0;

    for (int i = 0; i < length; ++i){
        V * tmp = getMapV(cur->next, K_Char_Gen(str[i]));
        if (tmp == NULL){
            checker = replace_check(prev, str, i);
            write_Pair(replaceCheck, checker);

            checker = remove_check(prev, str, i);
            write_Pair(removeCheck, checker);

            checker = add_check(prev, str, i)
            write_Pair(addCheck, checker);
        }
        assert(tmp->data.trieNodePtrVal != NULL);
        prev = cur;
        cur = tmp->data.trieNodePtrVal;
    }
    /* 沒有相似字 */
    if (replaceCheck[0].key.data.intKey == 1 && \
        removeCheck[0].key.data.intKey == 1 && \
        addCheck[0].key.data.intKey == 1){
        printf("!%s\n", str);
    }
    /* 印出相似字 */
    putchar('?'); // 開頭
    /* Sort! */
    int x_lim = replaceCheck[0].key.data.intKey, y_lim = removeCheck[0].key.data.intKey, z_lim = addCheck[0].key.data.intKey;
    qsort(replaceCheck + 1, x_lim - 1, sizeof(replaceCheck[1]), orderComp);
    qsort(removeCheck + 1, y_lim - 1, sizeof(removeCheck[1]), orderComp);
    qsort(addCheck + 1, z_lim - 1, sizeof(addCheck[1]), orderComp);
    // int total_length = x_lim + y_lim + z_lim;
    /* printing supporting variables */
    int x = 1, y = 1, z = 1;
    _Bool printBlank = false; // 處理列印格式
    char * buf = (char *) malloc(sizeof(char) * length + 2);
    /* Merge and print data */
    while (!(x == x_lim && y == y_lim && z == z_lim)){
        int rpl = replaceCheck[x].value.data.intVal;
        int rm = removeCheck[y].value.data.intVal;
        int add = addCheck[z].value.data.intVal;
        /* 處理列印格式 */
        if (printBlank){
            putchar(' ');
        }
        if (rpl > rm && rpl > add){
            strcpy(buf, str);
            buf[i] = replaceCheck[x++].key.data.charKey;
            printf("%s", buf);
        }
        if (rm > rpl && rm > add){
            memmove(buf, str, sizeof(char) * i);
            strcpt(buf + i, str);
            printf("%s", buf);
        }
        if (add > rm && add > rpl){
            strcpy(buf, str);
            buf[i] = addCheck[z++].key.data.charKey;
            printf("%s", buf);
        }
        /* 處理列印格式 */
        printBlank = true;
    }
    puts(""); // 處理列印格式
}