/* Preparasion for 50011. Spell Checker */
/* Map */
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>
# define false 0
# define true 1

typedef struct map_t Map;
typedef struct mNode_t mNode_t;
typedef struct tNode_t tNode_t;


/* 儲存一個整數或字符 */
typedef union {
    int intKey;
    char charKey;
} union_K;

/* 封裝 K */
typedef struct {
    unsigned short type;
    union_K data;
} K;

enum K_type {
    K_INT, K_CHAR
};

struct tNode_t {
    int wordOrder;
    Map * next;
};

/* K_INT 大者返回正, 小者返回負, 相等返回 */
int K_compare(const K * k1, const K * k2){
    if (k1->type == k2->type){
        if (k1->type == K_INT)
            return k1->data.intKey - k2->data.intKey;
        else if (k1->type == K_CHAR)
            return k1->data.charKey - k2->data.charKey;
    }
    puts("Error comparasion!");
    return 0;
}


/* 儲存一個 tNode_t 或整數 */
typedef union {
    tNode_t * trieNodePtrVal;
    Map * mapPtrVal;
    char * stringVal;
    int intVal;
} union_V;

/* 封裝 V */
typedef struct {
    unsigned short type;
    union_V data;
} V;

enum V_type {
    V_MAP_PTR, V_INT, V_TRIE_NODE_PTR, V_STRING
};


/* Map 需要的結構 */
struct mNode_t {
    K key;
    V value;
    mNode_t * left, * right;
};

/* mNode 建立函數, 傳入 key ptr, value ptr, 建立新節點, 深度複製後返回 */
mNode_t * newMapNode(K * keyPtr, V * valuePtr){
    mNode_t * newMapNode = (mNode_t *) malloc(sizeof(mNode_t));
    assert(newMapNode != NULL);
    newMapNode->key = * keyPtr;
    newMapNode->value = * valuePtr;
    newMapNode->left = newMapNode->right = NULL;
    return newMapNode;
}

struct map_t {
    struct mNode_t * root;
    int size;
    char stringMapVal[1024][128]; // for 50018. Map
};

/* 創建空 Map */
Map * newMap(void){
    Map * new_map = (Map *) malloc(sizeof(Map));
    assert(new_map != NULL);
    new_map->root = NULL;
    new_map->size = 0;
    return new_map;
}


typedef enum FUNC {
    ADD, SEARCH
} FUNC;
/* *
 * dive from root node and find the proper parent node
 * 嘗試特定出 node, 並返回之 
 * */
mNode_t * dive(Map * map, K * key, V * value, FUNC func){
    mNode_t * tmp = map->root, * prev = NULL;
    int direction = 0; // non
    while (tmp != NULL){
        if (K_compare(key, &(tmp->key)) < 0)
            prev = tmp, tmp = tmp->left, direction = 1;
        else if (K_compare(key,  &(tmp->key)) > 0)
            prev = tmp, tmp = tmp->right, direction = 2;
        else { // 成功找到
            switch (func){
                case ADD: // 插入 -> 更新 value, 若未找到跳出迴圈 (tmp == NULL), return add() 新增 node
                    tmp->value.type = value->type;
                    if (value->type == V_INT)
                        tmp->value.data.intVal = value->data.intVal;
                    else if (value->type == V_MAP_PTR)
                        tmp->value.data.mapPtrVal = value->data.mapPtrVal;
                    else if (value->type == V_TRIE_NODE_PTR)
                        tmp->value.data.trieNodePtrVal = value->data.trieNodePtrVal;
                    else if (value->type == V_STRING)
                        tmp->value.data.stringVal = value->data.stringVal;
                    return tmp;
                case SEARCH: // 搜尋 -> return node
                    return tmp;
                default:
                    puts("Switch error");
            }
        }
    }
    if (func == ADD){
        if (direction == 1)
            prev->left = tmp = newMapNode(key, value);
        else if (direction == 2)
            prev->right = tmp = newMapNode(key, value);
        // else // direction == 0
        //     tmp = newMapNode(key, * value);
        ++(map->size);
    }
    return tmp;
}



/* 為 Map 新增資料 */
void addMapData(Map * map, K key, V value){
    if (dive(map, &key, &value, ADD) == NULL)
        map->root = newMapNode(&key, &value);
    // map->root = addMapNode(map, map->root, key, value);
}

/* 判斷輔助函式 */
_Bool mapContains(Map * map, K key){ 
    // return getMapNode(cur, key) != NULL
    return dive(map, &key, NULL, SEARCH) != NULL;
}

/* 返回值的指標, 錯誤則返回 NULL */
V * getMapV(Map * map, K key){
    // mNode_t tmp = getMapNode(map, key);
    mNode_t * tmp = dive(map, &key, NULL, SEARCH);
    return (tmp != NULL) ? &(tmp->value) : NULL;
}


