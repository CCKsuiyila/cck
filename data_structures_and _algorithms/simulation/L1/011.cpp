
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
    //input
    char *a = new char[10005];
    char *b = new char[10005];
    fgets(a,10005,stdin);
    //getchar();
    fgets(b,10005,stdin);
    //deal with
    vector<int> a_number; 
    vector<int> b_number; 
    for(int i=0;i<strlen(a);++i){
        a_number.push_back(a[i] - ' ');
    }
    for(int i=0;i<strlen(b);++i){
        b_number.push_back(b[i] - ' ');
    }
    sort(b_number.begin(),b_number.end());
    for(int i=0;i<a_number.size();++i){
        if(!binary_search(b_number.begin(),b_number.end(),a_number[i])){
            fprintf(stdout,"%c",a[i]);
        }
    }

    return 0;
}
