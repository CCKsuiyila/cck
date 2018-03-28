
//https://www.patest.cn/contests/gplt/L2-020

#include<iostream>
#include<vector>
using namespace std;

struct date{
    bool get = 0;
    double power;
    long long int magnification;
    vector<int> apprentice;
};
double dfs(vector<date> &input_date, int now, double r,double *result){
    for(int i=0;i<input_date[now].apprentice.size();++i){
        if(input_date[input_date[now].apprentice[i]].get==0){
            input_date[input_date[now].apprentice[i]].power = input_date[now].power*r;
        }else{
            input_date[input_date[now].apprentice[i]].power = input_date[now].power*r*input_date[input_date[now].apprentice[i]].magnification;
            *result += input_date[input_date[now].apprentice[i]].power;
        }
        dfs(input_date,input_date[now].apprentice[i],r,result);
    }
}
int main(){
    //input
    int n;   double zero_power,r;
    cin>>n>>zero_power>>r;        r = (100-r)*0.01;
    vector<date> input_date(n);
    for(int i=0;i<n;++i){
        long long int n1; cin>>n1;
        if(n1==0){
            input_date[i].get = 1;
            cin>>input_date[i].magnification;
        }else{
            for(int j=0; j<n1;++j){
                int temp; cin>>temp;
                input_date[i].apprentice.push_back(temp);
            }
        }
    }
    if(input_date[0].get==0){
        input_date[0].power = zero_power;
    }else{                                                    //这种情况确实没考虑   1分
        cout<<int(zero_power*input_date[0].magnification);
        return 0;
    }
    //deal with
    double result = 0;
    dfs(input_date,0,r,&result);
    //output
    cout<<(long long int)result;
    return 0;
}
//简化一下代码    但是感觉没必要...
