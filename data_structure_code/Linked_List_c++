#include<iostream>
using namespace std;

typedef struct Node{
	int Data;
	Node *Next;
}List;
List L, *PtrL;

List *FindKEle(int K, List *PtrL){
    List *p = PtrL;   //p指向表的第一个结点
    int i = 1;
    while(i < K && p != NULL){
        p = p->Next;
        i++;
    }
    if(i==K){
        return p;     //找到第K个元素，返回指针
    } 
    else return NULL;    //未找到返回空
}

int FindEle(int X, List *PtrL){
	int i = 0;
    List *p = PtrL;    //指向表第一个结点
    while(p != NULL && p->Data != X){
		++i;
        p = p->Next;
    }
    if(p != NULL){
        return i+1;    //找到则返回结点
    }
}

List *Insert(int i, int X, List *PtrL){
    List *p, *s;
    if(i == 1){    //如果在第一个结点插入，单独考虑
        s = (List *)malloc(sizeof(List));    //分配List大小的空间
        s->Data = X;
        s->Next = PtrL;
        PtrL = s;    //PtrL指向新的头结点s
		return PtrL;   //返回头结点
    }
    p = FindKEle(i-1, PtrL);   //找到第i-1个元素的结点并返回
    if(p == NULL){    //不存在第i个结点
        cout<<"插入位置不合法";
    }
    else{   //否则将结点插在i-1的后面
        s = (List *)malloc(sizeof(List));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
    }
	return PtrL;    //返回头结点
}

void Delete(int i, List *PtrL){
    List *p, *s;   
    if(i == 1){    //如果要删除的结点在第一个
        s = PtrL;
        PtrL = PtrL->Next;
        free(s);   //释放内存资源
    }
    p = FindKEle(i-1, PtrL);
    if(p == NULL){
        cout<<"无第"<<i<<"个元素";    //无该元素
    }
    else if(p->Next == NULL){
        cout<<"无第"<<i<<"个元素";
    }
    else{
        s = p->Next;    //删除节点
        p->Next = s->Next;
        free(s);    //释放内存资源
    }
}

int Length(List *PtrL){
    List *p = PtrL;    //将p指向表的第一个结点
    int j = 0;
    while(p){    //当指针不为空时，遍历表
        p = p->Next;
        j++;
    }
    return j;    //返回链表长度
}

void PrintList(){
	List *p = PtrL;
	while(p){
		cout<<p->Data;
		p = p->Next;
	}
}

int main(){
	int data[6] = {1,3,5,4,9,6};
	cout<<"MakeList:";
	for(int i = 0; i < 6; i++){
        PtrL = Insert(i+1, data[i], PtrL);
	}
	cout<<"Make Successfully!"<<endl;
	cout<<"PrintList:";
	PrintList();
	cout<<"  Length:"<<Length(PtrL)<<endl;
	
	cout<<"Find 3 at "<<FindEle(3, PtrL)<<endl;

	cout<<"Delete No.3:";
	Delete(3, PtrL);
	cout<<"Delete Successfully!"<<endl;

	cout<<"PrintList:";
	PrintList();
	return 0;
}
