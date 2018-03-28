
//https://www.patest.cn/contests/gplt/L2-007

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

struct date{
    int amount = 0;
    double area = 0.00;
};

struct result_date{
    int min_number;
    int people_number;
    double average_house_number;
    double average_area;
};

bool compare(result_date a, result_date b){
    if(a.average_area==b.average_area){
        return a.min_number<b.min_number;
    }
    return a.average_area>b.average_area;
}
struct DisjointSet{
    vector<int> father,rank,exist;
    vector<date> save_date;

    DisjointSet(int n) : father(n), rank(n), exist(n,0), save_date(n){
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
    DisjointSet input(10000);
    int n;
    cin>>n;
    int count = 0;
    for(int i=0;i<n;++i){
        vector<int> home;
        int sign = -1;
        for(int i=0;i<3;++i){
            int temp;
            cin>>temp;
            if(temp!=-1){
                if(sign==-1&&input.empty(temp)==false){
                    sign = temp;
                }
                home.push_back(temp);
            }
        }
        int k;
        cin>>k;
        for(int i=0;i<k;++i){
            int temp;
            cin>>temp;
            if(sign==-1&&input.empty(temp)==false){
                sign = temp;
            }
            home.push_back(temp);
        }
        if(sign==-1){
            input.add(home[0]);
            for(int j=1;j<home.size();++j){
                input.add(home[j]);
                input.merge(home[0],home[j]);
            }
        }else{
            for(int j=0;j<home.size();++j){
                input.add(home[j]);
                input.merge(input.find(sign),home[j]);
            }
        }
        int a,b;
        cin>>a>>b;
        input.save_date[home[0]].amount = a;
        input.save_date[home[0]].area = b;
    }

    //deal with
    vector<int> myhash(10000,0);
    vector<int> min_number(10000,INF);
    for(int i=0;i<10000;++i){
        if(input.empty(i)==false){
            int temp = input.find(i);
            ++myhash[temp];
            if(min_number[temp]>i){
                min_number[temp] = i;
            }
            if(temp!=i){
                input.save_date[temp].amount += input.save_date[i].amount;
                input.save_date[temp].area += input.save_date[i].area;
            }
        }
    }
    vector<result_date> result;
    for(int i=0;i<10000;++i){
        if(input.empty(i)==false&&input.find(i)==i){
            int temp = input.find(i);
            result_date one_result;
            one_result.min_number = min_number[temp];
            one_result.people_number = myhash[temp];
            one_result.average_house_number = input.save_date[i].amount*1.00/myhash[temp];
            one_result.average_area = input.save_date[i].area*1.00/myhash[temp];
            result.push_back(one_result);
        }
    }
    sort(result.begin(),result.end(),compare);

    //output
    cout<<result.size()<<endl;
    for(int i=0;i<result.size();++i){
        printf("%04d %d %.3f %.3f",result[i].min_number,result[i].people_number,result[i].average_house_number,result[i].average_area);
        if(i!=result.size()-1){
            cout<<endl;
        }
    }

    return 0;
}
// 1.      要用input.find(i)  而不是 input.father[i]
// 2.    忘记输出那个家庭个数了

