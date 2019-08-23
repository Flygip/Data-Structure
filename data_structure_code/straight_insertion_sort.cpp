#include<iostream>
using namespace std;

void straight_insertion_sort(int *array){
	int temp,i,j;   //用来暂存需要插入的值

	for(i=1; i<8; i++){
		temp = array[i];
		for(j=i-1; temp<array[j]; j--)   //与有序序列比较，从后往前，方便后移
			array[j+1]=array[j];
		array[j+1]=temp;    //插入值
	}
}

int main(){
	int data[] = {49,38,65,97,76,13,27,49};

	straight_insertion_sort(data);

	for(int i=0; i<8; i++){
		cout<<data[i]<<" ";
	}
	return 0;
}
