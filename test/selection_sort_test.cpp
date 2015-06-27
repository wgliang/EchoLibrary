#include <iostream>
#include <cstring>
#include <math.h>
#include "selection_sort.h"
using namespace std;
int main(){
	int a[10] = {10,4,5,552,154361,515,525,4643,1421,2};

/*	select_sort(a,0,9);
	for(int i = 0; i < 10; i++){
		cout<< a[i] <<" ";
	}
	cout<<endl;
	*/
	select_sort(a,3,4);
	for(int i = 0; i < 10; i++){
		cout<< a[i] <<" ";
	}
	cout<<endl;
	select_sort(a,1,5);
	for(int i = 0; i < 10; i++){
		cout<< a[i] <<" ";
	}
	cout<<endl;

	return 0;
}
