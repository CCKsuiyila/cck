
//https://www.patest.cn/contests/gplt/L2-019

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
    set<string> care_list;
    for(int i=0;i<n;++i){
        string temp;
        cin>>temp;
        care_list.insert(temp);
    }
    cin>>n;
    vector<string> id;
    vector<int> times;
    for(int i=0;i<n;++i){
        string id_temp;
        int times_temp;
        cin>>id_temp>>times_temp;
        id.push_back(id_temp);
        times.push_back(times_temp);
    }

    //deal with
    int sum = 0;
    for(int i=0;i<times.size();++i){
        sum += times[i];
    }
    double average = sum*1.00/times.size();
    vector<string> result;
    for(int i=0;i<times.size();++i){
        if(times[i]>average&&care_list.find(id[i])==care_list.end()){
            result.push_back(id[i]);
        }
    }
    sort(result.begin(),result.end());

    //output
    if(result.size()==0){
        cout<<"Bing Mei You";
        return 0;
    }
    for(int i=0;i<result.size()-1;++i){
        cout<<result[i]<<endl;
    }
    cout<<result[result.size()-1];


    return 0;
}
