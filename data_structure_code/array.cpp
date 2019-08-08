#define MAXSIZE 100   //定义表的最大长度
#include<iostream>
using namespace std;

typedef struct Node{   //定义结点
	int Data[MAXSIZE];
	int Last;    //保存数组长度
}List;
List L,*PtrL;

List *MakeEmpty(){
	List *PtrL;
	//分配一个List(Node)大小的连续内存空间
	PtrL = (List *)malloc(sizeof(List));
	PtrL->Last = -1;   //初始化Last
	return PtrL;
}

void Insert(int x, int i, List *PtrL){
	int j = 0;
	if(i > MAXSIZE){
		cout<<"表满";
		return;
	}
	if(i < 1 || i > PtrL->Last + 2){ 
		//如果位置不在表头到表尾则不合法
		cout<<"插入位置不合法";
		return;
	}
	//将i到PtrL->Last后面的元素后移一个位置
	for(j = PtrL->Last; j >= i; j--){
		PtrL->Data[j+1] = PtrL->Data[j];
	}
	PtrL->Data[i-1] = x;  //在i处插入x
	PtrL->Last++;  //结尾下标加1
}

void Delete(int i, List *PtrL){
	int j = 0;
	if(i < 1 || i > PtrL->Last + 1){
		cout<<"不存在第"<<i<<"个元素";
		return;
	}
	//将i到PtrL->Las前面的元素后移一个位置
	for(j = i-1; j < PtrL->Last; j++){
		PtrL->Data[j] = PtrL->Data[j+1];
	}
	PtrL->Last--;   //结尾下标减1
}

int Find(int x, List *PtrL){
	int i = 0;
	//遍历
	while(i <= PtrL->Last && PtrL->Data[i] != x){
		i++;   
	}
	if(i > PtrL->Last){
		return -1;  //未找到返回-1
	}
	else{
		return i;  //找到了返回下标i
	}
}

void Print(List *PtrL){
	int i = 0;
	while(i <= PtrL->Last){
		cout<<PtrL->Data[i];
		i++;
	}
}
int main(){
	int data[] = {1,2,3,4,5,6};

	cout<<"初始化!";
    PtrL = MakeEmpty();    //初始化表

	cout<<"\n建表";
	for(int i = 0; i < 6; i++){   //建表
		Insert(data[i], i+1, PtrL);
	}

	cout<<"->打印:";
	Print(PtrL);  //打印表

	cout<<"\n删除第二个元素";
	Delete(2, PtrL);   //删除第二个元素
	
	cout<<"->打印:";
	Print(PtrL);   //打印删除后的表

    cout<<"\n查找5的位置为:";
	cout<<Find(5, PtrL);   //寻找5的位置
	return 0;
}
