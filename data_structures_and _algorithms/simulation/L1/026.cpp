
#include<iostream>
#include<string>
using namespace std;

int main(){
    string output = "I Love GPLT";
    for(int i=0;i<output.size()-1;++i){
        cout<<output[i]<<endl;
    }
    cout<<output[output.size()-1];

    return 0;
}
