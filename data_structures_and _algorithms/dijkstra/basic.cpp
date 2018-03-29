#include<iostream>
#include<vector>
using namespace std;

const int INF = 2147483647;
struct the_dijkstra{
    vector<int> dis;  vector<bool> v;
    vector<vector<int> > g;    //稠密图用领接矩阵,稀疏图用领接表
    int start,n;
    the_dijkstra(int n,int start) : dis(n,INF),v(n,0),g(n,vector<int> (n,INF)){
        this->start = start;
        this->n = n;
    }

    void add_g(int x,int y){
        g[x][y] = 1;
    }
    void dijkstra(){
        dis[start] = 0;
        for(int i=0;i<n;++i){
            int mark = -1, min_dis = INF;
            for(int j=0;j<n;++i){
                if(!v[j]&&dis[j]<min_dis){      //here   v
                    min_dis = dis[j];
                    mark = j;
                }
            }
            v[mark] = 1;
            for(int j=0;j<n;++i){   if(!v[j])   //here   v
                dis[j] = min(dis[j],dis[mark]+g[mark][j]);
            }
        }
    }
};
int main(){
    return 0;
}
