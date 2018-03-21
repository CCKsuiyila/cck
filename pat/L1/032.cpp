
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    //input
    int n;
    char sign;
    fscanf(stdin,"%d %c\n",&n,&sign);
    char *date = new char[20000];
    gets(date);
    if(n<strlen(date)){
        for(int i=strlen(date)-n;i<strlen(date);++i){
            fprintf(stdout,"%c",date[i]);
        }
    }else if(n==strlen(date)){
        fprintf(stdout,"%s",date); 
    }else{
        for(int i=0;i<n-strlen(date);++i){
            fprintf(stdout,"%c",sign);
        }
        fprintf(stdout,"%s",date); 
    }

    return 0;
}

//1.  14line  -n rather than -4
