
#include<cstdio>
using namespace std;

int main(){
    //input
    int n;
    scanf("%d",&n);
    //deal with
    n += 2;
    if(n<=7){
        printf("%d",n);
    }else{
        n = n%7;
        printf("%d",n);
    }
        
    return 0;
}
