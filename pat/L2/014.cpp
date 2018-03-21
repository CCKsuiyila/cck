
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
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
    vector<int> stack;
    for(int i=0;i<n;++i){
        auto j = lower_bound(stack.begin(),stack.end(),input[i]);
        if(j==stack.end()){
            stack.push_back(input[i]);
        }else{
            *j = input[i];
        }
    }
    

    //output
    cout<<stack.size();


    return 0;
}
