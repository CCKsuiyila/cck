#define MAX_INT 1000000
#define MAX_N 400000

#include <stdio.h>
#include<iostream>
using namespace std;

long long int count=0;
int main(){
	
	int quicksort(int *x,int *y,int lef, long long int righ);
	int mergesort(int *L,long long int n);

    //输入
    long long int n;
    scanf("%d",&n);
    int x[MAX_N];
    int y[MAX_N];
    int i; 
    for (i=0;i<n;i++){
		scanf("%d %d",&(x[i]),&(y[i]));
		}
	//排序x
	quicksort(x,y,0,n-1); 
	//归并排序得逆序数
	mergesort(y,n-1);
	printf("%lld",(long long int)n*(n-1)/2-count);
    return 0;
}

//归并同时记录逆序数  
int merge(int *L,int low,int m,long long int high){ 
    int i=low;
	int j=m+1;
	int k=0;   
    int *t=new int[high-low+1];   
    while(i<=m&&j<=high){  
        if(L[i]<=L[j]){  
            t[k++]=L[i];
            i++;
 		}	
        else{ 
            t[k++]=L[j++]; 
            count=count+m+1-i;
		}	
    }		
    while(i<=m){ 
        t[k++]=L[i];
        i++;
	}		
    while(j<=high){ 
        t[k++]=L[j++]; 
	}		
    for(i=low,k=0;i<=high;i++,k++)  
        L[i]=t[k];  
    delete []t; 
    return 0;	
}  
//分开 
int sort(int *L,int low,long long int high){  
    int mid;  
    if(low<high){  
        mid=(low+high)/2;  
        sort(L,low,mid);  
        sort(L,mid+1,high);  
        merge(L,low,mid,high);  
    }  
	return 0;
}  
//归并排序并记录逆序数
int mergesort(int *L,long long int n){  
    sort(L,0,n);  
	return 0;
}  


//快速排序算法
int quicksort(int *x,int *y, int lef, long long int righ){  
    if (lef<righ){        
        int i=lef;
		int j=righ;
		int xx=x[lef];
		int yy=y[lef];  
        while (i<j){  
            while(i<j&&x[j]>=xx){ 
                j--; 
			}				
            if(i<j){  
                x[i] =x[j];
                y[i] =y[j];
				i=i+1;
			}				
            while(i<j&&x[i]<xx){ 
                i++; 
			}				
            if(i<j){  
                x[j] =x[i]; 
                y[j] =y[i];
				j=j-1;
		    }				
        }  
        x[i] =xx; 
        y[i] =yy;		
        quicksort(x,y,lef,i - 1); 
        quicksort(x,y,i+1,righ);
    }  
	return 0;
}  