mNode_t * removeMapNode(Map * map, mNode_t * cur, K * key){
    if (cur == NULL)
        return NULL;
    if (K_compare(key, &(cur->key)) < 0)
        cur->left = removeMapNode(map, cur->left, key);
    else if (K_compare(key, &(cur->key)))
        cur->right = removeMapNode(map, cur->right, key);
    else { // cur->key == * key
        mNode_t * successor = NULL;
        if (cur->left == NULL)
            successor = cur->right;
        else if (cur->right == NULL)
            successor = cur->left;
        else { // cur->left != NULL && cur->right != NULL
            mNode_t * tmp = cur->right, * prev = NULL;
            
            while (tmp->left != NULL){
                prev = tmp;
                tmp = tmp->left;
            }

            if (tmp != cur->right)
                prev->left = tmp->right;
            else 
                cur->right = tmp->right;
            
            successor = newMapNode(&(tmp->key), &(tmp->value));
            free(tmp);
            return successor;
        }
    }
    return cur;
}

/* 給定 key, 搜尋並刪除後返回其值 (value) 的指標 */
V * removeMapData(Map * map, K key){
    // mNode_t tmp = getMapNode(map, key);
    mNode_t * tmp = dive(map, &key, NULL, SEARCH);
    if (tmp != NULL){
        map->root = removeMapNode(map, map->root, &key);
        --(map->size);
        return &(tmp->value);
    }
    return NULL;
}

typedef struct {
    K key;
    V value;
} Pair_K_V;

void getMapInOrder(mNode_t * cur, Pair_K_V * arr, int * size){
    if (cur != NULL){
        getMapInOrder(cur->left, arr, size);
        arr[(* size)++] = (Pair_K_V) {.key = cur->key, .value = cur->value};
        getMapInOrder(cur->right, arr, size);
    }
}

Pair_K_V * getAllPairs(Map * map){
    Pair_K_V * res = (Pair_K_V *) malloc(sizeof(Pair_K_V) * map->size);
    int cnt = 0;
    getMapInOrder(map->root, res, &cnt);
    assert(cnt == map->size);
    return res;
}

void preOrder(mNode_t * cur){
    if (cur != NULL){
        if (cur->key.type == K_INT)
            printf("int key : %d, int value : %d\n", cur->key.data.intKey, cur->value.data.intVal);
        else if (cur->key.type == K_CHAR)
            printf("char key : %c\n", cur->key.data.charKey);
        preOrder(cur->left);
        preOrder(cur->right);
    }
}

void inOrder(mNode_t * cur){
    if (cur != NULL){
        inOrder(cur->left);
        if (cur->key.type == K_INT)
            printf("int key : %d, int value : %d\n", cur->key.data.intKey, cur->value.data.intVal);
        else if (cur->key.type == K_CHAR)
            printf("key : %c\n", cur->key.data.charKey);
        inOrder(cur->right);
    }
}

void postOrder(mNode_t * cur){
    if (cur != NULL){
        postOrder(cur->left);
        postOrder(cur->right);
        if (cur->key.type == K_INT)
            printf("int key : %d, int value : %d\n", cur->key.data.intKey, cur->value.data.intVal);
        else if (cur->key.type == K_CHAR)
            printf("key : %c\n", cur->key.data.charKey);
    }
}

/* 以 (char *) value 搜尋相符的 keys, inOrder */
void getKArrayUseValue(mNode_t * cur, K * arr, int * current_size, V * value){
    if (cur != NULL){
        getKArrayUseValue(cur->left, arr, current_size, value);
        if (!strcmp(cur->value.data.stringVal, value->data.stringVal)) // 50018 題
            arr[(* current_size)++] = cur->key;
        getKArrayUseValue(cur->right, arr, current_size, value);
    }
}

/* 給定 size_container 作為儲存陣列大小的容器,
 * 返回 (char *)) value 相應的 Key array
 */
K * getMapKArrayUseValue(Map * map, V * value, int * size_container){
    K * ret = (K *) malloc(sizeof(K) * map->size);
    * size_container = 0;
    getKArrayUseValue(map->root, ret, size_container, value);
    return ret;
}

/* 0 : preOrder, 1 : inOrder, 2 : postOrder */
void (* printOrder[3])(mNode_t *) = {
    preOrder,
    inOrder,
    postOrder
};

int freeMapNode(mNode_t * cur){
    if (cur != NULL){
        int freeNum = freeMapNode(cur->left);
        freeNum += freeMapNode(cur->right);
        free(cur);
        return freeNum + 1;
    }
    return 0;
}

void freeMap(Map * map){ map->size -= freeMapNode(map->root);}

K K_Int_Gen(int key){ return (K){.data.intKey = key, .type = K_INT};}
K K_Char_Gen(char key){ return (K){.data.charKey = key, .type = K_CHAR};}

V V_Int_Gen(int value){ return (V){.data.intVal = value, .type = V_INT};}
V V_Map_Ptr_Gen(Map * value){ return (V){.data.mapPtrVal = value, .type = V_MAP_PTR};}
V V_Trie_Node_Ptr_Gen(tNode_t * value){ return (V){.data.trieNodePtrVal = value, .type = V_TRIE_NODE_PTR};}
V V_String_Gen(char * value){ return (V){.data.stringVal = value, .type = V_STRING};}