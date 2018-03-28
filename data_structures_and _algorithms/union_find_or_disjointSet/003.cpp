
//https://www.patest.cn/contests/gplt/L3-003

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int compare(int a,int b){
    return a>b;
}

struct DisjointSet{
    vector<int>father,rank,date,number;

    DisjointSet(int n) : father(n), rank(n), date(n),number(n){
        for(int i=0;i<n;++i){
            father[i] = i;
            number[i] = 0;
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
    DisjointSet input(1005);
    for(int i=0;i<n;++i){
        int n1;
        cin>>n1;
        getchar();
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

        if(sign==0){
            input.add(circle[0]);
            ++input.number[circle[0]];
            for(int k=1;k<circle.size();++k){
                input.add(circle[k]);
                input.merge(circle[0],circle[k]);
            }
        }else{
        	++input.number[input.find(sign)];
            for(int k=0;k<circle.size();++k){
                input.add(circle[k]);
                input.merge(input.find(sign),circle[k]);
            }
        }
    }

    //deal with
    int tribe_count = 0;
    vector<int> people_count;
    for(int i=1;i<=1000;++i){
        if(input.empty(i)==false&&input.father[i]!=i){
            int temp = input.number[i];
            input.number[input.find(i)] += temp;
            input.number[i] = 0;
        }
    }
    for(int i=1;i<=1000;++i){
        if(input.empty(i)==false&&input.father[i]==i){
            ++tribe_count;
            people_count.push_back(input.number[i]);
        }
    }
	sort(people_count.begin(),people_count.end(),compare);
    //output
    cout<<tribe_count<<endl;
    cout<<people_count[0];
    for(int i=1;i<people_count.size();++i){
        cout<<' '<<people_count[i];
    }

    return 0;
}
