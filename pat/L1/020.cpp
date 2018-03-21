
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    //input
    int n;
    cin>>n;
    vector<int> have;
    for(int i=0;i<n;++i){
        int m;
        cin>>m;
        if(m<=1){
            if(m==1){
                int temp;
                cin>>temp;
            }
            continue;
        }
        for(int j=0;j<m;++j){
            int temp;
            cin>>temp;
            have.push_back(temp);
        }
    }
    cin>>n;
    vector<int> be_search;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        be_search.push_back(temp);
    }
    //deal with
    sort(have.begin(),have.end());
    //have.erase(unique(have.begin(),have.end()),have.end());
    vector<int> result;
    int *hash = new int[100000];
    for(int i=0;i<n;++i){
        if(!binary_search(have.begin(),have.end(),be_search[i])){
            if(hash[be_search[i]]!=99999){
                result.push_back(be_search[i]);
                hash[be_search[i]] = 99999;
            }
        }
    }
    if(result.size()==0){
        printf("No one is handsome");
        return 0;
    }
    fprintf(stdout,"%05d",result[0]);
    for(int i=1;i<result.size();++i){
        fprintf(stdout," %05d",result[i]);
    }

    return 0;
}

//test if we can use the vector
//and the result is we can use the stl with C++

//1.   47line and 49line     with int   00000 is 0
//2.                         don't find the problem
//3.   15line to 18line      i find it  
//4.   36line                i am not familiar with the stl, make sure it is right 
//5.   35line to 38line      test this case ,but i think this is not the key
//6.   35line to 38line      have....   this is incorrect
//7.   40line                i find it, the result is not be sort, but runtime is too long 
//8.   41line                with hash, if the memory is enough
//
//100000 int.  the memory is enough!!!
