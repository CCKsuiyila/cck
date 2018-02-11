//对 回忆一下自己的做题思路(最近每做一题就把这个粘过去)
//1.先理解题
//2.确定解题思路(选择数据结构算法什么的)   确定能解决正常情况,也不用考虑太多复杂度
//3.2达到之后, 开始考虑各种解决可能遇到的奇怪情况   然后看看有没有复杂度更低的思路

//这道题直接在原版上面修改了
//把申请内存的方式改成C++了   给类加了构造函数  可以灵活申请内存   改了改函数名啥的
#include<iostream>
#include<cstdio>
using namespace std;

class Stack{
	public:
		//注意：你不能添加更多的public函数或变量,如有需要可添加析构函数
		Stack(int length);
		bool empty();
		void push(int value);
		int pop();
		int top();
	private:
		//此处可以扩展
		int *array;
		int current_length;
		int max_size;
};

Stack::Stack(int length){
	array=new int[length];
	max_size = length;
	current_length=0;
	
}

bool Stack::empty(){
	if(current_length>0){
		return false;
	}
	if(current_length==0){
		return true;
	}
}

void Stack::push(int value){
	current_length=current_length+1;
	array[current_length]=value;
}

int Stack::pop(){
	int temporary=array[current_length];
	current_length=current_length-1;
	return temporary;
}

int Stack::top(){
	int temporary=array[current_length];
	return temporary;
}


class Queap{
	public:
		Queap(int length);
		void enqueap(int);
		int dequeap();
		int min();
	private:
		int current_length;
		int max_size;
		Stack* queap;
		Stack* backup;
};

Queap::Queap(int length){
	current_length=0;
	max_size = length;
	queap = new Stack(length+10);
	backup = new Stack(length+10);//
}

void Queap::enqueap(int value){
	queap->push(value);
	current_length=current_length+1;
}

int Queap::dequeap(){
	int head;
	int temporary;
	for(int i=0;i<current_length-1;i++){
		temporary=queap->pop();
		backup->push(temporary);
	}
	head=queap->pop();
	for(int i=0;i<current_length-1;i++){
		temporary=backup->pop();
		queap->push(temporary);
	}
	current_length=current_length-1;
	return head;
}

int Queap::min(){
	int minimum=queap->top();
	int temporary;
	for(int i=0;i<current_length;i++){
		temporary=queap->pop();
		if(temporary<minimum){
			minimum=temporary;
		}
		backup->push(temporary);
	}
	for(int i=0;i<current_length;i++){
		temporary=backup->pop();
		queap->push(temporary);
	}
	return minimum;
}

int main(){
	int n;
	fscanf(stdin,"%d",&n);
	getchar();
	Queap myqueap(n);
	char act;
	int number;
	for(int i=0;i<n;i++){
		fscanf(stdin,"%c",&act);
		if('E'==act){
			fscanf(stdin," %d",&number);
			myqueap.enqueap(number);
		}
		if('M'==act){
			int result=myqueap.min();
			fprintf(stdout,"%d\n",result);
		}
		if('D'==act){
			int result=myqueap.dequeap();
			fprintf(stdout,"%d\n",result);
		}
		getchar();
	}
	return 0;
}

