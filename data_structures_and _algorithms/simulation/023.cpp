
//https://www.patest.cn/contests/gplt/L2-023

#include<bits/stdc++.h>
using namespace std;

int main(){
    int v,e,k; cin>>v>>e>>k;
    vector<vector<int> > edge(v);
    for(int i=0;i<e;++i){
        int a,b; cin>>a>>b;
        edge[a-1].push_back(b-1);
    }
    vector<int> v_color(v);
    int n; cin>>n;
    for(int i=0;i<n;++i){
        unordered_set<int> count;
        for(int j=0;j<v;++j){
            cin>>v_color[j];
            count.insert(v_color[j]);
        }
        int sign = 0;
        //if(count.size()>k){
        if(count.size()!=k){
            cout<<"No";
            sign = 1;
        }
        for(int j=0;sign==0&&j<v;++j){
            for(int k=0;k<edge[j].size();++k){
                if(v_color[j]==v_color[edge[j][k]]){
                    cout<<"No";
                    sign = 1;
                    break;
                }
            }
        }

        if(sign==0){cout<<"Yes";}
        if(i!=n-1){
            cout<<endl;
        }
    }
}
