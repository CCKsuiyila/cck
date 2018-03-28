
#include<cstdio>
using namespace std;

int main(){
    //input
    char time[10];
    scanf("%s",&time);
    //deal with
    int one   = time[0] - '0';
    int two   = time[1] - '0';
    int three = time[3] - '0';
    int four  = time[4] - '0';
    int hour = one*10 + two;
    int minute = three*10 + four;
    
    if((hour>=0&&hour<12)||(hour==12&&minute==0)){
        fprintf(stdout,"Only %s.  Too early to Dang.",time);
        return 0;
    }

    if(minute!=0){
        ++hour;
    }
    hour -= 12;
    for(int i=0;i<hour;++i){
        fprintf(stdout,"Dang");
    }

    return 0;
}
