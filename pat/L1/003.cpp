
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
    //input
    string give_number;
    cin>>give_number;
    //deal with
    int result_array[15];
    for(int i=0;i<10;++i){
        result_array[i]=0;
    }
    int length = give_number.size();
    int to_number;
    for(int i=0;i<length;++i){
        to_number = give_number[i]-'0';
        ++result_array[to_number];
    }
    //output
    for(int i=0;i<10;++i){
        if(result_array[i]!=0){
            printf("%d:%d\n",i,result_array[i]);
        }
    }
     0;
}



/*
#include<cstdio>
using namespace std;

int main(){
    //input
    unsigned long long int give_number;
    scanf("%llu",&give_number);
    //deal with
    int result_array[15];
    for(int i=0;i<10;++i){
        result_array[i]=0;
    }
    int one_digit;
    unsigned long long int temp;
    while(give_number>0){
        temp = give_number;
        one_digit = give_number-temp/10*10;
        ++result_array[one_digit];
        give_number /= 10;
    }
    //output
    for(int i=0;i<10;++i){
        if(result_array[i]!=0){
            printf("%d:%d\n",i,result_array[i]);
        }
    }
     0;
}
//1 2  input with long long int rather than string
*/
