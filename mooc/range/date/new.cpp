#define MAX_INT 10000001
#define MAX_NUM 500000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lef;

int main(){
    int sort(int *points,int n);
	int dichotomyleft(int *points,int e,int righ);
	int dichotomyright(int *points,int e,int righ);
    static int points[MAX_NUM];
    static int borders_a[MAX_NUM];
    static int borders_b[MAX_NUM];
    int m;
    int n;
    int i;
    int a;
    int b;
	int leftposition;
	int rightposition;
    //输入
    scanf("%d %d",&n,&m);
    for (i=0;i<n;i++){
        scanf("%d",&(points[i]));
    }
    for (i=0;i<m;i++) {
        scanf("%d %d",&a,&b);
        borders_a[i]=a; 
        borders_b[i]=b;
    }
    //排序
	sort(points,n);
	//二分查找
	for(i=0;i<m;i++){
	    dichotomyleft(points,borders_a[i],n-1);
	    leftposition=lef;
	    dichotomyright(points,borders_b[i],n-1);
	    rightposition=lef;
	    printf("%d\n",rightposition-leftposition);
	}
    return 0;
}


int dichotomyleft(int *points,int e,int righ){
	lef=0;
	while(lef<righ){
		int middle=(lef+righ)>>1;
		if(e==points[middle]){
			lef=middle-1;
			break;
		}
		if(e!=points[middle]){
			(e<points[middle])?righ=middle:lef=middle+1;
		}
	}
	return --lef;
} 

int dichotomyright(int *points,int e,int righ){
	lef=0;
	while(lef<righ){
		int middle=(lef+righ)>>1;
		if(e==points[middle]){
			lef=middle;
			break;
		}
		if(e!=points[middle]){
			(e<points[middle])?righ=middle:lef=middle+1;
		}
	}
	return --lef;
} 

int sort(int *points,int n){
	int temp;
	bool sorted=false;
	while(!sorted){
	    sorted=true;
	    for(int j=1;j<n;j++)
		    if(points[j-1]>points[j]){
			    temp=points[j];
			    points[j]=points[j-1];
			    points[j-1]=temp;
				sorted=false;
		    }
    }
	return sorted;
}


















