
#include<cstdio>
using namespace std;

int main(){
    //input
    int n;
    scanf("%d",&n);
    //deal with 
    int result = 1;
    for(int i=0;i<n;++i){
        result *= 2;
    }
    //output
    printf("2^%d = %d",n,result);

    return 0;
}
