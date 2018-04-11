
//https://www.patest.cn/contests/gplt/L2-025

#include<bits/stdc++.h>
using namespace std;

int main(){
    //input
    int n,m;   cin>>n>>m;
    vector<int> a(m),b(m);
    for(int i=0;i<m;++i){
        cin>>a[i]>>b[i];
    }
    int n1;  cin>>n1;
    for(int i=0;i<n1;++i){
        int n2;  cin>>n2;
        unordered_set<int>  temp;
        for(int j=0;j<n2;++j){
            int temp1;  cin>>temp1;
            temp.insert(temp1);
        }
        int sign = 0;
        for(int j=0;j<m;++j){
            if(temp.find(a[j])==temp.end()&&temp.find(b[j])==temp.end()){
                sign = 1;
                break;
            }
        }
        if(sign==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }


    return 0;
}

