
//https://www.patest.cn/contests/gplt/L1-054

#include<bits/stdc++.h>
using namespace std;

int main(){
    //input
    char sign;  int n;
    cin>>sign>>n;
    getchar();
    vector<string> input(n);
    for(int i=0;i<n;++i){
        getline(cin,input[i]);
        while(input[i].size()<n) input[i] = input[i] + ' ';
    }

    //deal with
    vector<string> change(input);
    for(int i=0;i<n/2;++i){
        for(int j=0;j<n;++j){
            swap(change[i][j],change[n-i-1][n-j-1]);
        }
    }
    if(n%2!=0){
        for(int i=0;i<n/2;++i){
            swap(change[n/2][i],change[n/2][n-i-1]);
        }
    }
    if(input==change){
        cout<<"bu yong dao le"<<endl;
    }
    
    //output
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(change[i][j]!=' '){
                cout<<sign;
            }else{
                cout<<' ';
            }
        }
        cout<<endl;
    }

    return 0;
}
