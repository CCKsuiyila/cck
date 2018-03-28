
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    //input and deal with
    int n;
    cin>>n;
    if(n==0){
        return 0;
    }
    vector<string> output;
    for(int i=0;i<n;++i){
        int integer;
        cin>>integer;
        if(integer==1||integer==45){
            output.push_back("No");
            continue;
        }else if(integer==2){
            output.push_back("Yes");
            continue;
        }else if(integer%2==0){
            output.push_back("No");
            continue;
        }
        int sign = 0;
        for(int j=3;j<(int)sqrt(integer)+1;j+=2){
            if(integer%j==0){
                sign = 1;
                break;
            }
        }
        if(sign==0){
            output.push_back("Yes");
        }else{
            output.push_back("No");
        }
    }
    //output
    cout<<output[0];
    for(int i=1;i<n;++i){
        cout<<endl<<output[i];
    }

    return 0;
}

//1.      run out of time  i change the 22line
//2 3. 22line        (integer+1)/2   may be incorrect
//4 5 6.  you forget the break after the output.push_back();
//you need to sleep   do right thing at the right time
