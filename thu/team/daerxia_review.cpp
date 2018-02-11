//果然还是得一段一段来,process注释掉竟然没问题了,就是说process部分竟然能影响输入
//我他妈也是佩服自己了 while里面的3个for循环全是++A_index. 不死循环才怪呢
//你他妈的就不能一开始就检查吗  非得调试半天  还调试   我真是日了狗了
//检查出这个改了以后就能在小黑框里面运行样例成功了

//这次算是用了下hash吧  和原来的比了一下 无论速度还是内存都不如原来的 
//原来的那个加速版的还不如不加速版的   不过这一次的代码长度减少不少原来(73)这次(55)
//看了下大概懂原来是怎么写的了   现在客观评价的话,还是现在的代码好懂一点   简洁一点
//不过依然是    在同一个复杂度内就不用太纠结了    系数差不太多就不管

//2017-02-26 22:27:21    50分
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	//input
	int n;
	fscanf(stdin, "%d", &n);
	int* A = new int[n+10];
	int* B = new int[n+10];
	int* C = new int[n+10];
	for(int i=0;i<n;++i){
		fscanf(stdin,"%d",&(A[i]));
	}
	for(int i=0;i<n;++i){
		fscanf(stdin,"%d",&(B[i]));
	}
	for(int i=0;i<n;++i){
		fscanf(stdin,"%d",&(C[i]));
	}
	int k;
	fscanf(stdin,"%d",&k);
	
	//process
	int* hash = new int[n+10];
	int A_index=0;
	int B_index=0;
	int C_index=0;
	for(int i=0;i<(n+10);++i){
		hash[i] = 0;
	}
	int sign = 0;
	while(sign==0){
		for(;hash[(A[A_index])]!=0;++A_index);
		if(A[A_index]==k){
			cout<<"A";
			sign = 1;
		}
		hash[(A[A_index])]=8;
		++A_index;
		for(;hash[(B[B_index])]!=0;++B_index);
		if(B[B_index]==k){
			cout<<"B";
			sign = 1;
		}
		hash[(B[B_index])]=8;
		++B_index;
		for(;hash[(C[C_index])]!=0;++C_index);
		if(C[C_index]==k){
			cout<<"C";
			sign = 1;
		}
		hash[(C[C_index])]=8;
		++C_index;
	}
	return 0;
}

