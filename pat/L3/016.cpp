#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;

#define INF 2147483647
const int MaxN = 520;

struct tree_node{
    tree_node* father = NULL;
    tree_node* left_child = NULL;
    tree_node* rignt_child = NULL;
    int date;
    int layer = 0;
};

tree_node* find(tree_node* head, int find_number){
    while(find_number!=head->date){
        if(find_number<(head->date)){    //这个就是左边小右边大了,
            head = head->left_child;
        }else{
            head = head->rignt_child;
        }
    }
    return head;
}
int main(){
    //input
    int n;
    cin>>n;
    if(n==0){
        return 0;
    }
    vector<tree_node> input(n);
    set<int> exist;
    for(int i=0;i<n;++i){
        cin>>input[i].date;
        exist.insert(input[i].date);
    }

    //deal with
    for(int i=1;i<n;++i){
        tree_node* temp = &input[0];
        int count = 1;
        while(temp!=NULL){
            if(input[i].date<(temp->date)){    //这个就是左边小右边大了,
                if(temp->left_child==NULL){
                    temp->left_child = &input[i];
                    temp->left_child->father = temp;
                    input[i].layer = count;
                    break;
                }
                temp = temp->left_child;
                ++count;
            }else{
                if(temp->rignt_child==NULL){
                    temp->rignt_child = &input[i];
                    temp->rignt_child->father = temp;
                    input[i].layer = count;
                    break;
                }
                temp = temp->rignt_child;
                ++count;
            }
        }
    }


    //output
    cin>>n;
    getchar();
    for(int i=0;i<n;++i){
        string result;
        string temp_input;
        getline(cin,temp_input);
        stringstream string_input(temp_input);
        int number1,number2;
        string eat_string;
        string_input>>number1>>eat_string;
        if(exist.find(number1)==exist.end()){
            cout<<"No";
            if(i!=n-1){
                cout<<endl;
            }
            continue;
        }
        if(eat_string=="is"){
            string_input>>eat_string>>eat_string;
            if(eat_string=="root"){
                if(input[0].date==number1){
                    result = "Yes";
                }else{
                    result = "No";
                }
            }else if(eat_string=="parent"){
                string_input>>eat_string>>number2;
                if(exist.find(number2)==exist.end()){
                    cout<<"No";
                    if(i!=n-1){
                        cout<<endl;
                    }
                    continue;
                }
                tree_node* temp = find(&input[0],number1);
                if((temp->left_child!=NULL&&temp->left_child->date==number2)||(temp->rignt_child!=NULL&&temp->rignt_child->date==number2)){
                    result = "Yes";
                }else{
                    result = "No";
                }
            }else if(eat_string=="left"){
                string_input>>eat_string>>eat_string>>number2;
                if(exist.find(number2)==exist.end()){
                    cout<<"No";
                    if(i!=n-1){
                        cout<<endl;
                    }
                    continue;
                }
                tree_node* temp = find(&input[0],number2);
                if(temp->left_child!=NULL&&temp->left_child->date==number1){
                    result = "Yes";
                }else{
                    result = "No";
                }
            }else if(eat_string=="right"){
                string_input>>eat_string>>eat_string>>number2;
                if(exist.find(number2)==exist.end()){
                    cout<<"No";
                    if(i!=n-1){
                        cout<<endl;
                    }
                    continue;
                }
                tree_node* temp = find(&input[0],number2);
                if(temp->rignt_child!=NULL&&temp->rignt_child->date==number1){
                    result = "Yes";
                }else{
                    result = "No";
                }
            }
        }else if(eat_string=="and"){
            string_input>>number2>>eat_string>>eat_string;
            if(exist.find(number2)==exist.end()){
                cout<<"No";
                if(i!=n-1){
                    cout<<endl;
                }
                continue;
            }
            if(eat_string=="on"){
                tree_node* temp = find(&input[0],number1);
                tree_node* temp1 = find(&input[0],number2);
                if(temp->layer==temp1->layer){
                    result = "Yes";
                }else{
                    result = "No";
                }
            }else{
                tree_node* temp = find(&input[0],number1);
                if(temp->father!=NULL&&((temp->father->left_child!=NULL&&temp->father->left_child->date==number2)||(temp->father->rignt_child!=NULL&&temp->father->rignt_child->date==number2))){
                    result = "Yes";
                }else{
                    result = "No";
                }
            }
        }
        cout<<result;
        if(i!=n-1){
            cout<<endl;
        }
    }

    return 0;
}
// 1.   查询值可能不在树上
// 2.   对于使用的每一个指针都要判断是不是NULL    否则就段错误了   记住,是每一个
