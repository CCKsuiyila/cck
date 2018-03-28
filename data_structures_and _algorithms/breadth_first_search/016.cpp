
//https://www.patest.cn/contests/gplt/L2-016

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define INF 2147483647
const int MaxN = 520;

struct date{
    bool is_emp = 1;
    int sex;
    int father = -1;
    int mother = -1;
};

void bfs(int be_searched,vector<date> &input,vector<int> &myhash,vector<int> &myqueue){
    int from = 0;  int to = myqueue.size();
    for(int i=0;i<4;++i){
        while(from<to){
            if(input[myqueue[from]].is_emp==0&&input[myqueue[from]].father!=-1){
                myqueue.push_back(input[myqueue[from]].father);
                myhash[input[myqueue[from]].father] = 1;
            }
            if(input[myqueue[from]].is_emp==0&&input[myqueue[from]].mother!=-1){
                myqueue.push_back(input[myqueue[from]].mother);
                myhash[input[myqueue[from]].mother] = 1;
            }
            ++from;
        }
        to = myqueue.size();
    }
}
int main(){
    //input
    int n;  cin>>n;
    vector<date> input(100000);
    for(int i=0;i<n;++i){
        int a,b,c;  char sex;
        cin>>a>>sex>>b>>c;
        input[a].is_emp = 0;
        if(sex=='M'){
            input[a].sex = 1;
        }else if(sex=='F'){
            input[a].sex = 0;
        }
        input[a].father = b;   input[a].mother = c;
        if(b!=-1){
            input[b].is_emp = 0;
            input[b].sex = 1;
        }
        if(c!=-1){
            input[c].is_emp = 0;
            input[c].sex = 0;
        }
    }

    //deal with  output
    cin>>n;
    for(int i=0;i<n;++i){
        int a,b;  cin>>a>>b;
        if(input[a].sex==input[b].sex){
            cout<<"Never Mind"<<endl;
            continue;
        }
        vector<int> myhash(100000,0);
        vector<int> myqueue;  myqueue.push_back(a);
        myhash[a] = 1;
        bfs(a,input,myhash,myqueue);

        vector<int> myhash1(100000,0);
        vector<int> myqueue1;  myqueue1.push_back(b);
        myhash[b] = 1;
        bfs(b,input,myhash1,myqueue1);

        int sign = 0;
        for(int i=0;i<myqueue.size();++i){
            if(myhash1[myqueue[i]]==1){
                cout<<"No"<<endl;
                sign = 1;
                break;
            }
        }
        if(sign==0)   cout<<"Yes"<<endl;
    }

    return 0;
}
//不出意外地话,里面还有一些冗余的数据

