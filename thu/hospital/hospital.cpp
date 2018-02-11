#include<cstdio>
#include <cmath>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int w[n+10];
	int coordinate[n+10];
	for(int i=1;i<=n;i++){
		fscanf(stdin,"%d %d",&(coordinate[i]),&(w[i]));
	}
	long long int min_w=1000000000000000000;
	int min_coor=-1;
	int quicken=n-n%10;
	for(int i=0;i<32768;i++){
		int sum=0;
		for(int j=1;j<=quicken;j=j+10){
			sum=sum+((w[j])*abs(i-(coordinate[j])))+((w[j+1])*abs(i-(coordinate[j+1])))+((w[j+2])*abs(i-(coordinate[j+2])))+((w[j+3])*abs(i-(coordinate[j+3])))+((w[j+4])*abs(i-(coordinate[j+4])))+((w[j+5])*abs(i-(coordinate[j+5])))+((w[j+6])*abs(i-(coordinate[j+6])))+((w[j+7])*abs(i-(coordinate[j+7])))+((w[j+8])*abs(i-(coordinate[j+8])))+((w[j+9])*abs(i-(coordinate[j+9])));
		}
		for(int j=quicken+1;j<=n;j=j+1){
			sum=sum+((w[j])*abs(i-(coordinate[j])));
		}
		if(sum<min_w){
			min_w=sum;
			min_coor=i;
		}
		if(sum==min_w){
			if(min_coor>i){
				min_coor=i;
			}
		}
	}
	printf("%d\n",min_coor);
	printf("%lld",min_w);
	return 0;
}