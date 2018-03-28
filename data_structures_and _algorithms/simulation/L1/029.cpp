
#include<cstdio>
using namespace std;

int main(){
    //input
    int h;
    scanf("%d",&h);
    //deal with
    double result = h - 100.00;
    result *= 0.9*2;
    //output
    printf("%.1f",result);

    return 0;
}
