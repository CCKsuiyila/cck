
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
    char * input = new char[1010]; 
    gets(input);
    if(strlen(input)==0){
        cout<<0;
        return 0;
    }
    //deal with
    int result = 1;
    for(int i=0;i<strlen(input);++i){
        int prev = i-1;
        int succ = i+1;
        int length = 1;
        while(prev>=0&&succ<strlen(input)&&input[prev]==input[succ]){
            length += 2;
            --prev;
            ++succ;
        }
        if(length>result){
            result = length;
        }
    }

    int result1 = 0;
    for(int i=0;i<strlen(input);++i){
        int prev = i;
        int succ = i+1;
        int length = 0;
        while(prev>=0&&succ<strlen(input)&&input[prev]==input[succ]){
            length += 2;
            --prev;
            ++succ;
        }
        if(length>result1){
            result1 = length;
        }
    }

    if(result1>result){
        result = result1;
    }
    //output
    cout<<result;

    return 0;
}
