
//https://www.patest.cn/contests/gplt/L2-021

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    //input
    int n;
    cin>>n;
    map<double, string> people;
    for(int i=0;i<n;++i){
        string temp_name;
        cin>>temp_name;
        int temp_times;
        cin>>temp_times;
        vector<int> save;
        for(int j=0;j<temp_times;++j){
            int temp;
            cin>>temp;
            save.push_back(temp);
        }
        sort(save.begin(),save.end());
        save.erase(unique(save.begin(),save.end()),save.end());
        people.insert({(save.size()+0.001000000*save.size()/temp_times),temp_name});
    }

    //deal with
    if(people.size()==0){
        return 0;
    }else if(people.size()==1){
        cout<<people.begin()->second<<' '<<'-'<<' '<<'-';

    }else if(people.size()==2){
        auto map_one = people.begin();
        auto map_two = people.begin();
        ++map_two;
        if(map_one->first<(map_two->first)){
            cout<<map_two->second<<' '<<map_one->second<<' '<<'-';
        }else{
            cout<<map_one->second<<' '<<map_two->second<<' '<<'-';
        }
    }else{
        auto map_now = people.end();
        --map_now;
        cout<<(map_now)->second<<' ';
        --map_now;
        cout<<(map_now)->second<<' ';
        --map_now;
        cout<<(map_now)->second;
    }

    return 0;
}
