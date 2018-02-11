//对 回忆一下自己的做题思路(最近每做一题就把这个粘过去)
//1.先理解题
//2.确定解题思路(选择数据结构算法什么的)   确定能解决正常情况,也不用考虑太多复杂度
//3.2达到之后, 开始考虑各种解决可能遇到的奇怪情况   然后看看有没有复杂度更低的思路

//依然  这个题直接改变mooc那个吧   这题比那个简单点
#include<iostream>
#include<cstdio>
using namespace std;

class STACK{
	public:
		STACK(int length);//构造函数,确定栈的长度
		bool empty();//判断栈空
		bool full();//判断栈满
		bool push(int value);//入栈
		int pop();//出栈
	private:
		int max_length;
		int  current_length;
		int* array;
};
STACK::STACK(int length){
	max_length = length;
	current_length = 0;
	array = new int[length+10];
}

bool STACK::empty(){
	if(current_length ==0){
		return true;
	}else{
		return false;
	}
}

bool STACK::full(){
	if(current_length == max_length){
		return true;
	}else{
		return false;
	}
}

bool STACK::push(int value){
	if(!full()){
		array[current_length] = value;
		current_length = current_length + 1;
		return true;
	}else{
		return false;
	}
}

int STACK::pop(){
	if(!empty()){
		current_length = current_length - 1;
		int temp = array[current_length];
		return temp;
	}
}



int line[1600000+100];


int main(){
	
	int n;
	int m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&(line[i]));
	}
	STACK train_stack(m);
	int i = 1;
	int count_line = 0;
	while((i<=n)||(!train_stack.empty())){
		if(i < line[count_line]){
			if(train_stack.push(i)){
				++i;
				continue;
			}else{
				fprintf(stdout,"%s\n","No");
				return 0;
			}
		}
		if(i == line[count_line]){
			if(!train_stack.full()){
				++i;
				++count_line;
				continue;
			}else{
				fprintf(stdout,"%s\n","No");
				return 0;
			}
		}
		if(i > line[count_line]){
			if(train_stack.pop() == line[count_line]){
				++count_line;
			}else{
				fprintf(stdout,"%s\n","No");
				return 0;
			}
		}
	}
	fprintf(stdout,"%s\n","Yes");
	return 0;
}