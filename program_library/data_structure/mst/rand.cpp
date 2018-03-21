#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;
int main(int argc,char* argv[]){
	int genRandPoints(int,FILE*);
	if (2!=argc){
		fprintf(stderr,"usage: rand xxx\nxxx is the number of points to gen\n");
		return 1;
	}
	int num;
	if (1!=sscanf(argv[1],"%d",&num)||num<0){
		fprintf(stderr,"error reading number\n");
		return 2;
	}
	genRandPoints(num,stdout);
	return 0;
}

int rand10000(){
	return rand()%10000;
}

int genRandPoints(int n,FILE* fp){
	srand((unsigned int)time(0));
	int count=0;
	fprintf(fp,"%d\n",n);
	set<int> dict;
	while(count<n){
		int x=rand10000();
		int y=rand10000();
		int key=x*10000+y;
		if (dict.find(key)!=dict.end()) continue;
		dict.insert(key);
		fprintf(fp,"%d %d\n",x,y);
		count++;
	}
	return 0;
}