#include<iostream>
#include<cstdio>
#include<malloc.h>
#include<string.h>
#define MAX 26
using namespace std;


int main(){
	int n;
	fscanf(stdin,"%d",&n);
	getchar();
	for(int i=0;i<MAX;i++){
		char*name=(char*)malloc(10*sizeof(char));
		gets(name);
		printf("%s\n",name);
		free(name);
	}
	return 0;
}