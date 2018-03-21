#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
    //input
    string number;
    cin>>number;
    //deal with
    int i;
    if(number[0]=='-'){
        i = 1;
    }else{
        i = 0;
    }
    int count = 0;
    for(;i<number.size();++i){
        if(number[i]=='2'){
            ++count;
        }
    }
    double result;
    if(number[0]=='-'){
        result = count*100.00/(number.size()-1);
        result *= 1.5;
    }else{
        result = count*100.00/number.size();
    }
    if(number[number.size()-1]%2==0){
        result *= 2.0;
    }
    printf("%.2f%c",result,'%');

    return 0;
}
// c's I/0   or  C++'s I/O      i believe you learn morn
// <cstring> or <string>   i know you have a profound understanding
// those two need to use concertedly

//1.  28line     forget the *100.00

// environment
// learn c'I/O with the 33line 
// it is very important that the transition of the type   25line  *100.00 or *100
