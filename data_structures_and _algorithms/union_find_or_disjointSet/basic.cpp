#include<iostream>
#include<vector>
using namespace std;

struct union_find{
    vector<int> father,rank,
    vector<bool> exist;

    union_find(int n): father(n),rank(n,0),exist(n,0){
        for(int i=0;i<n;++i)
            father[i] = i;
    }
    void add(int v){
        exist[v] = 1;
    }
    bool is_exist(int v){
        return exist[v];
    }
    int find(int v){
        return father[v] = (father[v]==v) ? v : find(father[v]);
    }
    void merge(int x,int y){
        int a = find(x), b = find(y);
        if(rank[a]<rank[b]){
            father[a] = b;
        }else{
            father[b] = a;
            if(rank[a]==rank[b]){
                ++rank[a];
            }
        }
    }
};
int main(){
    return 0;
}
