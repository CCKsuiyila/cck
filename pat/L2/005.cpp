
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
    vector<unordered_set<int>> date;
    for(int i=0;i<n;++i){
        int n1;
        cin>>n1;
        unordered_set<int> temp;
        for(int j=0;j<n1;++j){
            int input;
            cin>>input;
            temp.insert(input);
        }
        date.push_back(temp);
    }

    //deal with
    cin>>n;
    vector<double> result;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        --a;--b;
        int nc = 0;
        for(auto i=date[a].begin();i!=date[a].end();++i){
            if(date[b].find(*i)!=date[b].end()){
                ++nc;
            }
        }
        int nt = date[a].size() + date[b].size() - nc;
        result.push_back(nc*100.00/nt);
    }
    
    //output
    if(n==0){
        return 0;
    }else{
        fprintf(stdout,"%.2f%%",result[0]);
    }
    for(int i=1;i<n;++i){
        fprintf(stdout,"\n%.2f%%",result[i]);
    }


    return 0;
}
