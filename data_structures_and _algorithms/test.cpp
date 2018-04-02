

#include<bits/stdc++.h>
using namespace std;

const int max_size = 1010;
vector<int> preorder(max_size);
vector<int> result;

bool build_tree(int prefrom,int length){
    if(length<=0){
        return true;
    }
    int temp = prefrom+1;
    while(temp<prefrom+length&&preorder[temp]<preorder[prefrom]) ++temp;
    int temp1 = temp;
    while(temp1<prefrom+length&&preorder[temp1]>=preorder[prefrom]) ++temp1;
    if(temp1!=prefrom+length){
        return false;
    }
    if(!build_tree(prefrom+1,temp-prefrom-1)){
        return false;
    }
    if(!build_tree(temp,length-(temp-prefrom))){
        return false;
    }
    result.push_back(preorder[prefrom]);
    return true;
}

bool build_tree1(int prefrom,int length){
    if(length<=0){
        return true;
    }
    int temp = prefrom+1;
    while(temp<prefrom+length&&preorder[temp]>=preorder[prefrom]) ++temp;
    int temp1 = temp;
    while(temp1<prefrom+length&&preorder[temp1]<preorder[prefrom]) ++temp1;
    if(temp1!=prefrom+length){
        return false;
    }
    if(!build_tree1(prefrom+1,temp-prefrom-1)){
        return false;
    }
    if(!build_tree1(temp,length-(temp-prefrom))){
        return false;
    }
    result.push_back(preorder[prefrom]);
    return true;
}


int main(){
    int n;  cin>>n;
    for(int i=0;i<n;++i) cin>>preorder[i];

    if(build_tree(0,n)){
        cout<<"YES"<<endl;
        for(int i=0;i<result.size();++i){
            cout<<result[i];
            if(i!=result.size()-1) cout<<' ';
        }
    }else{
        result.clear();
        if(build_tree1(0,n)){
            cout<<"YES"<<endl;
            for(int i=0;i<result.size();++i){
                cout<<result[i];
                if(i!=result.size()-1) cout<<' ';
            }
        }else{
            cout<<"NO";
        }
    }
}
