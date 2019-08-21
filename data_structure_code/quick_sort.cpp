#include<iostream>
using namespace std;

int find_key(int low, int high, int *array){
	int key=array[low];   //保存枢轴值
	while(high>low){
		while(high>low && array[high]>=key)
			--high;
		array[low] = array[high];  //比枢轴值小交换
		while(high>low && array[low]<=key)
			++low;
		array[high] = array[low];  //比枢轴值大交换
	}
	array[low] = key;   //将枢轴值插入
	return low;
}

void quick_sort(int low, int high, int *array){
	int key_position;
	if(high>low){
		key_position = find_key(low, high, array);
		quick_sort(low, key_position-1, array);
		quick_sort(key_position+1, high, array);
	}
}
int main(){
	int data[] = {49,38,65,97,76,13,27,49};
	quick_sort(0, 7, data);

	for(int i=0; i<8; i++){
		cout<<data[i]<<" ";
	}
	return 0;
}
