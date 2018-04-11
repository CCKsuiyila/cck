
//https://www.patest.cn/contests/gplt/L1-050

#include<bits/stdc++.h>
using namespace std;

int main(){
    //input
    long long int l,n;   cin>>l>>n;
    //deal with
    long long int sum = 0;
    for(int i=0;i<7;++i){
        sum += pow(26,i)*25;
    }
    n %= sum;
    n = sum - n + 1;
    vector<int> result;
    for(int i=0;i<l;++i){
        int temp = n%26;
        result.push_back(temp);
        n /= 26;
        if(n<=0){
            break;
        }
    }
    for(int i=result.size()-1;i>=0;--i){
        cout<<(char)('a'+result[i]);
    }

    return 0;
}

