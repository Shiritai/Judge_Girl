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

struct tNode_t {
    int wordOrder;
    Map * next;
};

/* 儲存一個 tNode_t 或整數 */
typedef union {
    tNode_t * trieNodePtrVal;
    Map * mapPtrVal;
    char stringVal[128];
    int intVal;
} union_V;

/* 封裝 V */
typedef struct {
    unsigned short type;
    union_V data;
} V;

/* Map 需要的結構 */
struct mNode_t {
    K key;
    V value;
    mNode_t * left, * right;
};

struct map_t {
    struct mNode_t * root;
    int size;
};

void init(Map *);
int map(Map *, const int, const char *);
int numPairs(Map *);
void print(Map *);
const char * getValue(Map *, const int);
int unmap(Map *, int);
int reverseMap(Map *, const char *, int []);