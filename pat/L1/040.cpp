
#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    //input
    int n;
    //cin>>n;
    fscanf(stdin,"%d",&n);
    for(int i=0;i<n;++i){
        char sex;
        double height;
        cin>>sex>>height;
        //fscanf(stdin,"%c %f",&sex,&height);
        if(sex=='M'){
            fprintf(stdout,"%.2f\n",height/1.09);
        }else{
            fprintf(stdout,"%.2f\n",height*1.09);
        }
    }

    return 0;
}

// 8 9 are all correct  
// but 13 is correct but 14 is incorrect
