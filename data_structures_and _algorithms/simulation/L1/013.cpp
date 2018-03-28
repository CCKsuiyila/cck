#include<cstdio>
using namespace std;

int factorial(int n){
    int result = 1;
    for(int i=1;i<=n;++i){
        result *= i;
    }

    return result;
}

int main(){
    //input
    int n;
    scanf("%d",&n);
    //deal with
    int result = 0;
    for(int i=1;i<=n;++i){
        result += factorial(i);
    }
    //output
    printf("%d",result);

    return 0;
}
