
//https://www.patest.cn/contests/gplt/L2-022

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
    int address;
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
    list_node* converse_list = new list_node[100010];
    for(int i=0;i<number;++i){
        string address;
        int key;
        string next;
        cin>>address>>key>>next;
        //getchar();
        if(next=="-1"){
            next = "100005";
        }
        list[atoi(address.c_str())].key = key;
        list[atoi(address.c_str())].next = atoi(next.c_str());
        converse_list[atoi(next.c_str())].key = key;
        converse_list[atoi(next.c_str())].next= atoi(address.c_str());
    }

    //deal with
    list_node* result = new list_node[100010];
    int count = 0;
    int end = 100005;
    while(start!=end){
        result[count].address = converse_list[end].next;
        result[count].key = converse_list[end].key;
        result[count].next = start;
        ++count;
        end = converse_list[end].next;
        if(start==end){
            break;
        }
        result[count].address = start;
        result[count].key = list[start].key;
        result[count].next = converse_list[end].next;
        ++count;
        start = list[start].next;
    }
    result[count-1].next = -1;

    //output
    for(int i=0;i<count-1;++i){
        fprintf(stdout,"%05d %d %05d\n",result[i].address,result[i].key,result[i].next);
    }
    fprintf(stdout,"%05d %d %d",result[count-1].address,result[count-1].key,result[count-1].next);


    return 0;
}
