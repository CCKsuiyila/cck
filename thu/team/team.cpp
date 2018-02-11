#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	fscanf(stdin,"%d",&n);
	int A[n+1];
	int B[n+1];
	int C[n+1];
	A[0]=0;
	B[0]=0;
	C[0]=0;
	int temp[n+1];
	for(int i=0;i<=n;i++){
		temp[i]=0;
	}
	for(int i=1;i<=n;i++){
		fscanf(stdin,"%d",&(A[i]));
	}
	for(int i=1;i<=n;i++){
		fscanf(stdin,"%d",&(B[i]));
	}
	for(int i=1;i<=n;i++){
		fscanf(stdin,"%d",&(C[i]));
	}
	int person;
	fscanf(stdin,"%d",&person);
	int j=1;
	int k=1;
	int h=1;
	for(int i=0;i<=(n/3) ;i++){
		for( ; ;j++){
			int member=A[j];
			if(member!=temp[member]){
				temp[member]=member;
				A[j]=0;
				j=j+1;
				break;
			}	
		}
		if(temp[person]==person){
			cout<<'A'<<endl;
			break;
		}
		for( ; ;k++){
			int member=B[k];
			if(member!=temp[member]){
				temp[member]=member;
				B[k]=0;
				k=k+1;
				break;
			}	
		}
		if(temp[person]==person){
			cout<<'B'<<endl;
			break;
		}
		for( ; ;h++){
			int member=C[h];
			if(member!=temp[member]){
				temp[member]=member;
				C[h]=0;
				h=h+1;
				break;
			}	
		}
		if(temp[person]==person){
			cout<<'C'<<endl;
			break;
		}
	}
	return 0;
}

