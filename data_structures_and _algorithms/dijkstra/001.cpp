
//https://www.patest.cn/contests/gplt/L2-001

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

void dijkstra(int N,int s,vector<int> &number,vector<int> &dis,vector<int> &road_number,vector<int> &people_number,vector<vector<int> > &road,vector<vector<int> > &g,vector<bool> v){
    dis[s] = 0;
    road_number[s] = 1;      //这里也会影响最短路径条数的正确性
    for(int i=0;i<N;++i){
        int mark = -1, mindis = INF;
        for(int j=0;j<N;++j){
            if(!v[j]&&dis[j]<mindis){
                mindis = dis[j];
                mark = j;
            }
        }if(mark==-1) break;
        v[mark] = 1;
        people_number[mark] += number[mark];
        road[mark].push_back(mark);
        for(int j=0; j<N; ++j) if(!v[j]&&g[mark][j]!=INF){
            if(dis[j]==dis[mark] + g[mark][j]){
                //++road_number[j];   路的条数不是这么算的
                road_number[j] += road_number[mark];
                if(people_number[j]<people_number[mark]){
                    people_number[j] = people_number[mark];
                    road[j] = road[mark];
                }
            }else if(dis[j]>dis[mark] + g[mark][j]){
                road_number[j] = road_number[mark];
                //road_number[j] = 1;        还有这里
                people_number[j] = people_number[mark];
                dis[j] = dis[mark] + g[mark][j];
                road[j] = road[mark];
            }
        }
    }
}

int main(){
    //input
    int n,m,s,d;
    cin>>n>>m>>s>>d;
    vector<int> number(n);
    for(int i=0;i<n;++i){
        cin>>number[i];
    }
    vector<int> dis(n,INF),road_number(n,0),people_number(n,0);
    vector<vector<int> > road(n),g(n+5,vector<int>(n+5,INF));
    vector<bool> v(n+5,0);
    for(int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b] = c;
        g[b][a] = c;      //1. you can from a to b, you alse can from b to a;
    }
    //deal with
    dijkstra(n,s,number,dis,road_number,people_number,road,g,v);
    //output
    cout<<road_number[d]<<' '<<people_number[d]<<endl;
    for(int i=0;i<road[d].size();++i){
        cout<<road[d][i];
        if(i!=road[d].size()-1){
            cout<<' ';
        }
    }
    return 0;
}
