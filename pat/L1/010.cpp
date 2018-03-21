
#include<cstdio>
using namespace std;
int main(){
    //input
    long long int a[3];
    scanf("%lld %lld %lld",&a[0],&a[1],&a[2]);
    //deal with
    for(int j=0;j<3;++j){
        for(int i=0;i<2-j;++i){
            if(a[i]>a[i+1]){
                long long int temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
            }
        }
    }
    //output
    printf("%lld->%lld->%lld",a[0],a[1],a[2]);

    return 0;
}
//1 2. 9 10lines  do the right thing at the right time      last night, you write the bubble sort incorrectly.
