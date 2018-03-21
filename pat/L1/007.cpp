
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;

int main(){
    //input
    int give_number;
    scanf("%d",&give_number);
    //deal with
    if(give_number<0){
        printf("%s ","fu");
        give_number = -give_number;
    }
    string temp = to_string(give_number);
    //output
    char *output = (char*)malloc(temp.size()*4);
    for(int i=0;i<temp.size();++i){
        switch (temp[i]){
            case '0':
                strcat(output,"ling ");
                break;
            case '1':
                strcat(output,"yi ");
                break;
            case '2':
                strcat(output,"er ");
                break;
            case '3':
                strcat(output,"san ");
                break;
            case '4':
                strcat(output,"si ");
                break;
            case '5':
                strcat(output,"wu ");
                break;
            case '6':
                strcat(output,"liu ");
                break;
            case '7':
                strcat(output,"qi ");
                break;
            case '8':
                strcat(output,"ba ");
                break;
            case '9':
                strcat(output,"jiu ");
                break;
        }
    }
    output[strlen(output)-1] = '\0';
    printf("%s",output);

    return 0;
}
//2.  54line   i am not clear about the strlen
//i directly improve the I/O and overleap the problem

/*
//1.   ' ' at the end is redundant
#include<cstdio>
#include<string>
using namespace std;

int main(){
    //input
    int give_number;
    scanf("%d",&give_number);
    //deal with
    if(give_number<0){
        printf("%s ","fu");
        give_number = -give_number;
    }
    string temp = to_string(give_number);
    for(int i=0;i<temp.size();++i){
        switch (temp[i]){
            case '0':
                printf("%s ","ling");
                break;
            case '1':
                printf("%s ","yi");
                break;
            case '2':
                printf("%s ","er");
                break;
            case '3':
                printf("%s ","san");
                break;
            case '4':
                printf("%s ","si");
                break;
            case '5':
                printf("%s ","wu");
                break;
            case '6':
                printf("%s ","liu");
                break;
            case '7':
                printf("%s ","qi");
                break;
            case '8':
                printf("%s ","ba");
                break;
            case '9':
                printf("%s ","jiu");
                break;
        }
    }

    return 0;
}
*/
