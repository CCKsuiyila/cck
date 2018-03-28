#include<iostream>
#include<vector>
using namespace std;

bool dfs(int count, int n,vector<vector<char> > &input,int now,vector<int> &myhash,vector<int> &temp_result,vector<vector<int> > &result){
    for(int i=0;i<n;++i){
        if(input[now][i]=='W'||input[i][now]=='L'){
            if(count<n&&myhash[i]==0){
                myhash[i] = 1;
                temp_result.push_back(i);
                if(dfs(++count,n,input,i,myhash,temp_result,result)){
                    return true;
                }
                temp_result.pop_back();
                myhash[i] = 0;
                --count;
            }else if(count==n&&i==temp_result[0]){
                temp_result.push_back(i);
                result.push_back(temp_result);
                return true;
            }
        }
        int sign = 1;
        for(;sign<n;++sign){
            if(!myhash[sign]&&(input[sign][0]=='W'||input[0][sign]=='L')){
                break;
            }
        }
        if(sign==n) return false;
    }
    return false;
}
int main(){
    //input
    int n; cin>>n;
    vector<vector<char> > input(n,vector<char>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>input[i][j];
        }
    }
    //deal with
    vector<vector<int> > result;
    vector<int> temp_result(1,0);
    vector<int> myhash(n,0);   myhash[0] = 1;
    dfs(1,n,input,0,myhash,temp_result,result);
    //output
    if(result.size()==0){
        cout<<"No Solution";
    }else{
        for(int i=0;i<n;++i){
            cout<<result[0][i]+1;
            if(i!=n-1){
                cout<<' ';
            }
        }
    }
    return 0;
}
/*
#include <cstdio>
 2 #include <cstring>
 3 #include <string>
 4 #include <iostream>
 5 #include <algorithm>
 6 #include <vector>
 7 #include <map>
 8 #include <queue>
 9 #include <map>
10 #include <cmath>
11 #include <set>
12 using namespace std;
13 typedef long long ll;
14 const int maxn = 22;
15 vector<int>mp[maxn];
16 int nu[maxn][maxn];
17 int vis[maxn];
18 char st[maxn];
19 int n;
20 int path[maxn];
21 int flag;
22 void dfs(int s,int cnt) {
23     if(flag) return;//找到一个就直接返回
24     path[cnt] = s;
25     if(cnt == n - 1 ) {
26         if(nu[s][0]) flag = 1;
27         return;
28     }
29     int i;
30     for(i = 0; i < n; ++i) {  //优化点，如果剩下的点没有和起点相连的，就直接返回
31         if(!vis[i] && nu[i][0] == 1) break;
32     }
33     if(i == n ) return;
34     for(i = 0; i < mp[s].size(); ++i) {
35         if(!vis[mp[s][i]]) {
36             vis[mp[s][i]] = 1;
37         //    path[cnt] = mp[s][i];
38             dfs(mp[s][i], cnt + 1);
39             vis[mp[s][i]] = 0;
40
41         }
42     }
43 }
44 int main()
45 {
46
47     scanf("%d", &n);
48     for(int i = 0; i < n; ++i) {
49         scanf("%s", st);
50         int len = strlen(st);
51         for(int j = 0; j < len; ++j) {
52             if(st[j] == 'W')
53                 nu[i][j] = 1;
54             if(st[j] == 'L')
55                 nu[j][i] = 1;
56         }
57     }
58     for(int i = 0; i < n; ++i) {
59         for(int j = 0; j < n; ++j) {
60             if(nu[i][j])   mp[i].push_back(j);
61         }
62     }
63     path[0] = 1;
64     vis[0] = 1;
65     dfs(0, 0);
66
67     if(!flag) {
68         printf("No Solution");
69         return 0;
70     }
71     else printf("%d",path[0] + 1);
72     for(int i = 1; i < n; ++i) {
73         printf(" %d",path[i] + 1);
74     }
75
76     return 0;
77 }
*/
