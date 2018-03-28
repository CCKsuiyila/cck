#include<cstdio>
using namespace std;

int main(){
    //input 
    int a,b;
    scanf("%d %d",&a,&b);
    //output
    int i,j;
    for(i=a,j=1;i<=b;++i,++j){
        printf("%5d",i);
        if(j%5==0){
            printf("\n");
        }
    }
    if(j%5!=1){
        printf("\n");
    }
    int sum = 0;
    if(a>=0){
        sum = (a+b)*(b-a+1)/2;
    }else{
        sum += (1+b)*b/2;
        a = -a;
        sum -= (1+a)*a/2;
    }
    printf("Sum = %d",sum);

    return 0;
}
//1. 12line   j rather than i
//2. 16line   j rather than i   and 1 rather than 0
