
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    //intput
    int n;
    cin>>n;
    //deal with
    int result_length = 0;
    vector<int> product;
    int sq = (int)sqrt(n) + 2;
    int i = 2;
    for(int j=2;j<sq;++j){
        if(n%j!=0){
            continue;
        }
        vector<int> temp;
        int count = 0;
        int number = n;
        for(int i=j;i<sq;++i){
            if(number%i==0){
                temp.push_back(i);
                number /= i;
                /*
                if(number>=temp[0]&&number<=temp[temp.size()-1]){
                    temp.pop_back();
                    number = i;
                }
                */
            }else{
                if(temp.size()>result_length){
                    result_length = temp.size();
                    product = temp;
                }
                break;
            }
        }
    }
    //output
    if(result_length==0){
        cout<<1<<endl;
        cout<<n;
    }else{
        cout<<result_length<<endl;
        cout<<product[0];
        for(int i=1;i<product.size();++i){
            cout<<'*'<<product[i];
        }
    }

    return 0;
}

//
//5.   45 46line    the key is here  for the last two case
