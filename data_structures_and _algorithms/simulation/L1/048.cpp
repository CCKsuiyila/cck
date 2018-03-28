
#include<cstdio>
using namespace std;

int main(){
    //input
    int ra,ca;
    fscanf(stdin,"%d %d",&ra,&ca);
    int a[ra][ca];
    for(int i=0;i<ra;++i){
        for(int j=0;j<ca;++j){
            fscanf(stdin,"%d",&a[i][j]);
        }
    }
    int rb,cb;
    fscanf(stdin,"%d %d",&rb,&cb);
    int b[rb][cb];
    for(int i=0;i<rb;++i){
        for(int j=0;j<cb;++j){
            fscanf(stdin,"%d",&b[i][j]);
        }
    }
    if(ca!=rb){
        fprintf(stdout,"Error: %d != %d",ca,rb);
        return 0;
    }
    int result[ra][cb];
    fprintf(stdout,"%d %d\n",ra,cb);
    for(int i=0;i<ra;++i){
        for(int j=0;j<cb;++j){
            int sum = 0;
            for(int k=0;k<ca;++k){
                sum += a[i][k]*b[k][j];
            }
            result[i][j] = sum;
        }
    }
    //output
    fprintf(stdout,"%d",result[0][0]);
    for(int i=1;i<cb;++i){
        fprintf(stdout," %d",result[0][i]);
    }
    for(int i=1;i<ra;++i){
        fprintf(stdout,"\n%d",result[i][0]);
        for(int j=1;j<cb;++j){
            fprintf(stdout," %d",result[i][j]);
        }
    }
    return 0;
}

//test   but i think the format is wrong
