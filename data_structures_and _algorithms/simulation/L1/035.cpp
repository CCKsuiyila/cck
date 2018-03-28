
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    //input
    vector<string> date;
    string temp;
    cin>>temp;
    while(temp!="."&&date.size()<15){
        date.push_back(temp);
        cin>>temp;
    }
    //deal with and output
    if(date.size()>=14){
        cout<<date[1]<<" and "<<date[13]<<" are inviting you to dinner...";
    }else if(date.size()>=2){
        cout<<date[1]<<" is the only one for you...";
    }else{
        cout<<"Momo... No one is for you ...";
    }

    return 0;
}
