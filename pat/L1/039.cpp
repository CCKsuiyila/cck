
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int main(){
    //input
    int line_number;
    scanf("%d\n",&line_number);
    char *date = new char[1005];
    gets(date);
    //deal with
    vector<vector<char>> result;
    for(int i=0;i<line_number;++i){
        vector<char> temp;
        for(int j=i;j<strlen(date);j+=line_number){
            temp.push_back(date[j]);
        }
        result.push_back(temp);
    }
    for(int i=0;i<line_number;++i){
        if(result[i].size()!=result[0].size()){
            while(result[i].size()<result[0].size()){
                result[i].push_back(' ');
            }
        }
    }
    for(int j=result[0].size()-1;j>=0;--j){
        cout<<result[0][j];
    }
    for(int i=1;i<line_number;++i){
        cout<<endl;
        for(int j=result[i].size()-1;j>=0;--j){
            cout<<result[i][j];
        }
    }

    return 0;
}
