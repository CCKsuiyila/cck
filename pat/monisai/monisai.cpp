#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
//#include<unordered_map>
//#include<unordered_set>
#include<algorithm>
#include<sstream>
using namespace std;

#define INF 2147483647
const int MaxN = 520;

int main(){
    //input
    string input;
    vector<int> tab,one,two;
    cin>>input;
    for(int i=input.size()-1;i>=0;--i){
        if(input[i]=='0'){
            tab.push_back(10);
        }else{
            tab.push_back(input[i]-'0');
        }

    }
    cin>>input;
    for(int i=input.size()-1;i>=0;--i){
        one.push_back(input[i]-'0');
    }
    cin>>input;
    for(int i=input.size()-1;i>=0;--i){
        two.push_back(input[i]-'0');
    }
    //deal with
    vector<int> result;
    int i=0;
    int next = 0;
    while(i<one.size()&&i<two.size()){
        if((one[i]+two[i]+next)>=tab[i]){
            result.push_back((one[i]+two[i]+next)%tab[i]);
            next = 1;
        }else{
            result.push_back(one[i]+two[i]+next);
            next = 0;
        }
        ++i;
    }
    if(i<one.size()){
        while(i<one.size()){
            if(one[i]+next>=tab[i]){
                result.push_back((one[i]+next)%tab[i]);
                next = 1;
            }else{
                result.push_back(one[i]+next);
                next = 0;
            }
            ++i;
        }
    }else if(i<two.size()){
        while(i<two.size()){
            if(two[i]+next>=tab[i]){
                result.push_back((two[i]+next)%tab[i]);
                next = 1;
            }else{
                result.push_back(two[i]+next);
                next = 0;
            }
            ++i;
        }
    }
    if(next==1){
        result.push_back(1);
    }

    //output
    int j=result.size()-1;
    while(j>0&&result[j]==0){
        --j;
    }
    for(;j>=0;--j){
        cout<<result[j];
    }


    return 0;
}


