#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	
	int binary_search(int *data,int low,int high
	,int be_searched,int &result);
	
	int array[100];
	for(int i=0;i<100;i++){
		array[i]=i;
	}
	int be_searched;
	scanf("%d",&be_searched);
	int result;
	binary_search(array,0,99,be_searched,result);
	fprintf(stdout,"%d",result);
	return 0;
}

int binary_search(int *data,int low,int high
,int be_searched,int &result){
	
	for(;low<=high;){
		int middle=(low+high)/2;
		if(be_searched==data[middle]){
			result=middle;
			return 0;
		}
		if(low==high){
			result=-1;
			return 0;
		}
		if(be_searched<data[middle]){
			high=middle;
		}
		if(be_searched>data[middle]){
			low=middle;
		}
	}
	result=-1;
	return 0;
}