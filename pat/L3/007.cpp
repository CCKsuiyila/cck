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

void dijkstra(int N,int s,vector<int> &dis,vector<int> &from, vector<int> &len,vector<vector<int> > &g,vector<vector<int> > &g1,vector<vector<int> > &road,vector<bool> v){
    dis[s] = 0;
    len[s] = 0;
    //from[s] = s;
    for(int i=0;i<N;++i){
        int mark = -1, mindis = INF;
        for(int j=0;j<N;++j){
            if(!v[j]&&dis[j]<mindis){
                mindis = dis[j];
                mark = j;
            }
        }
        if(mark==-1) break;
        v[mark] = 1;
        road[mark].push_back(mark);
        //len[mark] += g1[from[mark]][mark];
        for(int j=0; j<N; ++j) if(!v[j]&&g[mark][j]!=INF){
            if((dis[j]>dis[mark] + g[mark][j])||((dis[j]==dis[mark] + g[mark][j])&&(len[j]>len[mark]+g1[mark][j]))){
                dis[j] = dis[mark] + g[mark][j];
                //from[j] = mark;
                len[j] = len[mark] + g1[mark][j];
                road[j] = road[mark];
            }
        }
    }
}

void dijkstra1(int N,int s,vector<int> &dis,vector<vector<int> > &g,vector<vector<int> > &road,vector<bool> v){
    dis[s] = 0;
    for(int i=0;i<N;++i){
        int mark = -1, mindis = INF;
        for(int j=0;j<N;++j){
            if(!v[j]&&dis[j]<mindis){
                mindis = dis[j];
                mark = j;
            }
        }
        if(mark==-1) break;
        v[mark] = 1;
        road[mark].push_back(mark);
        for(int j=0; j<N; ++j) if(!v[j]&&g[mark][j]!=INF){
            if(dis[j]>dis[mark] + g[mark][j]){
                dis[j] = dis[mark] + g[mark][j];
                road[j] = road[mark];
            }else if(dis[j]==dis[mark] + g[mark][j]){
                if(road[j].size()>road[mark].size()){
                    road[j] = road[mark];
                }
            }
        }
    }
}

int main(){
    //input
    int n,m;
    cin>>n>>m;
    vector<vector<int> > road_length(n,vector<int> (n,INF));
    vector<vector<int> > road_time(n,vector<int> (n,INF));
    for(int i=0;i<m;++i){
        int a,b,c,length,time;
        cin>>a>>b>>c>>length>>time;
        if(c==1){
            road_length[a][b] = length;
            road_time[a][b] = time;
        }else{
            road_length[a][b] = length;
            road_time[a][b] = time;
            road_length[b][a] = length;
            road_time[b][a] = time;
        }
    }
    int s,d;
    cin>>s>>d;
    //road_length[s][s] = 0;

    //deal with
    vector<int> dis(n,INF),len(n,INF),from(n,-1);
    vector<bool> v(n,0);
    vector<vector<int> > road(n);
    dijkstra(n,s,dis,from,len,road_time,road_length,road,v);
    vector<int> result_time_road = road[d];
    int result_time = dis[d];

    vector<int> dis1(n,INF);
    vector<bool> v1(n,0);
    vector<vector<int> > road1(n);
    dijkstra1(n,s,dis1,road_length,road1,v1);
    vector<int> result_length_road = road1[d];
    int result_length = dis1[d];
    //output
    if(result_time_road==result_length_road){
        cout<<"Time = "<<result_time<<"; Distance = "<<result_length<<": ";
        for(int i=0;i<result_length_road.size();++i){
            cout<<result_length_road[i];
            if(i!=result_length_road.size()-1){
                cout<<" => ";
            }
        }
    }else{
        cout<<"Time = "<<result_time<<": ";
        for(int i=0;i<result_time_road.size();++i){
            cout<<result_time_road[i];
            if(i!=result_time_road.size()-1){
                cout<<" => ";
            }
        }
        cout<<endl<<"Distance = "<<result_length<<": ";
        for(int i=0;i<result_length_road.size();++i){
            cout<<result_length_road[i];
            if(i!=result_length_road.size()-1){
                cout<<" => ";
            }
        }
    }


    return 0;
}
//对于这种存储路径的数据结构    城市从0开始开始从1开始一样的
//dijkstra里面的三条注释掉以后(不用from)就好了   从23 到了30
//暂时看不出来这个from有啥问题    有空再来看吧
//就此  练了三个dijkstra了

