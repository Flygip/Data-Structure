#include<iostream>
using namespace std;

void adjust_heap(int *array, int s, int m){
	int j, key=array[s];    //取处结点s处的值
	for(j=2*s+1; j<=m; j*=2){
		if(j<m&&array[j]<array[j+1])   //找出值大的孩子结点
			j++;
		if(key>array[j])  //s为值较大的结点，退出循环
			break;
		array[s]=array[j];   //否则将值较大的结点调整到s
		s=j;   //继续对子节点j进行调整
	}
	array[s]=key;  //将原来结点值插入
}

void creat_heap(int *array, int n){
	int i;
	for(i=n/2; i>=0; i--)  //i=n/2是从末尾结点的双亲结点开始调整
		adjust_heap(array, i, n);
}

int main(){
	int data[]={49,38,65,97,76,13,27,49};
	int i=0;

	creat_heap(data, 7);

	for(i=7; i>0; i--){
		int temp;
		temp=data[0];
		data[0]=data[i];
		data[i]=temp;
		adjust_heap(data, 0, i-1);
	}

	for(i=0; i<8; i++){
		cout<<data[i]<<" ";
	}
	return 0;
}
