
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    //input
    char date[15];
    fscanf(stdin,"%s",&date);
    //output
    for(int i=6;i<10;++i){
        fprintf(stdout,"%c",date[i]);
    }
    fprintf(stdout,"-");
    for(int i=0;i<5;++i){
        fprintf(stdout,"%c",date[i]);
    }

    return 0;
}
