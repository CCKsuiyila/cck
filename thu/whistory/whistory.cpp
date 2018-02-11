#include<iostream>
#include<cstdio>
#include<string.h>
#include<malloc.h>
using namespace std;

struct box{
	char *imprint=(char*)malloc(10010*sizeof(char));//修改的这解决了1        
	int num;
};

int match(char*a,char*b,int result,int n){
	for(int i=0;i<n;i++){//2:‘n’在此作用域中尚未声明
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
	scanf("%d %d",&m,&n);
	getchar();
	box data[m];
	for(int i=0;i<m;i++){
		gets(data[i].imprint);
	}
	box type[m];
	int amount=0;
	for(int i=0;i<m;i++){
		int result=-1;
		for(int j=0;j<amount;j++){//4:一直输出0 1 2 3 4    问题在这 j写成i了
			result=match(data[i].imprint,type[j].imprint,type[j].num,n);//4:一直输出0 1 2 3 4    问题在这 j写成i了
			if(result>=0){
				break;
			}
		}
		if(result>=0){
			printf("%d\n",result);
		}else{
			type[amount].imprint=data[i].imprint;//1:无效的数组赋值
			type[amount].num=i;
			amount=amount+1;
			printf("%d\n",i);
		}
	}
	return 0;
}