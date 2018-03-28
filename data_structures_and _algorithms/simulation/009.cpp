
//https://www.patest.cn/contests/gplt/L2-009

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

struct date{
    double money = 0;
    int times = 0;
    int order = 0;
};

bool compare(date &a,date &b){
    if(a.money==b.money){
        if(a.times==b.times){
            return a.order<b.order;
        }
        return a.times>b.money;
    }
    return a.money>b.money;
}

int main(){
    //input
    int people_number;
    cin>>people_number;
    vector<date> give_date(people_number+2);
    for(int i=1;i<=people_number;++i){
        give_date[i].order = i;
    }
    for(int i=1;i<=people_number;++i){
        int gift_number;
        cin>>gift_number;
        for(int j=0;j<gift_number;++j){
            int id;
            double money_get;
            cin>>id>>money_get;
            give_date[id].money += money_get;
            ++give_date[id].times;
            give_date[i].money -= money_get;
        }
    }

    //deal with
    sort(give_date.begin()+1,give_date.end()-1,compare);

    //output
    if(give_date.size()==0){
        return 0;
    }else{
        printf("%d %.2f",give_date[1].order,give_date[1].money*0.01);
        for(int i=2;i<=people_number;++i){
            printf("\n%d %.2f",give_date[i].order,give_date[i].money*0.01);
        }
    }


    return 0;
}
