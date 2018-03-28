
//https://www.patest.cn/contests/gplt/L2-003

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

struct date{
    double number;
    double price;
    double one_price;
};

bool compare(date a, date b){
    return a.one_price>b.one_price;
}

int main(){
    //input
    int n;
    double d;
    cin>>n>>d;
    vector<date> input(1005);
    for(int i=0;i<n;++i){
        cin>>input[i].number;
    }
    for(int i=0;i<n;++i){
        cin>>input[i].price;
        input[i].one_price = (input[i].price*1.00/input[i].number);
    }
    //deal with
    double result = 0.00;
    sort(input.begin(),input.end(),compare);
    for(int i=0;i<n;++i){
        if(input[i].number<d){
            result += input[i].price;
            d -= input[i].number;
        }else{
            result += d*input[i].one_price;
            break;
        }
    }
    //output
    printf("%.2f",result);

    return 0;
}
//the price also may be double  rather than only the one_price
