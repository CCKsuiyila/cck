
#include<iostream>
using namespace std;

int main(){
    //input
    int *hash = new int[1005];
    for(int i=0;i<1005;++i){
        hash[i] = 0;
    }
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int number;
        cin>>number;
        for(int j=0;j<number;++j){
            int temp;
            cin>>temp;
            ++hash[temp];
        }
    }
    int result_sign = -1;
    int max_time = 0;
    for(int i=1;i<1001;++i){
        if(hash[i]>=max_time){
            max_time = hash[i];
            result_sign = i;
        }
    }
    cout<<result_sign<<' '<<max_time;

    return 0;
}
