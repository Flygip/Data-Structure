#include<iostream>
using namespace std;

void merging_insert(int *array, int *t_array, int low, int mid, int high){
	int i=low,j=mid+1,t=low;
	while(i<=mid&&j<=high){   //将array中记录由大到小插入到t_array
		if(array[i]<array[j])   //找到左枝和右枝较小值，插入到t_array
			t_array[t++] = array[i++];   //左枝较小进行插入
		else
			t_array[t++] = array[j++];   //右枝较小进行插入
	}
	//将左枝或者右枝剩余的值全部插入到t_array当中
	while(i<=mid)
		t_array[t++] = array[i++];
	while(j<=high)
		t_array[t++] = array[j++];

	for(i=0; i<j; i++)   //将和并好的值存在array中
		array[i] = t_array[i];
}

void merging_sort(int *array, int *t_array, int low, int high){
	if(low<high){
		int mid = low+(high-low)/2;   //计算分裂点
		merging_sort(array, t_array, low, mid);   //对左枝进行分裂
		merging_sort(array, t_array, mid+1, high);   //对右枝进行分裂
		merging_insert(array, t_array, low, mid, high);    //对左右枝进行合并排序
	}
}

int main(){
	int data[] = {49,38,65,97,76,13,27,16};
	int temp[8] = {0};   //暂时存储数组，初始化为0

	merging_sort(data, temp, 0, 7);

	for(int i=0; i<8; i++){
		cout<<temp[i]<<" ";
	}
	return 0;
}
