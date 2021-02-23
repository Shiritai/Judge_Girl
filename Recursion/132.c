/* 132. Color Countries */
# include <stdio.h>
# include <stdlib.h>

# define MAX_CITIES 20

int comp(const void * data1, const void * data2){
    return * (int *) data1 > * (int *) data2;
}

_Bool put_color(int);

typedef struct node {
    int color, connect_num;
    int connect[MAX_CITIES];
} node;

int node_num, colors, pair_num;

node nodes[MAX_CITIES];

int main(void){
    scanf("%d%d%d", &node_num, &colors, &pair_num);
    /* init nodes */
    for (int i = 0; i < MAX_CITIES; ++i){
        nodes[i].color = 0, nodes[i].connect_num = 0;
        for (int j = 0; j < MAX_CITIES; ++j)
            nodes[i].connect[j] = 0;
    }
    /* scan node data */
    for (int i = 0; i < pair_num; ++i){
        int jibun, aite;
        scanf("%d%d", &jibun, &aite);
        nodes[jibun].connect[nodes[jibun].connect_num] = aite;
        nodes[aite].connect[nodes[aite].connect_num] = jibun;
        nodes[jibun].connect_num++, nodes[aite].connect_num++;
    }
    for (int i = 0; i < node_num; ++i)
        qsort(nodes[i].connect, nodes[i].connect_num, sizeof(int), comp);
    /* check connetion data */
    // puts("");
    // for (int i = 0; i < node_num; ++i){
    //     printf("%d : ", i);
    //     for (int j = 0; j < nodes[i].connect_num; ++j)
    //         printf("%d ", nodes[i].connect[j]);
    //     puts("");
    // }
    // puts("");
    if (put_color(0)){
        for (int i = 0; i < node_num; ++i)
            printf("%d\n", nodes[i].color);
    }
    else
        puts("no solution.");
    return 0;
}

_Bool put_color(int cur_node){
    if (cur_node == node_num - 1){
        nodes[cur_node].color = 1;
        while (nodes[cur_node].color <= colors){  // try all colors
            int fal_flag = 0;
            for (int j = 0; j < nodes[cur_node].connect_num && !fal_flag; ++j){  // check all connected cities
                if (nodes[cur_node].color == nodes[nodes[cur_node].connect[j]].color)
                    fal_flag = 1;
            }
            if (!fal_flag) // no color conflict, the ONLY ONE difference from the "else" section at the very below 
            {
                // printf("%d --> %d\n", cur_node, nodes[cur_node].color);
                return 1;
            }
            else
                nodes[cur_node].color++;
        }
        return 0;
    }
    else {
        nodes[cur_node].color = 1;
        while (nodes[cur_node].color <= colors){  // try all colors
            int fal_flag = 0;
            for (int j = 0; j < nodes[cur_node].connect_num && !fal_flag; ++j){ // check all connected cities
                if (nodes[cur_node].color == nodes[nodes[cur_node].connect[j]].color)
                    fal_flag = 1;
            }
            if (!fal_flag && put_color(cur_node + 1)) // no color conflict
            {
                // printf("%d --> %d\n", cur_node, nodes[cur_node].color);
                return 1;
            }
            else
                nodes[cur_node].color++;
        }
        return 0;
    }
}