
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

long long int greatest_common_divisor(long long int a,long long int b){
    long long int big;
    long long int little;
    if(a>b){
        big = a;
        little = b;
    }else{
        big = b;
        little = a;
    }
    long long int remainder=big%little;
    while(remainder!=0){
        big = little;
        little = remainder;
        remainder = big%little;
    }
    return little;
}

long long int least_common_multiple(long long int a,long long int b){
    long long int temp = greatest_common_divisor(a,b);
    long long int result = a/temp*b;
    return result;
}

void add(long long int *result_molecule,long long int *result_denominator,long int molecule,long int denominator){
    long long int temp_denominator = least_common_multiple(*result_denominator,denominator);
    long long int temp_molecule1 = temp_denominator/(*result_denominator)*(*result_molecule);
    long long int temp_molecule2 = temp_denominator/denominator*molecule;
    *result_molecule = temp_molecule1+temp_molecule2;
    *result_denominator = temp_denominator;
    //simplify
    if(*result_molecule==0){
        return;
    }
    long long int temp = greatest_common_divisor(abs(*result_molecule),*result_denominator);
    *result_molecule /= temp;
    *result_denominator /= temp;
}

int main(){
    //input
    int number;
    scanf("%d\n",&number);
    long int molecule[number+5];
    long int denominator[number+5];
    for(int i=0;i<number;++i){
        scanf("%ld/%ld",&molecule[i],&denominator[i]);
    }
    //deal with
    int i;
    long long int result_molecule = molecule[0];
    long long int result_denominator = denominator[0];
    for(i=1;i<number;++i){
        if(result_molecule==0||result_denominator==0){
            for(;i<number;++i){
                if(molecule[i]==0||denominator[i]==0){
                    continue;
                }else{
                    result_molecule = molecule[i];
                    result_denominator = denominator[i];
                    break;
                }
            }
            ++i;
        }
        if(molecule[i]==0||denominator[i]==0){
            continue;
        }
        add(&result_molecule,&result_denominator,molecule[i],denominator[i]);
    }

    //output
    long long int integer = result_molecule/result_denominator;
    result_molecule -= integer*result_denominator;
    if(integer!=0){
        printf("%lld",integer);
    }
    if(result_molecule!=0){
        if(integer!=0){
            printf(" ");
        }
        printf("%lld/%lld",result_molecule,result_denominator);
    }
    if(result_molecule==0&&integer==0){
        printf("0");
    }

    return 0;
}
//18 times      
//the problems that you meet:
//1.which variable should be long int and which should be long long int     
//2.when the result is negative, you don't know how to output
//3.91line to 93line     you don't know this condition
//4.86line to 88line     you don't know this condition
//5.39line to 41line     you don't know this condition
//6.61line to 75line     you don't know this condition
//
//importantly
//you solve the 1 and 2 with too much time. but an the truth, you can all use long long int for 1
//and for 2, all the type that you thought are correct.
//you should find what is the key
//althought the party have some bad influence, so you should know do the right thing at the right time
//be flexible next time

