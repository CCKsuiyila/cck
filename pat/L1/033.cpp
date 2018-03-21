
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int count_difference(int a){
    int hash[15] = {0};
    int result = 0;
    for(int i=0;i<4;++i){
        if(a==0){
            ++hash[0];
        }else{
            int temp = a - a/10*10;
            ++hash[temp];
            a /= 10;
        }
        
    }
    for(int i=0;i<10;++i){
        if(hash[i]>0){
            ++result;
        }
    }

    return result;
}

int main(){
    //input
    int year;
    int number;
    cin>>year>>number;
    int now_year = year;
    while(count_difference(now_year)!=number){
        ++now_year;
    }
    printf("%d %04d",now_year-year,now_year);

    return 0;
}

//1.  1 2  this case was forgot
