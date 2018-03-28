
//https://www.patest.cn/contests/gplt/L2-024

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

struct DisjointSet{
    vector<int>father,rank,date;

    DisjointSet(int n) : father(n), rank(n), date(n){
        for(int i=0;i<n;++i){
            father[i] = i;
        }
    }

    void add(int x){
        date[x] = 1;
    }

    bool empty(int x){
        if(date[x]==0){
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
    int n;
    cin>>n;
    DisjointSet input(10005);
    for(int i=0;i<n;++i){
        int n1;
        cin>>n1;
        vector<int> circle;
        int sign = 0;
        for(int j=0;j<n1;++j){
            int temp;
            cin>>temp;
            circle.push_back(temp);
            if(sign==0&&input.empty(temp)==false){
                sign = temp;
            }
        }

        if(circle.size()==0){
            continue;
        }
        if(sign==0){
            input.add(circle[0]);
            for(int k=1;k<circle.size();++k){
                input.add(circle[k]);
                input.merge(circle[0],circle[k]);
            }
        }else{
            for(int k=0;k<circle.size();++k){
                input.add(circle[k]);
                input.merge(sign,circle[k]);
            }
        }
    }

    //deal with
    int pepple_count = 0;
    set<int> tribe_count;
    for(int i=1;i<10001;++i){
        if(input.empty(i)==false){
            ++pepple_count;
            tribe_count.insert(input.find(i));
        }
    }

    //output
    cout<<pepple_count<<' '<<tribe_count.size()<<endl;
    cin>>n;
    if(n!=0){
        int a,b;
        cin>>a>>b;
        if(input.empty(a)==false&&input.empty(b)==false&&input.find(a)==input.find(b)){
            cout<<'Y';
        }else{
            cout<<'N';
        }
    }
    for(int i=1;i<n;++i){
        int a,b;
        cin>>a>>b;
        if(input.empty(a)==false&&input.empty(b)==false&&input.find(a)==input.find(b)){
            cout<<endl<<'Y';
        }else{
            cout<<endl<<'N';
        }
    }


    return 0;
}
