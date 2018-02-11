
#define MAX_INT 10000001
#define MAX_NUM 500000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    static int points[MAX_NUM+10];
    static int borders_a[MAX_NUM];
    static int borders_b[MAX_NUM];
    int count=0;
    int m;
    int n;
    int i;
    int j;
    int a;
    int b;
  
    scanf("%d %d",&n,&m);
    for (i=0;i<n;i++){
        scanf("%d",&(points[i]));
    }
    for (i=0;i<m;i++) {
        scanf("%d %d",&a,&b);
        borders_a[i]=a; 
        borders_b[i]=b;
    }
    for(i=0;i<m;i++){
	    if(borders_a[i]>borders_b[i]){count=-1;}
	    else{
		    for(j=0;j<n;j++)
			    if(points[j]>=borders_a[i]&&points[j]<=borders_b[i])
			        count=count+1;
		    }
	    printf("%d\n",count);
		count =0;
    }
    return 0;
}
	  

	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  