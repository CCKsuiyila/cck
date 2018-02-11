#include<iostream>
using namespace std;
int main(){
	int n;int m;int c[10];int d[10];int k=0;int v=0;int a;int b;
	cout<<"你想要输入多少个点?"<<endl;
	cin>>n;
	cout<<"你想要输入多少个区间?"<<endl;
	cin>>m;
	cout<<"请输入"<<n<<"个点:";
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<m;i++){
		cout<<"请输入区间:";
		cin>>a>>b;
		for(int j=0;j<n;j++){
			if(c[j]>=a&&c[j]<=b){
				d[v++]=c[j];
				k++;
			}
		}
		cout<<"在区间[a,b]上有"<<k<<"个点"<<endl;
		k=0;
	}
	return 0;
}
