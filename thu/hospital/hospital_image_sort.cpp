#include<cstdio>
#include <cmath>
using namespace std;

void quickSort(int s[],int t[], int l, int r){  
    if (l< r)  
    {        
        int i = l, j = r, x = s[l],y=t[l];  
        while (i < j)  
        {  
            while(i < j && s[j]>= x) // 从右向左找第一个小于x的数  
                j--;   
            if(i < j){  
                s[i] = s[j];
                t[i] = t[j];
				i=i+1;
			}				
            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数  
                i++;   
            if(i < j){  
                s[j] = s[i]; 
                t[j] = t[i];
				j=j-1;
		    }				
        }  
        s[i] = x; 
        t[i] = y;		
        quickSort(s,t,l,i - 1); // 递归调用  
        quickSort(s,t,i + 1,r);  
    }  
}  

int main(){
	int n;
	scanf("%d",&n);
	int w[n+10];
	int coordinate[n+10];
	for(int i=1;i<=n;i++){
		fscanf(stdin,"%d %d",&(coordinate[i]),&(w[i]));
	}
	quickSort(coordinate,w,1,n);
	long long int min_w=1000000000000000000;
	int min_coor=-1;
	int quicken=n-n%80;
	for(int i=1;i<=n;i++){
		long long int sum=0;
		for(int j=1;j<=quicken;j=j+80){
			sum=sum+((w[j])*abs((coordinate[i])-(coordinate[j])))+((w[j+1])*abs((coordinate[i])-(coordinate[j+1])))+((w[j+2])*abs((coordinate[i])-(coordinate[j+2])))+((w[j+3])*abs((coordinate[i])-(coordinate[j+3])))+((w[j+4])*abs((coordinate[i])-(coordinate[j+4])))+((w[j+5])*abs((coordinate[i])-(coordinate[j+5])))+((w[j+6])*abs((coordinate[i])-(coordinate[j+6])))+((w[j+7])*abs((coordinate[i])-(coordinate[j+7])))+((w[j+8])*abs((coordinate[i])-(coordinate[j+8])))+((w[j+9])*abs((coordinate[i])-(coordinate[j+9])))
			+((w[j+10])*abs((coordinate[i])-(coordinate[j+10])))+((w[j+11])*abs((coordinate[i])-(coordinate[j+11])))+((w[j+12])*abs((coordinate[i])-(coordinate[j+12])))+((w[j+13])*abs((coordinate[i])-(coordinate[j+13])))+((w[j+14])*abs((coordinate[i])-(coordinate[j+14])))+((w[j+15])*abs((coordinate[i])-(coordinate[j+15])))+((w[j+16])*abs((coordinate[i])-(coordinate[j+16])))+((w[j+17])*abs((coordinate[i])-(coordinate[j+17])))+((w[j+18])*abs((coordinate[i])-(coordinate[j+18])))+((w[j+19])*abs((coordinate[i])-(coordinate[j+19])))
			+((w[j+20])*abs((coordinate[i])-(coordinate[j+20])))+((w[j+21])*abs((coordinate[i])-(coordinate[j+21])))+((w[j+22])*abs((coordinate[i])-(coordinate[j+22])))+((w[j+23])*abs((coordinate[i])-(coordinate[j+23])))+((w[j+24])*abs((coordinate[i])-(coordinate[j+24])))+((w[j+25])*abs((coordinate[i])-(coordinate[j+25])))+((w[j+26])*abs((coordinate[i])-(coordinate[j+26])))+((w[j+27])*abs((coordinate[i])-(coordinate[j+27])))+((w[j+28])*abs((coordinate[i])-(coordinate[j+28])))+((w[j+29])*abs((coordinate[i])-(coordinate[j+29])))
			+((w[j+30])*abs((coordinate[i])-(coordinate[j+30])))+((w[j+31])*abs((coordinate[i])-(coordinate[j+31])))+((w[j+32])*abs((coordinate[i])-(coordinate[j+32])))+((w[j+33])*abs((coordinate[i])-(coordinate[j+33])))+((w[j+34])*abs((coordinate[i])-(coordinate[j+34])))+((w[j+35])*abs((coordinate[i])-(coordinate[j+35])))+((w[j+36])*abs((coordinate[i])-(coordinate[j+36])))+((w[j+37])*abs((coordinate[i])-(coordinate[j+37])))+((w[j+38])*abs((coordinate[i])-(coordinate[j+38])))+((w[j+39])*abs((coordinate[i])-(coordinate[j+39])))
			+((w[j+40])*abs((coordinate[i])-(coordinate[j+40])))+((w[j+41])*abs((coordinate[i])-(coordinate[j+41])))+((w[j+42])*abs((coordinate[i])-(coordinate[j+42])))+((w[j+43])*abs((coordinate[i])-(coordinate[j+43])))+((w[j+44])*abs((coordinate[i])-(coordinate[j+44])))+((w[j+45])*abs((coordinate[i])-(coordinate[j+45])))+((w[j+46])*abs((coordinate[i])-(coordinate[j+46])))+((w[j+47])*abs((coordinate[i])-(coordinate[j+47])))+((w[j+48])*abs((coordinate[i])-(coordinate[j+48])))+((w[j+49])*abs((coordinate[i])-(coordinate[j+49])))
			+((w[j+50])*abs((coordinate[i])-(coordinate[j+50])))+((w[j+51])*abs((coordinate[i])-(coordinate[j+51])))+((w[j+52])*abs((coordinate[i])-(coordinate[j+52])))+((w[j+53])*abs((coordinate[i])-(coordinate[j+53])))+((w[j+54])*abs((coordinate[i])-(coordinate[j+54])))+((w[j+55])*abs((coordinate[i])-(coordinate[j+55])))+((w[j+56])*abs((coordinate[i])-(coordinate[j+56])))+((w[j+57])*abs((coordinate[i])-(coordinate[j+57])))+((w[j+58])*abs((coordinate[i])-(coordinate[j+58])))+((w[j+59])*abs((coordinate[i])-(coordinate[j+59])))
			+((w[j+60])*abs((coordinate[i])-(coordinate[j+60])))+((w[j+61])*abs((coordinate[i])-(coordinate[j+61])))+((w[j+62])*abs((coordinate[i])-(coordinate[j+62])))+((w[j+63])*abs((coordinate[i])-(coordinate[j+63])))+((w[j+64])*abs((coordinate[i])-(coordinate[j+64])))+((w[j+65])*abs((coordinate[i])-(coordinate[j+65])))+((w[j+66])*abs((coordinate[i])-(coordinate[j+66])))+((w[j+67])*abs((coordinate[i])-(coordinate[j+67])))+((w[j+68])*abs((coordinate[i])-(coordinate[j+68])))+((w[j+69])*abs((coordinate[i])-(coordinate[j+69])))
			+((w[j+70])*abs((coordinate[i])-(coordinate[j+70])))+((w[j+71])*abs((coordinate[i])-(coordinate[j+71])))+((w[j+72])*abs((coordinate[i])-(coordinate[j+72])))+((w[j+73])*abs((coordinate[i])-(coordinate[j+73])))+((w[j+74])*abs((coordinate[i])-(coordinate[j+74])))+((w[j+75])*abs((coordinate[i])-(coordinate[j+75])))+((w[j+76])*abs((coordinate[i])-(coordinate[j+76])))+((w[j+77])*abs((coordinate[i])-(coordinate[j+77])))+((w[j+78])*abs((coordinate[i])-(coordinate[j+78])))+((w[j+79])*abs((coordinate[i])-(coordinate[j+79])));
		}
		for(int j=quicken+1;j<=n;j=j+1){
			sum=sum+((w[j])*abs((coordinate[i])-(coordinate[j])));
		}
		if(sum<min_w){
			min_w=sum;
			min_coor=(coordinate[i]);
		}
		if(sum==min_w){
			if(min_coor>(coordinate[i])){
				min_coor=(coordinate[i]);
			}
		}
		for(;coordinate[i]==coordinate[i+1];){
			i=i+1;
		}
	}
	printf("%d\n",min_coor);
	printf("%lld",min_w);
	return 0;
}