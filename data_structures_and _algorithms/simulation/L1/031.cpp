
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    //input and deal with
    int n;
    fscanf(stdin,"%d",&n);
    for(int i=0;i<n;++i){
        int height;
        int w;
        fscanf(stdin,"%d %d",&height,&w);
        double standard = (height-100.00)*0.9*2;
        if(abs(standard-w)<standard*0.1){
            fprintf(stdout,"You are wan mei!\n");
        }else if(w<standard){
            fprintf(stdout,"You are tai shou le!\n");
        }else if(w>standard){
            fprintf(stdout,"You are tai pang le!\n");
        }
    }

    return 0;
}

