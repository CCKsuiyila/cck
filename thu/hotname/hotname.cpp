#include<iostream>
#include<cstdio>
#include<malloc.h>
#include<string.h>
#define MAX 26
using namespace std;

struct Trie{
	Trie *next[MAX];
	int v;
};

int count=0;
//生成字典树
int createTrie(char*str,Trie *root){
	int len=strlen(str);
	Trie *p=root,*q;
	for(int i=0;i<len;i++){
		int id=str[i]-'a';
		if((p->next[id])!=NULL){//这里出问题了
			//p->next[id]->v=p->next[id]->v+1;
			p=p->next[id];
		}else{
			q=(Trie*)malloc(sizeof(Trie));
			q->v=0;
			for(int j=0;j<MAX;j++){
				q->next[i]=NULL;
			}
			p->next[id]=q;
			p=p->next[id];
		}
	}
	p->v=p->v+1;
	if((p->v)>count){
		count=p->v;
		return count;
	}else{
		return 0;
	}
}

int main(){
	char output[9];
	Trie *root=(Trie*)malloc(sizeof(Trie));//修改了这里解决了问题
	for(int i=0;i<MAX;i++){
		root->next[i]=NULL;
	}
	int n;
	fscanf(stdin,"%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		char*name=(char*)malloc(9*sizeof(char));
		gets(name);
		int a=createTrie(name,root);
		if(a!=0){
			for(int i=0;i<=strlen(name);i++){
				output[i]=name[i];
			}	
		}
		free(name);
	}
	printf("%s %d",output,count);
	return 0;
}