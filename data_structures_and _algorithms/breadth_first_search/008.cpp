
//https://www.patest.cn/contests/gplt/L3-008

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

struct date{
    int layer = 0;
    int number;
};

void bfs(int n,vector<vector<int> > &input, unordered_set<int> &exist,vector<date> &myqueue){
    for(int i=0;i<myqueue.size();++i){
        for(int j=0;j<input[myqueue[i].number].size();++j){
            if(exist.find(input[myqueue[i].number][j])==exist.end()){
                exist.insert(input[myqueue[i].number][j]);
                date join;
                join.number = input[myqueue[i].number][j];
                join.layer = myqueue[i].layer+1;
                myqueue.push_back(join);
            }
        }
    }
}
int main(){
    //input
    int n,m,k;   cin>>n>>m>>k;
    vector<vector<int> > input(n+1);
    for(int i=0;i<m;++i){
        int  a,b;  cin>>a>>b;
        input[a].push_back(b);  input[b].push_back(a);
    }
    //deal with and output
    for(int i=0;i<k;++i){
        date be_searched;   cin>>be_searched.number;   be_searched.layer = 0;
        vector<date> myqueue;   myqueue.push_back(be_searched);
        unordered_set<int>  exist;  exist.insert(be_searched.number);
        bfs(n,input,exist,myqueue);
        if(myqueue.size()==1){
            cout<<0;
        }else{
            int j=myqueue.size()-1;
            int result = myqueue[j].number;
            while(myqueue[j].layer==myqueue[myqueue.size()-1].layer){
                if(myqueue[j].number<result){
                    result = myqueue[j].number;
                }
                --j;
            }
            cout<<result;
        }
        if(i!=k-1)  cout<<endl;
    }

    return 0;
}
//  优化1   领接矩阵改为不定长二维数组
//  优化2   set改为unorderset

