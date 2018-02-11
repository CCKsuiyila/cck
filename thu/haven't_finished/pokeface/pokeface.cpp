#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
struct Act{
	char type;
	int from;
	int to;
};
int main(){
	int n,m;
	fscanf(stdin,"%d %d",&n,&m);
	getchar();
	Act *act=(Act*)malloc(100100*sizeof(Act));
	for(int i=0;i<m;i++){
		fscanf(stdin,"%c %d %d",&act[i].type,&act[i].from,&act[i].to);
		getchar();
	}
	int poke[1000100]={0};
	for(int i=0;i<m;i++){
		if(act[i].type=='H'){
			for(int j=act[i].from;j<=act[i].to;j++){
				if(poke[j]==0){
					poke[j]=1;
				}
				else{
					poke[j]=0;
				}
			}
		}
		if(act[i].type=='Q'){
			int count=0;
			for(int j=act[i].from;j<=act[i].to;j++){
				if(poke[j]==0){
					count=count+1;
				}
			}
			cout<<count<<endl;
		}
	}
	return 0;
}
