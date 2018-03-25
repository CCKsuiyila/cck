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

void dijkstra(int N,int s,vector<int> &dis,vector<vector<int> > &g,vector<bool> v){
    dis[s] = 0;
    for(int i=1;i<N;++i){
        int mark = -1, mindis = INF;
        for(int j=1;j<N;++j){
            if(!v[j]&&dis[j]<mindis){
                mindis = dis[j];
                mark = j;
            }
        }
        if(mark==-1) break;
        v[mark] = 1;
        for(int j=1; j<N; ++j) if(!v[j]&&g[mark][j]!=INF){
            if(dis[j]>dis[mark] + g[mark][j]){
                dis[j] = dis[mark] + g[mark][j];
            }
        }
    }
}
int main(){
    //input
    int home_number,rubbish_number,road_number,max_distance;
    cin>>home_number>>rubbish_number>>road_number>>max_distance;
    vector<vector<int> > road(1011,vector<int> (1011,INF));
    for(int i=0;i<road_number;++i){
        string a,b,c;
        cin>>a>>b>>c;
        int one,two,three;
        if(a[0]=='G'&&b[0]=='G'){
            a[0] = '0';
            b[0] = '0';
            one = atoi(a.c_str())+1000;
            two = atoi(b.c_str())+1000;
        }else if(a[0]=='G'){
            a[0] = '0';
            one = atoi(a.c_str())+1000;
            two = atoi(b.c_str());
        }else if(b[0]=='G'){
            b[0] = '0';
            one = atoi(a.c_str());
            two = atoi(b.c_str())+1000;
        }else{
            one = atoi(a.c_str());
            two = atoi(b.c_str());
        }
        three = atoi(c.c_str());
        road[one][two] = three;
        road[two][one] = three;
    }
    //deal with
    int result_number = -1;
    double min_distance = -1;
    double average_distance = INF;
    for(int i=1001;i<1001+rubbish_number;++i){
        vector<int> dis(1001+rubbish_number,INF);
        vector<bool> v(1001+rubbish_number,0);
        dijkstra(1001+rubbish_number,i,dis,road,v);
        double temp_min = dis[1];
        double sum = 0.00;
        int sign = 0;
        for(int j=1;j<home_number+1;++j){
            if(dis[j]>max_distance){
                sign = 1;
                break;
            }else if(dis[j]<temp_min){
                temp_min = dis[j];
            }
            sum += dis[j];
        }
        if(sign==0){
            sum /= home_number;
            if(temp_min>min_distance){
                result_number = i;
                min_distance = temp_min;
                average_distance = sum;
            }else if(temp_min==min_distance&&sum<average_distance){
                result_number = i;
                average_distance = sum;
            }
        }
    }
    //output
    if(result_number==-1){
        cout<<"No Solution";
    }else{
        result_number -= 1000;
        printf("G%d\n",result_number);
        printf("%.1f %.1f",min_distance,average_distance);
    }
    return 0;
}

