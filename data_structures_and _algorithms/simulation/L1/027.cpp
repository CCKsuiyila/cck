
#include<cstdio>
#include<algorithm>
using namespace std;

bool comp(const int &a,const int &b){
    return a>b;
}

int main(){
    //input
    vector<int> number;
    for(int i=0;i<11;++i){
        char temp;
        fscanf(stdin,"%c",&temp);
        number.push_back(temp-'0');
    }
    //deal with
    vector<int> arr = number;
    sort(arr.begin(),arr.end(),comp);
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    vector<int> index;
    for(int i=0;i<11;++i){
        for(int j=0;j<arr.size();++j){
            if(arr[j]==number[i]){
                index.push_back(j);
                break;
            }
        }
    }
    //output
    fprintf(stdout,"%s","int[] arr = new int[]{");
    fprintf(stdout,"%d",arr[0]);
    for(int i=1;i<arr.size();++i){
        fprintf(stdout,",%d",arr[i]);
    }
    fprintf(stdout,"%s","};\nint[] index = new int[]{");
    fprintf(stdout,"%d",index[0]);
    for(int i=1;i<index.size();++i){
        fprintf(stdout,",%d",index[i]);
    }
    fprintf(stdout,"%s","};");

    return 0;
}
