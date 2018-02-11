#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

struct Line{
	long int a;
	long int b;
};
struct Spot{
	long int x;
	long int y;
	int area;
	int order;
};

int main(){
	int conduct(Line*line,Spot*spot,int low,int high,int lo,int hi);
	int sort(Spot*spot,int low,int high);
	
	int n,m;
	scanf("%d %d",&n,&m);
	Line*line=(Line*)malloc(100100*sizeof(Line));
	Spot*spot=(Spot*)malloc(1000100*sizeof(Spot));
	for(int i=0;i<n;i++){
		fscanf(stdin,"%ld %ld",&line[i].a,&line[i].b);
	}
	for(int i=0;i<m;i++){
		fscanf(stdin,"%ld %ld",&spot[i].x,&spot[i].y);
		spot[i].order=i;
	}
	
	conduct(line,spot,0,m-1,0,n-1);
	sort(spot,0,m);
	
	for(int i=0;i<m;i++){
		fprintf(stdout,"%d\n",spot[i].area);
	}
	return 0;
}


int conduct(Line*line,Spot*spot,int low,int high,int lo,int hi){
	int find_left_start(Line*line,Spot*spot,int low,int high,int mi);
	if(hi-lo<0||high-low<0){
		return 0;
	}
	int mi=(lo+hi)/2;
	int left_start=find_left_start(line,spot,low,high,mi);
	conduct(line,spot,low,left_start-1,lo,mi-1);
	conduct(line,spot,left_start,high,mi+1,hi);
	return 0;
}

int find_left_start(Line*line,Spot*spot,int low,int high,int mi){
	Spot middle_data=spot[low];
	for(;low<high;){
		for(;low<high;){
			if(spot[high].y>=(line[mi].b)-((line[mi].b)*(spot[high].x))/(line[mi].a)){
				spot[high].area=mi+1;
				high=high-1;
			}else{
				spot[high].area=mi;
				spot[low]=spot[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(spot[low].y<(line[mi].b)-((line[mi].b)*(spot[low].x))/(line[mi].a)){
				spot[low].area=mi;
				low=low+1;
			}else{
				spot[low].area=mi+1;
				spot[high]=spot[low];
				high=high-1;
				break;
			}
		}
	}
	int middle=low;
	spot[low]=middle_data;
	if(spot[low].y<(line[mi].b)-((line[mi].b)*(spot[low].x))/(line[mi].a)){
		spot[low].area=mi;
		return middle+1;
	}else{
		spot[low].area=mi+1;
		return middle;
	}
}


int sort(Spot*spot,int low,int high){
	int partition(Spot*spot,int low,int high);
	if(high-low<1){
		return 0;
	}
	int middle=partition(spot,low,high-1);
	sort(spot,low,middle);
	sort(spot,middle+1,high);
	return 0;
}
int partition(Spot*spot,int low,int high){
	Spot middle_data=spot[low];
	for(;low<high;){
		for(;low<high;){
			if(spot[high].order>middle_data.order){
				high=high-1;
			}else{
				spot[low]=spot[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(spot[low].order<middle_data.order){
				low=low+1;
			}else{
				spot[high]=spot[low];
				high=high-1;
				break;
			}
		}
	}
	int middle=low;
	spot[low]=middle_data;
	return middle;
}