//对 回忆一下自己的做题思路(最近每做一题就把这个粘过去)
//1.先理解题
//2.确定解题思路(选择数据结构算法什么的)   确定能解决正常情况,也不用考虑太多复杂度
//3.2达到之后, 开始考虑各种解决可能遇到的奇怪情况   然后看看有没有复杂度更低的思路

//看完题,能想出朴素算法   有个大概思路  但是不能保证不超时   然后看一看原来的代码吧
//突然发现还是按照最坏情况申请内存比较好,省了好多麻烦
//发现原来的代码也挺朴素的  简单的思路,但是45分了   思考一下能不能做出一点改进呢.
//突然看到hash,想起了把字母全加起来判等,不过不知道能不能减少时间.那就先试试吧.
//果然  思考多一点   速度快的不是一点  立刻就50分了   每个速度都比原来缩了好几倍   最后一组数据缩减为1/6     要多思考啊

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

struct box{
	char* imprint=new char[10010];     
	int num;
	int sum=0;
};

int match(char*a,char*b,int result,int n){
	for(int i=0;i<n;++i){//2:‘n’在此作用域中尚未声明
		if(b[i]==a[0]){
			int num=i;
			int sign=9;
			for(int j=0,k=num;k<n;k++,j++){//3:在 ISO‘for’作用域中，‘k’的名称查找有变化 [-fpermissive](就是因为小括号后面多写了个分号)
				if(b[k]!=a[j]){
					sign=10;
					break;
				}
			}
			if(9==sign){
				for(int j=n-num,k=0;j<n;k++,j++){
					if(b[k]!=a[j]){
						sign=10;
						break;
					}
				}
				if(9==sign){
					return result;
				}
			}
		}
	}
	return -1;
}

int main(){
	int m,n;
	fscanf(stdin,"%d %d",&m,&n);
	getchar();
	box data[m];
	for(int i=0;i<m;++i){
		gets(data[i].imprint);
		int length=strlen(data[i].imprint);
		for(int j=0;j<length;++j){
			data[i].sum += data[i].imprint[j] - 'a';
		}
	}
	box type[m];
	int amount=0;
	for(int i=0;i<m;++i){
		int result=-1;
		for(int j=0;j<amount;++j){//4:一直输出0 1 2 3 4    问题在这 j写成i了
			if(data[i].sum==type[j].sum){
				result=match(data[i].imprint,type[j].imprint,type[j].num,n);//4:一直输出0 1 2 3 4    问题在这 j写成i了
				if(result>=0){
					break;
				}
			}
		}
		if(result>=0){
			fprintf(stdout,"%d\n",result);
		}else{
			type[amount].imprint=data[i].imprint;//1:无效的数组赋值
			type[amount].num=i;
			type[amount].sum=data[i].sum;
			amount=amount+1;
			fprintf(stdout,"%d\n",i);
		}
	}
	return 0;
}