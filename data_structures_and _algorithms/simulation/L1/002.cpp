
#include<cstdio>
using namespace std;

int main(){
    //input
    int give_number;
    char give_sign;
    scanf("%d %c",&give_number,&give_sign);
    //find the line number
    int line_number;
    for(line_number=1;2*line_number*line_number-1<=give_number;++line_number){}
    --line_number;
    int output_number = give_number - 2*line_number*line_number+1;
    //output
    for(int i=line_number;i>0;--i){
        for(int j=0;j<line_number-i;++j){
            printf("%c",' ');
        }
        for(int k=0;k<2*i-1;++k){
            printf("%c",give_sign);
        }
        printf("\n");
    }
    for(int i=2;i<=line_number;++i){
        for(int j=0;j<line_number-i;++j){
            printf("%c",' ');
        }
        for(int k=0;k<2*i-1;++k){
            printf("%c",give_sign);
        }
        printf("\n");
    }
    printf("%d",output_number);
    return 0;
}

//1. 21line and 30 line  output the * rather than the give_sign
