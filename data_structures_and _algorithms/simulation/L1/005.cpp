
//with C's I/O and C++'s string class
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;

class save{
public:
    string identity;
    int test_number;
    int seat_number;
};
int main(){
    //input
    save give_data[1005];
    int quantity;
    scanf("%d\n",&quantity);
    char temp1[15];
    int temp2;
    int temp3;
    for(int i=0;i<quantity;++i){
        scanf("%s %d %d\n",&temp1,&temp2,&temp3);
        give_data[temp2].identity = temp1;
        give_data[temp2].test_number = temp2;
        give_data[temp2].seat_number = temp3;
    }
    //deal with and output
    scanf("%d\n",&quantity);
    int target;
    for(int i=0;i<quantity;++i){
        scanf("%d",&target);
        printf("%s %d\n",give_data[target].identity.c_str(),give_data[target].seat_number);
    }

    return 0;
}
//1. 17line  >=1000  i use 1000,    but i want to know when to use that and when to use new



























/*
//with C++'s I/O and string class
#include<iostream>
#include<string>
using namespace std;

class save{
public:
    string identity;
    int test_number;
    int seat_number;
};
int main(){
    //input
    save give_data[1005];
    save temp;
    int quantity;
    cin>>quantity;
    for(int i=0;i<quantity;++i){
        cin>>temp.identity>>temp.test_number>>temp.seat_number;
        //scanf("%s %d %d\n",&temp.identity,&temp.test_number,&temp.seat_number);
        give_data[temp.test_number].identity = temp.identity;
        give_data[temp.test_number].test_number = temp.test_number;
        give_data[temp.test_number].seat_number = temp.seat_number;
    }
    cin>>quantity;
    //deal with and output
    int target;
    for(int i=0;i<quantity;++i){
        cin>>target;
        cout<<give_data[target].identity<<' '<<give_data[target].seat_number<<endl;
    }
    
    return 0;
}
*/

/*
// with C++'s I/O and String class
#include<cstdio>
#include<cstring>
using namespace std;

class save{
public:
    char *identity;
    int test_number;
    int seat_number;
};
int main(){
    //input
    save give_data[1005];
    save temp;
    int quantity;
    scanf("%d\n",&quantity);
    for(int i=0;i<quantity;++i){
        scanf("%s %d %d\n",&temp.identity,&temp.test_number,&temp.seat_number);
        strcpy(give_data[temp.test_number].identity,temp.identity);
        //give_data[temp.test_number].identity = temp.identity;
        give_data[temp.test_number].test_number = temp.test_number;
        give_data[temp.test_number].seat_number = temp.seat_number;
    }
    scanf("%d\n",&quantity);
    //deal with and output
    int target;
    while(scanf("%d",&target)){
        printf("%s %d\n",give_data[target].identity,give_data[target].seat_number);
    }
    
    return 0;
}
*/
