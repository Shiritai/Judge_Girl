# include "BSTMap.h"

void init(Map * map){
    map->root = NULL;
    map->size = 0;
    memset(map->stringMapVal, '\0', sizeof(char) * 1024 * 128);
}

int map(Map * map, const int key, const char * value){
    _Bool ret = mapContains(map, key);
    if (ret == false){
        strcpy(map->stringMapVal[map->size], value);
        addMapData(K_Int_Gen(key), V_String_Gen(map->stringMapVal + map->size));
    }
    return ret;
}

int numPairs(Map * map){
    return map->size;
}

void print(Map * map){
    puts("----- map begin -----");
    printOrder[1](map->root);
    puts("----- end       -----");
}

const char * getValue(Map * map, const int key){
    V * ret = getMapV(map, K_Int_Gen(key));
    assert(ret->type == V_STRING);
    return ret->data.stringVal;
}

int unmap(Map * map, int key){
    return (removeMapData(map, key) == NULL) ? 0 : 1;
}

int reverseMap(Map * map, const char * value, int keys[]){
    int sizeOfArr;
    K * kArr = getMapKArrayUseValue(map, value, &sizeOfArr);
    for (int i = 0; i < sizeOfArr;; ++i){
        keys[i] = kArr[i].data.intKey;
    }
    return sizeOfArr;
}