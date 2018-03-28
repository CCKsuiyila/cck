
//https://www.patest.cn/contests/gplt/L2-015

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

bool compare(double a, double b){
    return a>b;
}
int main(){
    //input
    int row_number,column_number,output_number;
    cin>>row_number>>column_number>>output_number;
    vector<double> result;
    for(int i=0;i<row_number;++i){
        vector<int> one_people;
        int sum = 0;
        for(int j=0;j<column_number;++j){
            int score;
            cin>>score;
            sum += score;
            one_people.push_back(score);
        }
        sort(one_people.begin(),one_people.end());
        sum = sum - one_people[0] - one_people[one_people.size()-1];
        double average = 1.00000*sum/(column_number-2);
        result.push_back(average);
    }
    //deal with
    sort(result.begin(),result.end(),compare);
    //output
    if(output_number==0){
        return 0;
    }
    printf("%.3f",result[output_number-1]);
    for(int i=output_number-2;i>=0;--i){
        printf(" %.3f",result[i]);
    }


    return 0;
}
//1 2. 12line    use this first   so...     result is double   so a and b should be double
