
#include<cstdio>
using namespace std;

int main(){
    //input
    int a_capacity,b_capacity;
    fscanf(stdin,"%d %d\n",&a_capacity,&b_capacity);
    int n;
    fscanf(stdin,"%d",&n);
    int a_shout[n+5];
    int b_shout[n+5];
    int a_sum[n+5];
    int b_sum[n+5];
    for(int i=0;i<n;++i){
        fscanf(stdin,"%d %d %d %d",&a_shout[i],&a_sum[i],&b_shout[i],&b_sum[i]);
    }
    //deal with
    int a_can_drink = a_capacity;
    int b_can_drink = b_capacity;
    for(int i=0;i<n;++i){
        int temp = a_shout[i] + b_shout[i];
        if(a_sum[i]==temp&&b_sum[i]!=temp){
            --a_can_drink;
        }else if(a_sum[i]!=temp&&b_sum[i]==temp){
            --b_can_drink;
        }else{
            continue;
        }
        if(a_can_drink<0){
            printf("A\n");
            printf("%d",b_capacity-b_can_drink);
            return 0;

        }else if(b_can_drink<0){
            printf("B\n");
            printf("%d",a_capacity-a_can_drink);
            return 0;
        }
    }
}
