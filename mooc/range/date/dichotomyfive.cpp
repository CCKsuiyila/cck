#define MAX_INT 10000001
#define MAX_NUM 500000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

/*int sort(int *points,int n){
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
}*/

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b; 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int sort(int* points,int n){
  qsort(points,n,sizeof(int),compare_ints);
  return 0;
}

















