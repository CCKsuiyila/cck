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
using namespace std;

#define INF 2147483647
const int MaxN = 520;

struct DisjointSet{
    vector<int> father,rank,exist;
    vector<vector<int> > enemy;
    DisjointSet(int n) : father(n), rank(n), exist(n,0),enemy(n){
        for(int i=0;i<n;++i){
            father[i] = i;
        }
    }
    void add(int x){
        exist[x] = 1;
    }
    bool empty(int x){
        if(exist[x]==0){
            return true;
        }else{
            return false;
        }
    }
    int find(int v){
        return father[v] = (father[v]==v ? v : find(father[v]));
    }
    void merge(int x, int y){
        int a = find(x), b = find(y);
        if(rank[a]<rank[b]){
            father[a] = b;
        }else{
            father[b] = a;
            if(rank[b]==rank[a]){
                ++rank[a];
            }
        }
    }
};

int main(){
    //input
    DisjointSet input(110);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        input.add(a);input.add(b);
        if(c==1){
            input.merge(a,b);
        }else{
            input.enemy[a].push_back(b);
            input.enemy[b].push_back(a);
        }
    }
    //deal with
    for(int i=0;i<k;++i){
        int a,b;
        cin>>a>>b;
        if(input.find(a)==input.find(b)){
            if(find(input.enemy[a].begin(),input.enemy[a].end(),b)==input.enemy[a].end()){
                cout<<"No problem";
            }else{
                cout<<"OK but...";
            }
        }else{
            if(find(input.enemy[a].begin(),input.enemy[a].end(),b)==input.enemy[a].end()){
                cout<<"OK";
            }else{
                cout<<"No way";
            }
        }
        if(i!=k-1){
            cout<<endl;
        }
    }

    //output



    return 0;
}


