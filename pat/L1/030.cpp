
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    //input
    int n;
    cin>>n;
    vector<string> male;
    vector<string> female;
    vector<string> all;
    for(int i=0;i<n;++i){
        int sex;
        cin>>sex;
        string name;
        cin>>name;
        all.push_back(name);
        if(sex==0){
            female.push_back(name);
        }else{
            male.push_back(name);
        }
    }
    //deal with and output
    int male_count=0;
    int female_count=0;
    for(int i=0;i<n/2;++i){
        if(all[i]==male[male_count]){
            cout<<male[male_count]<<' '<<female[female.size()-1]<<endl;
            female.pop_back();
            ++male_count;
        }else{
            cout<<female[female_count]<<' '<<male[male.size()-1]<<endl;
            male.pop_back();
            ++female_count;
        }
    }

    return 0;
}
