#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

class date{
    public:
        int book_number;
        char operation;
        string time;
};

int calculation_time(string lend,string retu){
    int lend_hour = (lend[0]-'0')*10 + (lend[1]-'0');
    int lend_minute = (lend[3]-'0')*10 + (lend[4]-'0');
    int retu_hour = (retu[0]-'0')*10 + (retu[1]-'0');
    int retu_minute = (retu[3]-'0')*10 + (retu[4]-'0');
    int hour_difference = (retu_hour - lend_hour)*60;
    int minute_difference = (retu_minute - lend_minute);
    return hour_difference+minute_difference;
}
int main(){
    //input
    int day_number;
    cin>>day_number;
    
    vector<date> give_date;
    int count = day_number;
    while(count!=0){
        date temp;
        cin>>temp.book_number>>temp.operation>>temp.time;
        give_date.push_back(temp);
        if(temp.book_number==0){
            --count;
        }
    }
    //deal with
    int now = 0;
    int book_status[1005];
    for(int i=0;i<1005;++i){
        book_status[i] = -1;
    }
    vector<string> hash_time;
    for(int i=0;i<1005;++i){
        hash_time.push_back(" ");
    }
    vector<int> result_one;
    vector<int> result_two;
    for(int i=1;i<=day_number;++i){
        int lend_retu_time = 0;
        int sum_time = 0;
        while(give_date[now].book_number!=0){
            //if(give_date[now].operation=='S'&&book_status[give_date[now].book_number]!=i){
            if(give_date[now].operation=='S'){
                book_status[give_date[now].book_number] = i;
                hash_time[give_date[now].book_number] = give_date[now].time;
            }else if(give_date[now].operation=='E'&&book_status[give_date[now].book_number]==i){
                book_status[give_date[now].book_number] = -1;
                sum_time += calculation_time(hash_time[give_date[now].book_number],give_date[now].time);
                ++lend_retu_time;
                hash_time[give_date[now].book_number] = " ";
            }
            ++now;
        }
        result_one.push_back(lend_retu_time);
        int temp;
        if(lend_retu_time==0){
            temp = 0;
        }else{
            temp =round(1.00*sum_time/lend_retu_time);
        }
        result_two.push_back(temp);

        ++now;
    }
    //output
    cout<<result_one[0]<<' '<<result_two[0];
    for(int i=1;i<result_one.size();++i){
        cout<<endl<<result_one[i]<<' '<<result_two[i];
    }

    return 0;
}

//1. 14 to 22 line  redundant cout 
//  54line  55line    hehehe   
