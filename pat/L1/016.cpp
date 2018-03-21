
#include<cstdio>
using namespace std;

bool check(char *a){
    int weighting[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int sum = 0;
    for(int i=0;i<17;++i){
        if(a[i]<'0'||a[i]>'9'){
            return false;
        }
        sum += (a[i]-'0')*weighting[i];
    }
    int m[] = {1,0,10,9,8,7,6,5,4,3,2};
    int temp = m[sum%11];
    if(temp==10){
        if(a[17]=='X'){
            return true;
        }else{
            return false;
        }
    }else{
        if(temp==a[17]-'0'){
            return true;
        }else{
            return false;
        }
    }

}
int main(){
    //input and deal with
    int n;
    fscanf(stdin,"%d",&n);
    int sign = 0;
    for(int i=0;i<n;++i){
        char give_data[18+2];
        fscanf(stdin,"%s",&give_data);
        if(check(give_data)==false){
            fprintf(stdout,"%s\n",give_data);
            sign = 1;
        }
    }
    if(sign==0){
        fprintf(stdout,"%s","All passed");
    }

    return 0;
}
//  9line   '9'  rather than 9
//  25line  a[i]-'0' rather than a[i]
