#include<iostream>
#include<cstdio>
using namespace std;

int stack[1600000+100];
int line[1600000+100];
int act[3200000+100];


int main(){
	
	int conduct(int i,int*stack,int*line,int &stacknum,int &leavenum,int*act,int &count,int &sign,int m);
	
	int sign=9;
	int n;
	int m;
	scanf("%d %d",&n,&m);
	stack[0]=0;
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&(line[i]));
	}
	int stacknum=0;
	int leavenum=1;
	int size=2*n+200;
	int count=0;
	for(int i=0;i<n;i++){
		conduct(i,stack,line,stacknum,leavenum,act,count,sign,m);
		if(10==sign){
			break;
		}
	}
	if(9==sign){
		for(int i=0;(act[i]==6||act[i]==8)&&i<size;i++){
			if(act[i]==6){
				fprintf(stdout,"%s\n","push");
			}
			if(act[i]==8){
				fprintf(stdout,"%s\n","pop");
			}
		}
	}
	return 0;
}
	
int conduct(int i,int*stack,int*line,int &stacknum,int &leavenum,int*act,int &count,int &sign,int m){
	if(line[i]>leavenum){
		int difference=line[i]-leavenum;
		for(int j=0;j<difference;j++){
			if(stacknum>m-1){
			cout<<"No"<<endl;
			sign=10;
			return 0;
			}
			stacknum=stacknum+1;
			stack[stacknum]=leavenum;
			act[count++]=6;
			leavenum=leavenum+1;
		}
		conduct(i,stack,line,stacknum,leavenum,act,count,sign,m);
		return 0;
	}
	if(line[i]==leavenum){
		if(stacknum>m-1){
			cout<<"No"<<endl;
			sign=10;
			return 0;
		}
		act[count++]=6;
		act[count++]=8;
		leavenum=leavenum+1;
		return 0;
	}
	if(line[i]==stack[stacknum]){
		act[count++]=8;
		stacknum=stacknum-1;
		return 0;
	}
	if(line[i]<stack[stacknum]){
		cout<<"No"<<endl;
		sign=10;
		return 0;
	}
}
		