// /* 50011. Spell Checker */
// /* Map + Trie */
// # include <stdio.h>
// # include <string.h>
// # include <stdlib.h>

// typedef struct map_t Map;
// typedef struct mNode_t mNode_t;
// // typedef struct trie_t Trie;
// // typedef struct tNode_t tNode_t;


// /* 儲存一個整數或字符 */
// typedef union {
//     int intKey;
//     char charKey;
// } union_K;

// /* 封裝 K */
// typedef struct {
//     unsigned short type;
//     union_K data;
// } K;

// enum K_type {
//     K_INT, K_CHAR
// };


// /* K_INT 大者返回正, 小者返回負, 相等返回 */
// int K_compare(const K k1, const K k2){
//     if (k1.type == k2.type){
//         if (k1.type == K_INT)
//             return k1.data.intKey - k2.data.intKey;
//         else if (k1.type == K_CHAR)
//             return k1.data.charKey - k2.data.charKey;
//     }
//     puts("Error comparasion!");
//     return 0;
// }


// /* 儲存一個 tNode_t 或整數 */
// typedef union {
//     Map * mapPtrVal;
//     int intVal;
// } union_V;

// /* 封裝 V */
// typedef struct {
//     unsigned short type;
//     union_V data;
// } V;

// enum V_type {
//     V_MAP_PTR, V_INT,
// };


// /* Map 需要的結構 */
// struct mNode_t {
//     K key;
//     V value;
//     mNode_t * left, * right;
// };

// /* mNode 建立函數 */
// mNode_t * newMapNode(K key, V value){
//     mNode_t * newMapNode = (mNode_t *) malloc(sizeof(mNode_t));

//     newMapNode->key.type = key.type;

//     if (key.type == K_INT)
//         newMapNode->key.data.intKey = key.data.intKey;
//     else if (key.type == K_CHAR)
//         newMapNode->key.data.charKey = key.data.charKey;

//     newMapNode->value.type = value.type;

//     if (value.type == V_INT)
//         newMapNode->value.data.intVal = value.data.intVal;
//     else if (value.type == V_MAP_PTR)
//         newMapNode->value.data.mapPtrVal = value.data.mapPtrVal;

//     newMapNode->left = newMapNode->right = NULL;
//     return newMapNode;
// }

// struct map_t {
//     struct mNode_t * root;
//     int size;
// };

// /* 創建空 Map */
// Map * newMap(void){
//     Map * new_map = (Map *) malloc(sizeof(Map));
//     new_map->root = NULL;
//     new_map->size = 0;
//     return new_map;
// }

// /* 確認 map 是否為空 */
// _Bool isMapEmpty(Map * someMap){ return someMap->size == 0;}

// /* 確認 Map 大小 */
// int getMapSize(Map * someMap){ return someMap->size;}



// typedef enum FUNC {
//     ADD, CONTAIN, SEARCH
// } FUNC;
// /* *
//  * dive from root node and find the proper parent node
//  * 嘗試特定出 node, 並返回之 
//  * */
// mNode_t * dive(Map * map, K key, V * value, FUNC func){
//     mNode_t * tmp = map->root, * prev = NULL;
//     int direction = 0; // non
//     while (tmp != NULL){
//         if (K_compare(key, tmp->key) < 0)
//             prev = tmp, tmp = tmp->left, direction = 1;
//         else if (K_compare(key,  tmp->key) > 0)
//             prev = tmp, tmp = tmp->right, direction = 2;
//         else { // 成功找到
//             switch (func){
//                 case ADD: // 插入 -> 更新 value, 若未找到跳出迴圈 (tmp == NULL), return add() 新增 node
//                     tmp->value.type = value->type;
//                     if (value->type == V_INT)
//                         tmp->value.data.intVal = value->data.intVal;
//                     else if (value->type == V_MAP_PTR)
//                         tmp->value.data.mapPtrVal = value->data.mapPtrVal;
//                     return tmp;
//                 case CONTAIN: // 包含 -> return 同樣 key 的 node 回去就好
//                     return tmp;
//                 case SEARCH: // 搜尋 -> return node
//                     return tmp;
//                 default:
//                     puts("Switch error");
//             }
//         }
//     }
//     if (func == ADD){
//         if (direction == 1)
//             prev->left = tmp = newMapNode(key, * value);
//         else if (direction == 2)
//             prev->right = tmp = newMapNode(key, * value);
//         // else // direction == 0
//         //     tmp = newMapNode(key, * value);
//         ++(map->size);
//     }
//     return tmp;
// }



// /* 為 Map 新增資料 */
// void addMapData(Map * map, K key, V value){
//     if (dive(map, key, &value, ADD) == NULL)
//         map->root = newMapNode(key, value);
//     // map->root = addMapNode(map, map->root, key, value);
// }

// /* Map 新增資料的輔助函數, 採遞迴 */
// // mNode_t * addMapNode(Map * map, mNode_t * cur, K key, V value){
// //     if (cur == NULL){
// //         ++map->size;
// //         return newMapNode(key, value);
// //     }
// //     if (key, cur->key)
// //         cur->left = addMapNode(map, cur->left, key, value);
// //     else if (key > cur->key)
// //         cur->right = addMapNode(map, cur->right, key, value);
// //     else  // key == cur->key
// //         cur->value = value;
// //     return cur;
// // }

// /* 取節點的輔助函式, 採遞迴 */
// // mNode_t * getMapNode(mNode_t cur, K key){
// //     if (cur != NULL){
// //         if (key < cur->key)
// //             return getMapNode(cur->left, key);
// //         else if (key > cur->key)
// //             return getMapNode(cur->right, key);
// //         else // key == cur->key
// //             return cur;
// //     }
// //     return NULL;
// // }

