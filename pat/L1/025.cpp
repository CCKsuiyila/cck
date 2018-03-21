
//20 score others   reference
#include <iostream>  
#include <cctype>  
using namespace std;  
bool islegal(string s) {  
    if(s.length() == 0)  
        return false;  
    for(int i = 0; i < s.length(); i++) {  
        if(!isdigit(s[i])) {  
            return false;  
        }  
    }  
    int temp = stoi(s);  
    if(temp < 1 || temp > 1000) {  
        return false;  
    }  
    return true;  
}  
  
int main() {  
    string a, b;  
    string t;  
    getline(cin, t);  
    for(int i = 0; i < t.length(); i++) {  
        if(t[i] == ' ') {  
            a = t.substr(0, i);  
            b = t.substr(i + 1, t.size()- i - 1);  
            break;  
        }  
    }  
    if(!islegal(a)) {  
        a = "?";  
    }  
    if(!islegal(b)) {  
        b = "?";  
    }  
    cout << a << " + " << b << " = ";  
    if(a != "?" && b != "?") {  
        int atemp = stoi(a);  
        int btemp = stoi(b);  
        cout << atemp + btemp;  
    } else {  
        cout << "?";  
    }  
    return 0;  
} 


/*
//14 score   i can't find the 1 score
#include<cstdio>
#include<cstring>

using namespace std;
int main(){
    //input
    char *input = new char[10000];
    //fgets(input,100,stdin);
    gets(input);
    //deal with
    int separation = 0;
    int sign_one = -1;
    int sign_two = -1;
    while(input[separation]!=' '){
        ++separation;
    }
    int zero = 0;
    while(input[zero]=='0'){
        ++zero;
    }
    if(separation-zero<=4){
        if(separation-zero==4&&input[zero+0]=='1'&&input[zero+1]=='0'&&input[zero+2]==0&&input[zero+3]==0){
            sign_one = 1000;
        }else if(separation-zero==3&&input[zero+0]<='9'&&input[zero+1]<='9'&&input[zero+2]<='9'&&input[zero+0]>='0'&&input[zero+1]>='0'&&input[zero+2]>='0'){
            sign_one = 0;
            sign_one += (input[zero+0] - '0')*100;
            sign_one += (input[zero+1] - '0')*10;
            sign_one += (input[zero+2] - '0');
        }else if(separation-zero==2&&input[zero+0]<='9'&&input[zero+1]<='9'&&input[zero+0]>='0'&&input[zero+1]>='0'){
            sign_one = 0;
            sign_one += (input[zero+0] - '0')*10;
            sign_one += (input[zero+1] - '0');
        }else if(separation-zero==1&&input[zero+0]<='9'&&input[zero+0]>='1'){
            sign_one = 0;
            sign_one += (input[zero+0] - '0');
        }
    }
    ++separation;
    //while(input[separation]=='0'){
    while(input[separation]==' '||input[separation]=='0'){
        ++separation;
    }
    --separation;
    int end_sign = separation + 1;
    while(input[end_sign]>='0'&&input[end_sign]<='9'){
        ++end_sign;
    }
    int count = end_sign - separation - 1;
    int space_number = 0;
    for(int i=end_sign;i<strlen(input)&&input[i]==' ';++i){
        ++space_number;
    }
    if(end_sign+space_number==strlen(input)&&count<=4){
        if(count==4&&input[separation+1]=='1'&&input[separation+2]=='0'&&input[separation+3]=='0'&&input[separation+4]=='0'){
            sign_two = 1000;
        }else if(count==3){
        //}else if(count==3&&input[separation+1]!='0'){
            sign_two = 0;
            sign_two += (input[separation+1] - '0')*100;
            sign_two += (input[separation+2] - '0')*10;
            sign_two += (input[separation+3] - '0');
        }else if(count==2){
        }else if(count==2&&input[separation+1]!='0'){
            sign_two = 0;
            sign_two += (input[separation+1] - '0')*10;
            sign_two += (input[separation+2] - '0');
        }else if(count==1&&input[separation+1]!='0'){
            sign_two = 0;
            sign_two += (input[separation+1] - '0');
        }
    }
    //output
    if(sign_one>0){
        fprintf(stdout,"%d",sign_one);
    }else{
        fprintf(stdout,"?");
    }
    fprintf(stdout," + ");
    if(sign_two>0){
        fprintf(stdout,"%d",sign_two);
    }else{
        fprintf(stdout,"?");
    }
    fprintf(stdout," = ");
    if(sign_one>0&&sign_two>0){
        fprintf(stdout,"%d",sign_one+sign_two);
    }else{
        fprintf(stdout,"?");
    }

    return 0;
}
//1.  39line   the baidu's introduction of the strlen  is wrong 
//2 3.            make sure if ' ' is after the B
//4.   the gets and fgets is different  and the strlen is correct for the 1 
//5.   35 to 38 line   make sure if ' ' is before the B
//6.   test  0111    the point is not here
//7.   "00022 55"  this case?
//8.   "1    1"   the point is not here
*/
