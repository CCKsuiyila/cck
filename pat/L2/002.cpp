
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<cmath>
using namespace std;

struct list_node{
    int key;
    int next;
};

int main(){
    
    //input
    string temp_start;
    int number;
    cin>>temp_start>>number;
    int start = atoi(temp_start.c_str());

    list_node* list = new list_node[100010]; 
    unordered_multiset<int> the_key;
    for(int i=0;i<number;++i){
        string address;
        int key;
        string next;
        cin>>address>>key>>next;
        //getchar();
        list[atoi(address.c_str())].key = key;
        list[atoi(address.c_str())].next = atoi(next.c_str());
        the_key.insert(key);
    }

    
    //deal with
    int now = start;
    set<int> used_key;
    
    int now_one = 100006;
    list[100006].next = -1;
    int now_two = 100005;
    list[100005].next = -1;

    while(now!=-1){
        if(the_key.count(list[now].key)==1&&the_key.count((-(list[now].key)))==0){
            list[now_one].next = now;
            now_one = now;
            now = list[now_one].next;
            list[now_one].next = -1;
        }else{
            if(used_key.find(list[now].key)!=used_key.end()||(used_key.find(-(list[now].key))!=used_key.end())){
                list[now_two].next = now;
                now_two = now;
                now = list[now_two].next;
                list[now_two].next = -1;
            }else{
                used_key.insert(list[now].key);
                list[now_one].next = now;
                now_one = now;
                now = list[now_one].next;
                list[now_one].next = -1;
            }
        }
    }

    //output
    if(list[start].next!=-1){
        fprintf(stdout,"%05d %d %05d",start,list[start].key,list[start].next);
    }else{
        fprintf(stdout,"%05d %d %d",start,list[start].key,list[start].next);
    }
    start =list[start].next;
    while(start!=-1){
        if(list[start].next!=-1){
            fprintf(stdout,"\n%05d %d %05d",start,list[start].key,list[start].next);
            start =list[start].next;
        }else{
            fprintf(stdout,"\n%05d %d %d",start,list[start].key,list[start].next);
            break;
        }
        
    }
    start = list[100005].next;
    while(start!=-1){
        if(list[start].next!=-1){
            fprintf(stdout,"\n%05d %d %05d",start,list[start].key,list[start].next);
            start =list[start].next;
        }else{
            fprintf(stdout,"\n%05d %d %d",start,list[start].key,list[start].next);
            break;
        }
    }

    return 0;
}
