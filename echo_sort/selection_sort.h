#include <iostream>
#include <cstring>
#include <math.h>
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void select_sort(int array[], int low, int high){
	if(array == NULL || low >= high || low < 0)
		return;
	for(int i = low; i < high; i++){
		int temp = i;
		for(int j = i + 1; j <= high; j++){
			if(array[j] < array[temp])
				temp = j;
		}
		if(i != temp)
			swap(array[i],array[temp]);
	}
	return;
}