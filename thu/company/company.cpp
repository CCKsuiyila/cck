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
		conduct(i,sum,n);
	}
	cout<<sum;
	return 0;
}

int conduct(int i,int &sum,int n){
	if('I'==operate[i]){
		int person=staffnum[i];
		staff[person]=code[i];
		return 0;
	}
	if('O'==operate[i]){
		int person=staffnum[i];
		staff[person]=-1;
		return 0;
	}
	if('C'==operate[i]){
		for(int i=1;i<=n;i++){
			staff[i]=-1;
		}
		return 0;
	}
	if('N'==operate[i]){
		int login;
		int logout=0;
		for(int i=1;i<=n;i++){
			if(-1==staff[i]){
				logout=logout+1;
			}
		}
		login=n-logout;
		sum=sum+login;
		return 0;
	}
	if('Q'==operate[i]){
		int person=staffnum[i];
		sum=sum+staff[person];
		return 0;
	}
}