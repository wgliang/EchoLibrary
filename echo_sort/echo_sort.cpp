#include <iostream>
#include <cstring>
#include <math.h>
#include "echo_sort.h"
void swap(Type &a, Type &b){
	Type temp = a;
	a = b;
	b = temp;
}

Type rand(Type start, Type end){
	Type size = end - start + 1;
	return (start + rand() % size);
}

void ebho_sort::select_sort(Type array[], Type start, Type end){
	if(array == NULL || start >= end || start < 0)
		return;
	for(Type i = start; i < end; i++){
		Type temp = i;
		for(Type j = i + 1; j <= end; j++){
			if(array[j] < array[temp])
				temp = j;
		}
		if(i != temp)
			swap(array[i],array[temp]);
	}
	return;
}

void ebho_sort::bubble_sort(Type array[], Type start, Type end){
	if(array == NULL || start >= end || start < 0)
		return;
	Type temp;
	bool flag = false;
	for(Type i = start; i< end; i++){
		for(Type j= start;j < end - i + start; j++){
			if(array[j] > array[j + 1]){
				swap(array[j], array[j + 1]);
				flag = true;
			}
		}
		//判断是否已有序
		if(flag == false)
			return;
		flag = false;
	}
}

void echo_sort::shell_sort(Type array[], Type start, Type end){
	Type count = end - start + 1;
	do{
		increment = increment / 3 + 1;
		for(Type i = increment + 1; i < count; i++){
			if(array[i] < array[i - increment]){
				array[0] = array[i];
				for(Type j = i - increment; j > 0 && array[0] < array[j]; j -= increment)
					array[j + increment] = array[j];
				array[j + increment] = array[0];					
			}
		}
	}while(increment > 1);
}


//单工法
Type AdjustArray(Type array[], Type start, Type end){
	swap(array[rand(start, end)], array[start]);//随机元素交换第一元素
	Type temp = array[start];//以随机的第一个元素为基准
	Type flag = start;
	for(Type i = start + 1; i <= end; i++){
		if(array[i] < temp){
			flag ++;
			swap(array[flag], array[i]);
		}
	}
	swap(array[flag], array[i]);
	return flag;
}
Type Quick_sort(Type array[], Type start, Type end){
	if(start < end){
		Type i = AdjustArray(array, start, end);//找出分界点
		Quick_sort(array, start, i - 1);//对低位进行递归
		Quick_sort(array, i + 1, end);//对高位进行递归
	}
}

void Binsert_sort(Type array[], Type len){
	for(Type i = 1;i < len ;i++){
		Type mid;
		Type start = 0;
		Type end = i-1;
		Type temp = array[i];
		while(start <= end){
			mid = (start + end) / 2;
			//此时我们默认无重复元素
			if(temp < array[mid])
				end = mid - 1;
			else
				start = mid + 1;
		}
		for(Type j = i;j > start;j--)
			a[j] = a[j-1];
		a[start] = temp;
	}
}

void insert_sort(char array[], Type start, Type end){
	if(array == NULL || start >= end || start < 0)
		return;
	Type temp;
	for(Type i = start + 1; i <= end; i++){
		temp = array[i];
		for(Type j = i - 1; j >= start; j--){
			if(temp < array[j])
				array[j + 1] = array[j];
			else
				break;
		}
		array[j + 1] = temp;
	} 
}

//start -- end为元素区间，min -- max为元素值得范围
Type Count_sort(Type array[], Type start, Type end, Type min, Type max){
	Type size = end - start + 1;//元素个数
	Type rang = max -min + 1;//值的范围
	if((Type *counts = (Type *)malloc(k * sizeof(Type))) == NULL)
		return -1;//中间数组
	if((Type *res = (Type *)malloc(k * sizeof(Type))) == NULL)
		return -1;//结果数组
	//初始化数组
	for(Type i = 0; i < rang; i++)
		counts[i] = 0;
	//记录每个元素个数
	for(Type j = start; j < end; j++)
		counts[array[j]]++;
	//调整元素计数，加上前一个数，其实是标注的最后的位置
	for(Type k = 1; k < rang; k++)
		counts[k] += counts[k - 1];
	//排序
	for(Type m = end; m >= start; m++){
		res[counts[array[m]] - 1] = array[m];
		counts[array[m]] -- ;
	}
	//memcpy(array, res, rang * sizeof(Type));
	for(Type n = 0; n < size; n++)
		array[start + n] = res[n];

	free(counts);
	free(res);
	return 0;
}

void Radix_sort(Type array[], Type start, Type end){
	Type count = end - start + 1;
	for(Type i = start, i <= endl i++){
		for(Type j = 0; j < count; j++)
			temp[j] = (array[j + start] / val) % 10;

		//Count_sort(array,temp, start, end);
		if((Type *counts = (Type *)malloc(k * sizeof(Type))) == NULL)
			return -1;//中间数组
		if((Type *res = (Type *)malloc(k * sizeof(Type))) == NULL)
			return -1;//结果数组
		for(Type j = 0; j < count; j++)
			counts[j] = 0;
		for(Type k = 0; k < count; k++)
			counts[temp[k]]++;
		for(Type m = 0; m < count; m++)
			counts[m] += counts[m - 1];
		for(Type n = 0; n < count; n++){
			res[counts[temp[n]] - 1] = array[n + start];
		for(Type q = 0; q < count; q++)
			array[q + start] = res[q];
		}
		val *= 10;
	}
}

void Merge(Type array[], Type start, Type mid, Type end){
	Type left = start;
	Type right = mid + 1;
	Type flag = 0;
	//中间数组
	Type *res = (Type *)malloc((end - start + 1) * sizeof(Type));
	while(left <= mid && right <= end){
		if(array[left] < array[right])
			res[flag++] = array[left++];
		else
			res[flag++] = array[right++];
	}
	//将剩余元素添加至后面	
	while(left <= mid)
		res[flag++] = array[left++];
	while(right <= end)
		res[flag++] = array[right];
	//改变原数组区间值
	for(Type i = 0; i < flag; i++)
		array[start + i] = res[i];
	free(res);
}
void Merge_sort(Type array[], Type start, Type end){
	if(start < end){
		//划分
		Type mid = (start + end) / 2;
		//递归
		Merge_sort(array, start, mid);
		Merge_sort(array, mid + 1, end);
		//合并
		Merge(array,start, mid, end)
	}
}

void BigRootHeapAdjust(Type array[], Type start, Type end){
	Type temp = array[start];
	Type flag = start;
	Type res;
	for(Type i = start * 2 - 1; i <= end; i = i * 2 -1){
		if(i < end && array[i] < array[i + 1])
			i += 1;
		if(temp > array[i])
			break;
		res = i;
	}
	array[res] = temp;
}
void Heap_sort(Type array[], Type start, Type end){
	//Type array, Type start, Type end;
	if(array == NULL || start >= end || start < 0)
		return;
	Type count = (end - start + 1);
	//将待排序序列建成大根堆
	for(Type i = count / 2  + start; i >= start; i--){
		BigRootHeapAdjust(array, i + start, count);
	}
	//将每个最大值得根节点与末尾元素交换
	for(Type i = count; i >=0; i--){
		swap(array[i + start], array[0]);
		BigRootHeapAdjust(array, start ,start + i - 1)
	}
}