#define MAX_INT 10000001
#define MAX_NUM 500000
#include <stdio.h>
#include <stdlib.h>


int main(){
	int quicksort(int *points,int lef, int righ);
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
    for (i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        borders_a[i]=a; 
        borders_b[i]=b;
    }
    //排序 
	quicksort(points,0,n-1);
	
	//二分查找
	for(i=0;i<m;i++){
	    leftposition=dichotomyleft(points,borders_a[i],n-1);
	    rightposition=dichotomyright(points,borders_b[i],n-1);
	    printf("%d\n",rightposition-leftposition);
	}
    return 0;
}


int dichotomyleft(int *points,int e,int n){
	int lef=0;
	int righ=n;
	int count;
	if (e<points[lef]) return count=-1;
	if (points[righ]<e){
		count=righ;
		return count;
	}
	while(lef<righ){
		int middle=(lef+righ)>>1;
		if (points[middle]<e&&e<points[middle+1]){
			int count=middle;
			return count;
		}
		if (points[middle]<e&&e==points[middle+1]){
			int count=middle;
			return count;
		}
		if(points[middle]<e){
			lef=middle;
		}
		if(e<points[middle]){
			righ=middle;
		}
		if(e==points[middle]){
			while(e==points[middle]){
				middle=middle-1;
			}
			count=middle;
			return count;
		}  
	}
	count=lef+1;
	return count;
} 

int dichotomyright(int *points,int e,int n){
	int lef=0;
	int righ=n;
	int count;
	if (e<points[lef]){
		count=-1;
		return count;
	}		
	if (points[righ]<e){
		count=righ;
		return count;} //1
	while(lef<righ){
		int middle=(lef+righ)>>1;
		if (points[middle]<e&&e<points[middle+1]){
			int count=middle;
			return count;
		}
		if (points[middle]<e&&e==points[middle+1]){
			int count=middle+1;
			return count;
		}
		if(points[middle]<e){
			lef=middle;
		}
		if(e<points[middle]){
			righ=middle;
		}
		if(e==points[middle]){
			while(e==points[middle]){
				middle=middle+1;
			}
			count=middle-1;
			return count;
		}  
	}
	count=lef+1;
	
	if (count<righ&&points[count+1]==e){
		count=count+1;
	} 
	return count;
}

int quicksort(int *points,int lef, int righ){  
    if (lef<righ){        
        int i=lef;
		int j=righ;
		int k=points[lef];  
        while (i<j){  
            while(i<j&&points[j]>=k)
                j--;   
            if(i < j){  
                points[i] = points[j];
				i=i+1;
			}				
            while(i<j&&points[i]<k){
                i++; 
			}				
            if(i<j){  
                points[j]=points[i];
				j=j-1;
		    }				
        }
        points[i]=k; 		
        quicksort(points,lef,i - 1);
        quicksort(points,i + 1,righ);  
    }  
	return 0;
}  




















