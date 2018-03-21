
#include<cstdio>
using namespace std;

int main(){
    //input
    int a,b;
    scanf("%d %d",&a,&b);
    if(b>0){
        double temp = a*1.00/b;
        printf("%d/%d=%.2f",a,b,temp);
    }else if(b==0){
        printf("%d/%d=Error",a,b);
    }else{
        double temp = a*1.00/b;
        printf("%d/(%d)=%.2f",a,b,temp);
    }

    return 0;
}
