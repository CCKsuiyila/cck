
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int main(){
    //input
    int n;
    cin>>n;
    vector<string> result;
    for(int i=0;i<n;++i){
        string name;
        int breathing;
        int pulse;
        cin>>name>>breathing>>pulse;
        if(breathing<15||breathing>20||pulse<50||pulse>70){
            result.push_back(name);
        }
    }
    //output
    cout<<result[0];
    for(int i=1;i<result.size();++i){
        cout<<'\n'<<result[i];
    }

    return 0;
}




/*
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    //input and deal with and output
    int n;
    scanf("%d",&n);
    char name[4];
    char result[15][4];
    int count = 0;
    int breathing;
    int pulse;
    scanf("%s%d%d",&name,&breathing,&pulse);
    if(breathing<15||breathing>20||pulse<50||pulse>70){
        //printf("%s",name);
        for(int i=0;i<4;++i){
            result[count][i] = name[i];
            ++count;
        }
    }
    for(int i=1;i<n;++i){
        scanf("%s%d%d",&name,&breathing,&pulse);
        if(breathing<15||breathing>20||pulse<50||pulse>70){
            //printf("%s",name);
            for(int i=0;i<4;++i){
                result[count][i] = name[i];
            }
            ++count;
        }   
    }
    if(count>1){
        printf("%s",result[0]);
    }else if(count==1){
        printf("%s",result[0]);
        return 0;
    }else{
        return 0;
    }
    for(int i=1;i<count;++i){
        printf("\n%s",result[i]);
    }

    return 0;
}

//1.   cout<<name<<breathing<<pulse<<endl;  is forgotten
//2.    10line    rather than char *name = new char[20];
//3.   i don't know
*/
