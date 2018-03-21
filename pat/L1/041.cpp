
#include<iostream>
using namespace std;

int main(){
    int input;
    for(int i=1;cin>>input;++i){
        if(input==250){
            cout<<i;
            return 0;
        }
    }
}
