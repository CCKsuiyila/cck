//对 回忆一下自己的做题思路(最近每做一题就把这个粘过去)
//1.先理解题
//2.确定解题思路(选择数据结构算法什么的)   确定能解决正常情况,也不用考虑太多复杂度
//3.2达到之后, 开始考虑各种解决可能遇到的奇怪情况   然后看看有没有复杂度更低的思路

//读完题,知道要用字典树,但是脑子里没有这个数据结构实现的具体细节   就不重新来一遍了
//把原来的看明白  然后优化一下就好
//把原来C的都改成C++了   但是还是40分    提示是用字典树动态扩容   我感觉我用的就是动态扩容(按比例算,够90分了,就这样吧)

#include<iostream>
#include<cstdio>
#include<string.h>
#define MAX 26
using namespace std;

class TrieNode{
public:
	TrieNode();
	TrieNode *next[MAX];
	int v;
};
TrieNode::TrieNode(){
	for(int j=0;j<MAX;++j){
		next[j]=NULL;
	}
	v=0;
}

int count=0;
//生成字典树
int createTrie(char*str,TrieNode *root){
	int len=strlen(str);
	TrieNode* p=root;
	for(int i=0;i<len;++i){
		int index=str[i]-'a';
		if((p->next[index])!=NULL){//这里出问题了
			p=p->next[index];
		}else{
			TrieNode* q = new TrieNode;
			p->next[index]=q;
			p=p->next[index];
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
	TrieNode* root=new TrieNode;  //(TrieNode*)malloc(sizeof(TrieNode));//修改了这里解决了问题
	int n;
	fscanf(stdin,"%d",&n);
	getchar();
	int a;
	for(int i=0;i<n;++i){
		char* name=new char[9];
		gets(name);
		a=createTrie(name,root);
		if(a!=0){
			for(int i=0;i<=strlen(name);++i){
				output[i]=name[i];
			}	
		}
		delete [] name;   //free(name);
	}
	fprintf(stdout,"%s %d",output,count);
	return 0;
}