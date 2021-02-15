#include "max.h"
int max(int array[5][5]){
	int maxNum = 0, i, j;
	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++){
			if (array[i][j] > maxNum){
				maxNum = array[i][j];
			}
		}
	}
	return maxNum;
}