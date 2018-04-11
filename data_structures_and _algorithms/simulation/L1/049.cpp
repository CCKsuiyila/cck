
//https://www.patest.cn/contests/gplt/L1-049

#include<bits/stdc++.h>
using namespace std;

#define INF 2147483647
const int MaxN = 520;

int main(){
    //input
    int n;  cin>>n;
    vector<int> amount(n);
    for(int i=0;i<n;++i){
        cin>>amount[i];
    }

    //deal with
    int count = 0;
    set<int> is_emp;
    vector<vector<int>> result(n);
    while(is_emp.size()<n){
        for(int i=0;i<n;++i){
            if(is_emp.find(i)==is_emp.end()){
                if(result[i].size()>0&&count == result[i][result[i].size()-1]){
                    ++count;
                }
                result[i].push_back(++count);
                if(result[i].size()==amount[i]*10){
                    is_emp.insert(i);
                }
            }
        }
    }

    //output
    for(int i=0;i<n;++i){
        cout<<'#'<<i+1<<endl;
        for(int j=1;j<=result[i].size();++j){
            cout<<result[i][j-1];
            if(j%10!=0){
                cout<<' ';
            //}else if(i!=n-1||j!=result[i].size()){
            }else{
                cout<<endl;
            }
        }
    }

    return 0;
}

