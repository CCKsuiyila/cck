
#include<iostream>
using namespace std;

int main(){
    long long int n;
    cin>>n;

    int one = 1;
    int length = 1;
    while(one<n){
        one = one*10 +1;
        ++length;
    }
    while(1){
        cout<<one/n;
        if(one%n==0){
            cout<<' '<<length;
            return 0;
        }else{
            one = one%n;
            one = one*10 +1;
            ++length;
        }
    }

    return 0;
}
// give up the 3 score
// 6line   n  from int to long long     3 score get    excuse me???



/*
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> result;
    int length;
    int one = 1;
    int i=1;
    while(1){
        if(one<n){
            one *= 10;
            one += 1;
            ++i;
            continue;
        }
        result.push_back(one/n);
        if(one%n==0){
            length = i;
            break;
        }else{
            one %= n;
        }
    }
    for(int i=0;i<result.size();++i){
        cout<<result[i];
    }
    cout<<' '<<length;

    return 0;
}
//1.      n may be bigger than 19
//2.      s may be over the unsigned long long int 
//
*/

/*
#include<iostream>
using namespace std;

int main(){
    unsigned long long int n;
    cin>>n;
    unsigned long long int result;
    int length;
    unsigned long long int one = 1;
    for(int i=1;i<=19;++i){
        if(one%n==0){
            result = one/n;
            length = i;
            cout<<result<<' '<<length;
            return 0;
        }
        one *= 10;
        one += 1;
    }
    
    return 0;
}
*/
