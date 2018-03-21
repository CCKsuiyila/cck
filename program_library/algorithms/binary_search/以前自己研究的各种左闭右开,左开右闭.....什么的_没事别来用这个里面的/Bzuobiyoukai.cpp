#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

struct Road{
	int from;
	int to;
};
int k=0;
int main(){
	int quicksort(Road *data,int low,int high);
	int find_the_height(int spot,int m,Road*road);
	//输入
	static int n,m;
	fscanf(stdin,"%d %d",&n,&m);
	static Road*road=(Road*)malloc(1000100*sizeof(Road));
	for(int i=0;i<m;i++){
		fscanf(stdin,"%d %d",&(road[i].from),&(road[i].to));
	}
	//找出所有没有被指向的点,也就是可以作为起点的点
	int *find_origin=(int*)malloc(100100*sizeof(int));
	for(int i=0;i<100100;i++){
		find_origin[i]=0;
	}
	for(int i=0;i<m;i++){
		int temporary=road[i].to;
		find_origin[temporary]=temporary;
	}
	int *origin=(int *)malloc(100100*sizeof(int));
	int origin_number;//起点的个数(不含0)
	for(int i=1,j=0;i<=n;i++){
		if(0==find_origin[i]){
			origin[j++]=i;
			origin_number=j;
		}
	}
	//给路排序
	quicksort(road,0,m-1);
	//行动
	int number=0;
	for(int i=0;i<origin_number;i++){//一次循环,一个起点,一条路线
		int temporary=find_the_height(origin[i],m,road);
		if(temporary>number){
			number=temporary;
		}
	}
	//输出
	fprintf(stdout,"%d",number);
	return 0;
}

int find_the_height(int spot,int m,Road*road){
	int binary_search(Road *data,int low,int high,
	int be_searched);
	int length=0;
	int sign=9;
	int result=binary_search(road,0,m,spot);
	for(int i=result;i<m;i++){
		if(spot==road[i].from){
			int temporary=find_the_height(road[i].to,m,road);
			if(temporary>length){
				length=temporary;
			}
			sign=10;
		}else{
			break;
		}
	}
	if(9==sign){
		return 1;
	}
	if(10==sign){
		return length+1;
	}
}

//二分查找
int binary_search(Road *data,int low,int high
,int be_searched){
	
	for(;1<high-low;){
		int middle=(low+high)>>1;
		(be_searched<data[middle].from)?high=middle:low=middle;
	}
	if(be_searched==data[low].from){
		for(;be_searched==data[low].from;low=low-1);
		low=low+1;
		return low;
	}else{
		return 10000010;
	}
}

//快速排序
int quicksort(Road *data,int low,int high){
	int partition(Road *data,int low,int high);
	if ((high-low)<1){
		return 0;
	}
	
	int middle=partition(data,low,high-1);
	quicksort(data,low,middle);
	quicksort(data,middle+1,high);
	return 0;
}

int partition(Road *data,int low,int high){
	int backup_low=low;
	int backup_high=high;
	Road middle_data=data[low];
	for(;low<high;){
		for(;low<high;){
			if(data[high].from>middle_data.from){
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(data[low].from<middle_data.from){
				low=low+1;
			}else{
				data[high]=data[low];
				high=high-1;
				break;
			}
		}
	}
	int middle=low;
	data[low]=middle_data;
	low=backup_low;
	high=backup_high;
	return middle;
}
