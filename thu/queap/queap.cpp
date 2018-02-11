#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

class Stack{
	public:
		//注意：你不能添加更多的public函数或变量,如有需要可添加析构函数
		Stack();
		bool empty();
		void push(int value);
		int pop();
		int top();
	private:
		//此处可以扩展
		int *array;
		int size;
};

Stack::Stack(){
	size=0;
	array=(int *)malloc(1000100*sizeof(int));
}

bool Stack::empty(){
	if(size>0){
		return false;
	}
	if(size==0){
		return true;
	}
}

void Stack::push(int value){
	size=size+1;
	array[size]=value;
}

int Stack::pop(){
	int temporary=array[size];
	size=size-1;
	return temporary;
}

int Stack::top(){
	int temporary=array[size];
	return temporary;
}


class Queap{
	public:
		Queap();
		void enqueap(int);
		int dequeap();
		int min();
	private:
	    Stack queap;
		Stack backup;
		int length;
};

Queap::Queap(){
	length=0;
}

void Queap::enqueap(int value){
	queap.push(value);
	length=length+1;
}

int Queap::dequeap(){
	int head;
	int temporary;
	for(int i=0;i<length-1;i++){
		temporary=queap.pop();
		backup.push(temporary);
	}
	head=queap.pop();
	for(int i=0;i<length-1;i++){
		temporary=backup.pop();
		queap.push(temporary);
	}
	length=length-1;
	return head;
}

int Queap::min(){
	int minimum=queap.top();
	int temporary;
	for(int i=0;i<length;i++){
		temporary=queap.pop();
		if(temporary<minimum){
			minimum=temporary;
		}
		backup.push(temporary);
	}
	for(int i=0;i<length;i++){
		temporary=backup.pop();
		queap.push(temporary);
	}
	return minimum;
}

int main(){
	int n;
	fscanf(stdin,"%d",&n);
	getchar();
	Queap myqueap;
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