// /* 判斷輔助函式 */
// _Bool mapContains(Map * map, K key){ 
//     // return getMapNode(cur, key) != NULL
//     return dive(map, key, NULL, CONTAIN) != NULL;
// }

// /* 返回值的指標, 錯誤則返回 NULL */
// V * getMapV(Map * map, K key){
//     // mNode_t tmp = getMapNode(map, key);
//     mNode_t * tmp = dive(map, key, NULL, SEARCH);
//     return (tmp != NULL) ? &(tmp->value) : NULL;
// }

// /* 刪除節點的輔助函式, 採遞迴 */
// // mNode_t * removeMapNode(mNode_t cur, K key){
// //     if (cur != NULL){
// //         if (key < cur->key)
// //             return removeMapNode(cur->left, key);
// //         else if (key > cur->key)
// //             return removeMapNode(cur->right, key);
// //         else { // cur->key == key
// //             if (cur->left == NULL){
// //                 mNode_t comb = cur->right;
// //                 free(cur);
// //                 return comb;
// //             }
// //         }
// //     }
// //     return NULL;
// // }

// mNode_t * removeMapNode(Map * map, mNode_t * cur, K key){
//     if (cur == NULL)
//         return NULL;
//     if (K_compare(key, cur->key) < 0)
//         cur->left = removeMapNode(map, cur->left, key);
//     else if (K_compare(key, cur->key))
//         cur->right = removeMapNode(map, cur->right, key);
//     else { // cur->key == key
//         mNode_t * successor = NULL;
//         if (cur->left == NULL)
//             successor = cur->right;
//         else if (cur->right == NULL)
//             successor = cur->left;
//         else { // cur->left != NULL && cur->right != NULL
//             mNode_t * tmp = cur->right, * prev = NULL;
            
//             while (tmp->left != NULL){
//                 prev = tmp;
//                 tmp = tmp->left;
//             }

//             if (tmp != cur->right)
//                 prev->left = tmp->right;
//             else 
//                 cur->right = tmp->right;
            
//             successor = newMapNode(tmp->key, tmp->value);
//             free(tmp);
//             --(map->size);
//             return successor;
//         }
//     }
//     return cur;
// }

// /* 給定 key, 搜尋並刪除後返回其值 (value) 的指標 */
// V * removeMapData(Map * map, K key){
//     // mNode_t tmp = getMapNode(map, key);
//     mNode_t * tmp = dive(map, key, NULL, SEARCH);
//     if (tmp != NULL){
//         map->root = removeMapNode(map, map->root, key);
//         return &(tmp->value);
//     }
//     return NULL;
// }

// void preOrder(mNode_t * cur){
//     if (cur != NULL){
//         if (cur->key.type == K_INT)
//             printf("int key : %d, int value : %d\n", cur->key.data.intKey, cur->value.data.intVal);
//         else if (cur->key.type == K_CHAR)
//             printf("char key : %c\n", cur->key.data.charKey);
//         preOrder(cur->left);
//         preOrder(cur->right);
//     }
// }

// void inOrder(mNode_t * cur){
//     if (cur != NULL){
//         inOrder(cur->left);
//         if (cur->key.type == K_INT)
//             printf("int key : %d, int value : %d\n", cur->key.data.intKey, cur->value.data.intVal);
//         else if (cur->key.type == K_CHAR)
//             printf("key : %c\n", cur->key.data.charKey);
//         inOrder(cur->right);
//     }
// }

// void postOrder(mNode_t * cur){
//     if (cur != NULL){
//         postOrder(cur->left);
//         postOrder(cur->right);
//         if (cur->key.type == K_INT)
//             printf("int key : %d, int value : %d\n", cur->key.data.intKey, cur->value.data.intVal);
//         else if (cur->key.type == K_CHAR)
//             printf("key : %c\n", cur->key.data.charKey);
//     }
// }
// /* 0 : preOrder, 1 : inOrder, 2 : postOrder */
// void (* printOrder[3])(mNode_t *) = {
//     preOrder,
//     inOrder,
//     postOrder
// };

// int freeMapNode(mNode_t * cur){
//     if (cur != NULL){
//         int freeNum = freeMapNode(cur->left);
//         freeNum += freeMapNode(cur->right);
//         free(cur);
//         return freeNum + 1;
//     }
//     return 0;
// }

// void freeMap(Map * map){ map->size -= freeMapNode(map->root);}



// // struct trie {
// //     struct node {
// //         _Bool isWord;
// //         Map next;
// //     };
// //     struct node root;
// //     int size;
// // };

// K intKGen(int key){ return (K){.data.intKey = key, .type = K_INT};}
// K charKGen(char key){ return (K){.data.charKey = key, .type = K_CHAR};}

// V intTGen(int value){ return (V){.data.intVal = value, .type = V_INT};}
// V charTGen(Map * value){ return (V){.data.mapPtrVal = value, .type = V_MAP_PTR};}

// int main(void){
//     Map * head = newMap();

//     addMapData(head, intKGen(1), intTGen(2));
//     printOrder[0](head->root);
//     puts("");

//     addMapData(head, intKGen(-1), intTGen(-2));
//     printOrder[1](head->root);
//     puts("");

//     addMapData(head, intKGen(2), intTGen(3));
//     printOrder[2](head->root);
//     puts("");
    
//     addMapData(head, intKGen(0), intTGen(1));
//     printOrder[0](head->root);
//     puts("");
//     printOrder[1](head->root);
//     puts("");
//     printOrder[2](head->root);
//     puts("");
// }