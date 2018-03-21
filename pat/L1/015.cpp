
#include<cstdio>
using namespace std;

int main(){
    //input
    int length;
    char sign;
    scanf("%d %c",&length,&sign);
    //deal with
    int half;
    if(length%2!=0){
        half = (length+1)/2;
    }else{
        half = length/2;
    }
    //output
    for(int i=0;i<half;++i){
        for(int j=0;j<length;++j){
            printf("%c",sign);
        }
        printf("\n");
    }

    return 0;
}
//you should write this version first
//1. 14line to 16line was been forgot 

/*
#include<cstdio>
#include<math.h>
using namespace std;

int main(){
    //input
    int length;
    char sign;
    scanf("%d %c",&length,&sign);
    //deal with
    double temp = length;
    temp /= 2;
    temp = round(temp);
    int half = temp;
    //output
    for(int i=0;i<half;++i){
        for(int j=0;j<length;++j){
            printf("%c",sign);
        }
        printf("\n");
    }

    return 0;
}
//learn the round ceil floor
//but this problem is special, because of the 50%
//so i can write a simple version
*/
