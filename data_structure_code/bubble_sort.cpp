#include<iostream>
using namespace std;

int main(){
	//初始数组
	int data[] = {49,38,65,97,76,13,27,49};
	int i = 8,j = 0;

	for(;0<i; i--){
		//判断是否交换，如果未交换，退出循环
		bool flag = false;
		for(j=0; j<i-1; j++){
			//如果逆序则交换
			if(data[j+1] < data[j]){
				int temp;
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
				flag = true;
			}
		}
		if(!flag){
			break;
		}
	}

	for(i=0; i<8; i++){
		cout<<data[i]<<" ";
	}
	return 0;
}
