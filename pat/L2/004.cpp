#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define INF 2147483647
const int MaxN = 520;

bool judge(vector<int> array, vector<int> &result,int head,int to){
    int temp = head+1;
    while(temp<to&&array[temp]<array[head]){
        ++temp;
    }
    int temp2 = temp;
    while(temp<to&&array[temp]>=array[head]){
        ++temp;
    }
    if(temp!=to){
        return false;
    }else{
        result.push_back(array[head]);
        bool a = 1; bool b = 1;
        if(to-temp2>0){
            //result.push_back(array[temp2]);
            b = judge(array,result,temp2,to);
        }
        if(temp2-head-1>0){
            //result.push_back(array[head+1]);
            a = judge(array,result,head+1,temp2);
        }
        return (a&&b);
    }
}

bool judge1(vector<int> array, vector<int> &result,int head,int to){
    int temp = head+1;
    while(temp<to&&array[temp]>=array[head]){
        ++temp;
    }
    int temp2 = temp;
    while(temp<to&&array[temp]<array[head]){
        ++temp;
    }
    if(temp!=to){
        return false;
    }else{
        result.push_back(array[head]);
        bool a = 1; bool b = 1;
        if(to-temp2>0){
            //result.push_back(array[temp2]);
            b = judge1(array,result,temp2,to);
        }
        if(temp2-head-1>0){
            //result.push_back(array[head+1]);
            a = judge1(array,result,head+1,temp2);
        }
        return (a&&b);
    }
}


int main(){
    //input
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;++i){
        cin>>input[i];
    }

    //deal with
    vector<int> result_array;
    bool result = judge(input,result_array,0,n);
    vector<int> result_array1;
    bool result1 = judge1(input,result_array1,0,n);

    //output
    if(result==0&&result1==0){
        cout<<"NO";
    }else if(result!=0){
        cout<<"YES"<<endl;
        for(int i=result_array.size()-1;i>=0;--i){
            cout<<result_array[i];
            if(i!=0){
                cout<<' ';
            }
        }
    }else if(result1!=0){
        cout<<"YES"<<endl;
        for(int i=result_array1.size()-1;i>=0;--i){
            cout<<result_array1[i];
            if(i!=0){
                cout<<' ';
            }
        }
    }

    return 0;
}

