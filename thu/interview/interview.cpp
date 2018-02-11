#include<iostream>
#include<cstdio>
using namespace std;

struct SListNode{
	SListNode*prev;
	SListNode*succ;
	int interviewer;
};
//Circling list
struct List{
	SListNode*list_head;
	SListNode*list_data;
	int list_max_size;
	void init(SListNode*data,int size,SListNode*pnode,int inter){
		list_data=data;
		list_max_size=size;
		list_head=pnode;
		list_head->prev=list_head;
		list_head->succ=list_head;
		pnode->interviewer=inter;
	}
	SListNode*insertBehind(SListNode *pnode,int num,int inter,SListNode*last){
		SListNode*tmp=last;
		for(int i=1;i<num;i++){
			tmp=tmp->succ;
		}
		pnode->prev=tmp;
		pnode->succ=tmp->succ;
		pnode->prev->succ=pnode;
		pnode->succ->prev=pnode;
		pnode->interviewer=inter;
		return last;
	}
};

SListNode memory[1100];

int main(){
	int n,m;
	fscanf(stdin,"%d %d",&n,&m);
	int wait[1100];
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&(wait[i]));
	}
	List list;
	list.init(memory,1100,&(memory[0]),wait[0]);
	SListNode*temp;
	SListNode*last=&(memory[0]);
	for(int i=1;i<n;i++){
		int num=m;
		/*if(1==i){
			num=1;
		}
		if(i!=1&&i<m){
			num=m%i;
		}
		if(i!=1&&i>=m){
			num=m;
		}*/
		temp=&(memory[i]);
		int inter=wait[i];
		list.insertBehind(temp,num,inter,last);
		last=temp;
	}
	for(int i=0;i<n;i++){
		int output=temp->interviewer;
		fprintf(stdout,"%d ",output);
		temp=temp->prev;
	}
	return 0;
}