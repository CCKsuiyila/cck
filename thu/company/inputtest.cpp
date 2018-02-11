#include<iostream>
#include<cstdio>
using namespace std;

int staff[10000000];
char operate[1000000];
int staffnum[1000000];
int code[1000000];

int main(){
	int conduct(int i,int &sum,int n);
	int sum=0;
	int n,m;
	scanf("%d %d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++){
		staff[i]=-1;
	}
	for(int i=0;i<m;i++){
		scanf("%c",&(operate[i]));
		if('I'==operate[i]){
			scanf(" %d %d",&(staffnum[i]),&(code[i]));
		}
		if('O'==operate[i]||'Q'==operate[i]){
			scanf(" %d",&(staffnum[i]));
		}
		getchar();
	}
	for(int i=0;i<m;i++){
		printf("%c %d %d\n",operate[i],staffnum[i],code[i]);
	}
	return 0;
}



/*
#include <stdio.h>

int person[10000001]={0};


void Close(int n)
{
int i;
for(i=0;i<n;i++)
{
person[i]=-1;
}
}

int Number(int n)
{
int count=0;
int i;
for(i=0;i<n;i++)
{
if(person[i]!=-1)count++;
}
return count;
}

int main()
{
int n,m;
int sum=0;
scanf("%d %d",&n,&m);
getchar();//吃掉紧跟的回车
Close(n);//先将所有员工设为没来

while(m--)
{
char operation;
int rank,code;
scanf("%c",&operation);
getchar();
switch(operation)
{
case 'I':	//Log In：员工a登录，code为c。若a已登录，则将code更新为c
scanf("%d %d",&rank,&code);
getchar();
person[rank-1]=code;
break;
case 'O'://Log Out：编号为a的员工注销。若a未登录，则注销无效
scanf("%d",&rank);
getchar();
person[rank-1]=-1;
break;
case 'Q'://Query：询问员工a的code（若未登录或已注销，视为-1）
scanf("%d",&rank);
getchar();
sum+=person[rank-1];
break;

case 'C'://Close：到下班时间，所有员工注销
Close(n);
break;

case 'N'://Number：询问有多少员工正在上班
sum+=Number(n);
break;
}
}
printf("%d\n",sum);
return 0;
}*/