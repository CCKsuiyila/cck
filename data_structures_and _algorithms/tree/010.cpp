
//https://www.patest.cn/contests/gplt/L3-010

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

struct tree_node{
    //tree_node* father = NULL;
    tree_node* left_child = NULL;
    tree_node* rignt_child = NULL;
    int date;
};
int main(){
    //input
    int n;
    cin>>n;
    vector<tree_node> input(n);
    for(int i=0;i<n;++i){
        cin>>input[i].date;
    }

    //deal with
    for(int i=1;i<n;++i){
        tree_node* temp = &input[0];
        while(temp!=NULL){
            if(input[i].date>(temp->date)){
                if(temp->left_child==NULL){
                    temp->left_child = &input[i];
                    break;
                }
                temp = temp->left_child;
            }else{
                if(temp->rignt_child==NULL){
                    temp->rignt_child = &input[i];
                    break;
                }
                temp = temp->rignt_child;
            }
        }
    }
    vector<tree_node> myqueue;
    myqueue.push_back(input[0]);
    for(int i=0;i<myqueue.size();++i){
        if(myqueue[i].left_child==NULL&&myqueue[i].rignt_child==NULL){
            continue;
        }else if(myqueue[i].left_child!=NULL&&myqueue[i].rignt_child!=NULL){
            myqueue.push_back(*myqueue[i].left_child);
            myqueue.push_back(*myqueue[i].rignt_child);
        }else if(myqueue[i].left_child==NULL&&myqueue[i].rignt_child!=NULL){
            myqueue.push_back(*myqueue[i].rignt_child);
        }else if(myqueue[i].left_child!=NULL&&myqueue[i].rignt_child==NULL){
            myqueue.push_back(*myqueue[i].left_child);
        }
    }

    vector<tree_node> myqueue1;
    myqueue1.push_back(input[0]);
    tree_node kong;
    kong.date = -1;
    for(int i=0;i<myqueue1.size();++i){
        if(myqueue1[i].date==-1){
            continue;
        }
        if(myqueue1[i].left_child==NULL&&myqueue1[i].rignt_child==NULL){
            myqueue1.push_back(kong);
            myqueue1.push_back(kong);
        }else if(myqueue1[i].left_child!=NULL&&myqueue1[i].rignt_child!=NULL){
            myqueue1.push_back(*myqueue1[i].left_child);
            myqueue1.push_back(*myqueue1[i].rignt_child);
        }else if(myqueue1[i].left_child==NULL&&myqueue1[i].rignt_child!=NULL){
            myqueue1.push_back(kong);
            myqueue1.push_back(*myqueue1[i].rignt_child);
        }else if(myqueue1[i].left_child!=NULL&&myqueue1[i].rignt_child==NULL){
            myqueue1.push_back(*myqueue1[i].left_child);
            myqueue1.push_back(kong);
        }
    }

    while(myqueue1[myqueue1.size()-1].date==-1){
        myqueue1.pop_back();
    }
    //output
    for(int i=0;i<myqueue.size();++i){
        cout<<myqueue[i].date;
        if(i!=myqueue.size()-1){
            cout<<' ';
        }
    }
    if(myqueue1.size()==n){
        cout<<endl<<"YES";
    }else{
        cout<<endl<<"NO";
    }

    return 0;
}
