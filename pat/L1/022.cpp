
#include<cstdio>
using namespace std;

int main(){
    //input and deal with
    int n;
    fscanf(stdin,"%d\n",&n);
    int temp;
    int odd = 0;
    int even = 0;
    for(int i=0;i<n;++i){
        fscanf(stdin,"%d",&temp);
        if(temp%2==0){
            ++even;
        }else{
            ++odd;
        }
    }
    //output
    printf("%d %d",odd,even);

    return 0;
}
