
//https://www.patest.cn/contests/gplt/L2-017

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    //input
    int n;
    cin>>n;
    vector<int> input;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        input.push_back(temp);
    }

    //deal with
    sort(input.begin(),input.end());
    int number_one = input.size()/2;
    int number_two = input.size() - number_one;
    int sum_one = 0;
    int sum_two = 0;
    for(int i=0;i<number_one;++i){
        sum_one += input[i];
    }
    for(int i=number_one;i<input.size();++i){
        sum_two += input[i];
    }
    //output
    cout<<"Outgoing #: "<<number_two<<endl;
    cout<<"Introverted #: "<<number_one<<endl;
    cout<<"Diff = "<<sum_two-sum_one;

    return 0;
}
