
#include<iostream>
using namespace std;

int main(){
    //input
    string input;
    cin>>input;
    //deal with
    int g = 0;
    int p = 0;
    int l = 0;
    int t = 0;
    for(int i=0;i<input.size();++i){
        if(input[i]=='g'||input[i]=='G'){
            ++g;
        }else if(input[i]=='p'||input[i]=='P'){
            ++p;
        }else if(input[i]=='l'||input[i]=='L'){
            ++l;
        }else if(input[i]=='t'||input[i]=='T'){
            ++t;
        }
    }
    while(g>0||p>0||l>0||t>0){
        if(g>0){
            fprintf(stdout,"%c",'G');
            --g;
        }
        if(p>0){
            fprintf(stdout,"%c",'P');
            --p;
        }
        if(l>0){
            fprintf(stdout,"%c",'L');
            --l;
        }if(t>0){
            fprintf(stdout,"%c",'T');
            --t;
        }
    }

    return 0;
}
