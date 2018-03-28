
//https://www.patest.cn/contests/gplt/L2-012

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
//#include<unordered_map>
//#include<unordered_set>
#include<algorithm>
#include<sstream>
using namespace std;

int main(){
    //input
    int n,m;
    cin>>n>>m;
    vector<int> date;
    date.push_back(0);
    for(int i=1;i<=n;++i){
        int temp;
        cin>>temp;
        date.push_back(temp);
        push_heap(date.begin()+1,date.end(),greater<int>());
    }
    getchar();

    //deal with
    for(int i=0;i<m;++i){
        char *temp = new char[50];
        gets(temp);
        char result;
        if(strstr(temp,"root")){
            int number1 = atoi(temp);
            if(number1==date[1]){
                result = 'T';
            }else{
                result = 'F';
            }
        }else if(strstr(temp,"and")){
            stringstream cin_string(temp);
            int number1;
            int number2;
            string temp2;
            cin_string>>number1>>temp2>>number2;
            int a = find(date.begin(),date.end(),number1) - date.begin() ;
            int b = find(date.begin(),date.end(),number2) - date.begin() ;
            if(a/2==b/2){
                result = 'T';
            }else{
                result = 'F';
            }

        }else if(strstr(temp,"parent")){
            stringstream cin_string(temp);
            int number1;
            int number2;
            string temp2;
            cin_string>>number1>>temp2>>temp2>>temp2>>temp2>>number2;
            int a = find(date.begin(),date.end(),number1) - date.begin() ;
            int b = find(date.begin(),date.end(),number2) - date.begin() ;
            if(a*2==b||a*2+1==b){
                result = 'T';
            }else{
                result = 'F';
            }
        }else{
            stringstream cin_string(temp);
            int number1;
            int number2;
            string temp2;
            cin_string>>number1>>temp2>>temp2>>temp2>>temp2>>number2;
            int a = find(date.begin(),date.end(),number2) - date.begin() ;
            int b = find(date.begin(),date.end(),number1) - date.begin() ;
            if(a*2==b||a*2+1==b){
                result = 'T';
            }else{
                result = 'F';
            }
        }
        cout<<result<<endl;
    }
    //output

    return 0;
}
