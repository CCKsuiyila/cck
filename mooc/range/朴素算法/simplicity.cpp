#include<iostream>
#include<vector>
using namespace std;
int main(){
    int i; int j;int n; int m; int a; int b;int k=0;vector<int>c(n); vector<int>d(2*m); 
    cin>>n>>m;
    cout<<endl;
    for(i=0;i<n;i++)
        cin>>c[i];
    cout<<endl;
    for(i=0;i<m;i++){
        j=0;
	    cin>>d[j]>>d[j+1];
	    cout<<endl;
	    j=j+2;
    }
    for(j=0;j<m;j++){
		int y=0;
		if(d[y]>d[y+1]){k=-1;}
        for(i=0;i<n;i++){
		    if(n>=d[y]&&n<=d[y+1])
		        k=k+1;
	    }
	    cout<<k<<endl;
		y=y+2;
    }
    return 0;
}

/*#include<iostream>
using namespace std;
int main(){
	int a[5]={1,2,3,4,5};
	for(int i=0;i<=4;i++)
		cout<<a[i]<<" ";
	return 0;
}*/



/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    int i; int j;int n; int m; int a; int b;int k=0;vector<int>c(n); vector<int>d(2*m); 
    cin>>n;
	cout<<" ";
	cin>>m;
	cout <<" ";
    cout<<endl;
    for(i=0;i<n;i++)
        cin>>c[i];
	    cout<<" ";
    cout<<endl;
    for(i=0;i<m;i++){
        j=0;
	    cin>>d[j];
		cout<<" ";
		cin>>d[j+1];
	    cout<<" ";
		cout<<endl;
	    j=j+2;
    }
    for(j=0;j<m;j++){
		int y=0;
		if(d[y]>d[y+1]){k=-1;}
        for(i=0;i<n;i++){
		    if(n>=d[y]&&n<=d[y+1])
		        k=k+1;
	    }
	    cout<<k<<endl;
		y=y+2;
    }
    return 0;
}*/






















