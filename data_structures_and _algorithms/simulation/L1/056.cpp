
//https://www.patest.cn/contests/gplt/L1-056

#include<bits/stdc++.h>
using namespace std;

#define INF 2147483647
const int MaxN = 520;

int main(){
    //input
    int n; cin>>n;
    vector<string> name(n);
    vector<int> number(n);
    double sum = 0.0;
    for(int i=0;i<n;++i){
        cin>>name[i]>>number[i];
        sum += number[i];
    }
    //deal with
    sum = sum/n/2;
    int min = INF,mark = -1;
    for(int i=0;i<n;++i){
        if(abs(number[i]-sum)<min){
            min = abs(number[i]-sum);
            mark = i;
        }
    }
    //output
    cout<<(int)sum<<' '<<name[mark];

    return 0;
}

