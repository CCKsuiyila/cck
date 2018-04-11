
//https://www.patest.cn/contests/gplt/L1-055

#include<bits/stdc++.h>
using namespace std;

#define INF 2147483647
const int MaxN = 520;

int main(){
    //input
    int p1,p2;  cin>>p1>>p2;
    int b = 0;
    for(int i=0;i<3;++i){
        int temp; cin>>temp;
        b += temp;
    }

    //deal with
    if((p2>p1&&b>=1)||(b==3)){
        printf("The winner is b: %d + %d",p2,b);
    }else{
        printf("The winner is a: %d + %d",p1,3-b);
    }

    //output



    return 0;
}

