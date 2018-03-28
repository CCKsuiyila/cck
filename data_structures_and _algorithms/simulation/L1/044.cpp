
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int space;
    cin>>space;
    int count = 0;
    string input;
    cin>>input;
    vector<string> result;
    while(input.size()!=3){
        if(count<space){
            if(input.size()==6){
                result.push_back("Bu");
            }else if(input.size()==7){
                result.push_back("ChuiZi");
            }else{
                result.push_back("JianDao");
            }
            ++count;
        }else{
            if(input.size()==6){
                result.push_back("ChuiZi");
            }else if(input.size()==7){
                result.push_back("JianDao");
            }else{
                result.push_back("Bu");
            }
            count = 0;
        }
        cin>>input;
    }
    //output
    if(result.size()>0){
        cout<<result[0];
    }
    for(int i=1;i<result.size();++i){
        cout<<endl<<result[i];
    }

    return 0;
}
