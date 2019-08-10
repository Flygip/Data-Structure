#define MAXSIZE 20   //队列的最大长度
#include<iostream>
using namespace std;

typedef struct{
	int Data[MAXSIZE];
	int front;
	int rear;
}Queue;
Queue *PtrQ;

Queue *MakeEmpty(){  //初始化一个空队列
	Queue *p;
	p = (Queue *)malloc(sizeof(Queue));
	p->front = p->rear = -1;
	return p;
}

void add_queue(Queue *PtrQ, int x){
	if(PtrQ->front == MAXSIZE){   //判断队列是否已满
		cout<<"队列已满";
		return;
	}//不满则入队
	PtrQ->Data[++(PtrQ->rear)] = x;
}

int out_queue(Queue *PtrQ){
	if(PtrQ->front == PtrQ->rear){
		cout<<"队列为空";
		return -1;
	}//不为空则出队
	return PtrQ->Data[++(PtrQ->front)];
}

int main(){
	int i;
	int data[] = {0,1,2,3,4,5};
	//初始化
	PtrQ = MakeEmpty();
	//入队列
	for(i=0; i<6; i++){
		add_queue(PtrQ, data[i]);
	}
	//出队列
	for(i=0; i<6; i++){
		cout<<out_queue(PtrQ)<<" ";
	}
	return 0;
}
