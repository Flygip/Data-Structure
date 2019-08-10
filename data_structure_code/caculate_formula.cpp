#define MAXSIZE 20  //堆栈的最大长度
#include<string>
#include<iostream>
using namespace std;

char  Priority[7] = {'#','-','+','*','/','(',')'};   //定义优先级,#为标识符
int ascll_num[10] = {48,49,50,51,52,53,54,55,56,57};  //数字的ascll码
int left_bracket;   //记录(的位置
bool bracket = false;     //记录是否有括号

typedef struct{
	int Data[MAXSIZE];
	int Top;
}Stack;
Stack *PtrS_Int, *PtrS_Char;   //声明指针

Stack *MakeEmpty(Stack *PtrS){   //初始化栈
	Stack *p;
	p = (Stack *)malloc(sizeof(Stack));    //分配Stack大小的空间
	PtrS = p;
	PtrS->Top = -1;
	return PtrS;
}
Stack *Push(int x, Stack *PtrS){   //入栈
    if(PtrS->Top == MAXSIZE - 1){
        cout<<"栈满";
        return NULL;
    }
    else{   //入栈操作
        PtrS->Data[++(PtrS->Top)] = x;
        return PtrS;
    }
}
int Pop(Stack *PtrS){   //出栈
	if(PtrS->Top == -1){
		cout<<"栈空";
		return -1;
	}
	else{
		return PtrS->Data[(PtrS->Top)--];
	}
}
int char_to_int(char x){  //将字符转换为数字(49-57)ASCLL码表
	int value = 0;
	while(ascll_num[value] != int(x)){
		value++;
	}
	return value;
}
int char_order(char ch){   //返回符号优先级
	int order = 0;
	while(Priority[order] != ch){
		order++;
	}
	return order;
}
//表达式的分布计算
int Caculate(int num1, int num2, char op, Stack *PtrS_Int){
	int result = 0;
		switch(int(op)){
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num2 - num1;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			result = num2 / num1;
			break;
	}
	PtrS_Int->Data[++(PtrS_Int->Top)] = result;  //将结果入栈
	return result;
}
void Analyse(Stack *PtrS_Int, Stack *PtrS_Char, char read_char){
	char top_char = char(Pop(PtrS_Char));   //取栈顶元素
  int read_char_order = char_order(read_char);   //计算优先级
	int top_char_order = char_order(top_char);
  
	if(read_char == '('){   //记录右括号的位置
		Push(top_char, PtrS_Char);   //将top_char重新入栈
		left_bracket = PtrS_Char->Top;    //记录括号位置
		bracket = true;   //有括号
		return;
	}
	else if(read_char == ')'){   //遇到右括号,则计算(之前的运算
		while(left_bracket <= PtrS_Char->Top){
			int num1 = Pop(PtrS_Int);    //出栈两个数
			int num2 = Pop(PtrS_Int);
			Caculate(num1, num2, top_char, PtrS_Int);
			top_char = char(Pop(PtrS_Char));   //取栈顶运算符
		}
		Push(top_char, PtrS_Char);    //多拿出来的入栈
		bracket = false;    //括号标志标为false
		return;
	}
	if(!bracket){   //做无括号操作
		if(top_char_order <= read_char_order){    //优先级大于栈顶元素,入栈
			Push(top_char, PtrS_Char);
			Push(read_char, PtrS_Char);
		}
		else if(top_char_order > read_char_order){    //否则计算
			int num1 = Pop(PtrS_Int);    //从栈顶获取两个数
			int num2 = Pop(PtrS_Int);
			Caculate(num1, num2, top_char, PtrS_Int);
			Analyse(PtrS_Int, PtrS_Char, read_char);    //递归
		}
	}
	else{    //遇到(时，直接将后续运算符入栈
		Push(top_char, PtrS_Char);
		Push(read_char, PtrS_Char);
	}
}
void read_string(Stack *PtrS_Int, Stack *PtrS_Char, string s){   //分离串
	int  i = 0;
	int value;
	while(s[i] != '\0'){
		if(48 <= int(s[i]) && int(s[i]) <= 57){ //提取数字
			value = char_to_int(s[i]);   //转换位数字
			Push(value, PtrS_Int);   //数字入栈
		}
		else{ //分析字符
			Analyse(PtrS_Int, PtrS_Char, s[i]);
		}
		i++;
	}
}
int main(){
	string formula; //= "3*(4+4/2)*2-1";
	cout<<"Input Formula:";
	cin>>formula;
	formula = formula + '#';   //尾部标识符
	//初始化两个栈
	PtrS_Int = MakeEmpty(PtrS_Int);
	PtrS_Char = MakeEmpty(PtrS_Char);
	Push('#', PtrS_Char);   //将标识符放在栈底
	//读字符串
	read_string(PtrS_Int, PtrS_Char, formula);
	//打印结果
	cout<<"Result:"<<PtrS_Int->Data[(PtrS_Int->Top)--]<<endl;
	return 0;
}
