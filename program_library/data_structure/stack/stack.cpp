//this is my stack
//感觉挺溜,直接手打出来,提前没看书.这个用得少,啥时候用再根据需要改吧



//大二寒假的复习
//原来的思路都清楚,没啥大变化  就是这次写了个STACK类   感觉代码比原来清楚多了
//第一次直接40分,然后改了改95,最后除了个小思维缺陷就100了.

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
int act[3200000+100];


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
	int count_act = 0;
	while((i<=n)||(!train_stack.empty())){//没加后面的判断之前是40分  这倒是很快加上了
		if(i < line[count_line]){
			if(train_stack.push(i)){
				++i;
				act[count_act] = 6;
				++count_act;
				continue;
			}else{
				fprintf(stdout,"%s\n","No");
				return 0;
			}
		}
		if(i == line[count_line]){
			if(!train_stack.full()){//没加这个判断之前是95分   这种小思路缺陷就得尽量避免  还好今天这个没浪费太多时间
				act[count_act] = 6;
				++count_act;
				act[count_act] = 8;
				++count_act;
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
				act[count_act] = 8;
				++count_act;
				++count_line;
			}else{
				fprintf(stdout,"%s\n","No");
				return 0;
			}
		}
	}
	for(int i=0;(act[i]==6||act[i]==8);++i){
		if(act[i]==6){
			fprintf(stdout,"%s\n","push");
		}
		if(act[i]==8){
			fprintf(stdout,"%s\n","pop");
		}
	}
	return 0;
}
