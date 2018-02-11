#include<cstdio>
#include<iostream>
using namespace std;

//cycle_list
struct listnode{
	listnode*prev;
	listnode*succ;
	char ball;
};
struct list{
	listnode*list_head;
	void initialize(listnode*pnode,char ball){
		list_head=pnode;
		list_head->prev=list_head;
		list_head->succ=list_head;
		list_head->ball=ball;
	}
	listnode*append(listnode*pnode,char ball){//这个是新加的  效果是在末尾添加  效率比下面的高
		pnode->prev=list_head->prev;
		pnode->succ=list_head;
		list_head->prev=pnode;
		pnode->prev->succ = pnode;
		pnode->ball=ball;
		return pnode;
    }
	listnode*insertbehind(listnode*pnode,int num,char ball){//这个是在任意位置添加  这里要修改  这个函数是在后面添加  那么问题来了  想在头元素前面添加怎么办
		if(0 == num){//这个其实是改变头元素
			pnode->prev=list_head->prev;
			pnode->succ=list_head;
			pnode->prev->succ=pnode;
			pnode->succ->prev=pnode;
			pnode->ball=ball;
			list_head = pnode;
			return pnode;
		}else{//这个是正常情况  在某个元素后面插入*/
			listnode*container=list_head;
			for(int i=1;i<num;i++){
				container=container->succ;
			}
			pnode->prev=container;
			pnode->succ=container->succ;
			pnode->prev->succ=pnode;
			pnode->succ->prev=pnode;
			pnode->ball=ball;
			return pnode;
		}
    }
};

listnode data[20100];
int rank=0;
int total;//这还不能改undigned int  突然就想起了C++ primer

int main(){
	int eliminate(int position,char colour,listnode*head,int &total,list *necklace);
	//输入
	char pearl[10100];
	gets(pearl);
	int n;
	fscanf(stdin,"%d",&n);
	int position[10100];
	char colour[10100];
	for(int i=0;i<n;++i){//
		fscanf(stdin,"%d %c",&position[i],&colour[i]);
	}
	//数组链表化
	static list necklace;
	necklace.initialize(&(data[rank++]),(pearl[0]));
	for(int i=1;0!=pearl[i];++i){
		necklace.append(&(data[rank++]),(pearl[i]));
		total=i+1;
	}
	//process
	for(int i=0;i<n;++i){
		eliminate(position[i],colour[i],necklace.list_head,total,&necklace);
		if(total==0){
			printf("-\n");
			continue;
		}else{
			listnode* tmp=necklace.list_head;
			fprintf(stdout,"%c",tmp->ball);
			tmp=tmp->succ;
			for(;tmp!=necklace.list_head;){
				fprintf(stdout,"%c",tmp->ball);
				tmp=tmp->succ;
			}
			cout<<endl;
		}
	}
	return 0;
}

int eliminate(int position,char colour,listnode*head,int &total,list *necklace){
	if(total==0){//删去了&&position==0
		necklace->initialize(&(data[rank++]),colour);
		total=1;
		return 0;
	}
	if(total>0){
		if(total>=2){
			int eliminateagain(listnode*last,int &total,list *necklace);
			listnode*tmp=head->prev;
			for(int i=0;i<position;i++){
				tmp=tmp->succ;
			}
			if(position>=2&&tmp->prev->ball==tmp->ball&&tmp->ball==colour){
				tmp->succ->prev=tmp->prev->prev;
				tmp->succ->prev->succ=tmp->succ;
				total=total-2;
				if(position==2){
					if(total==0){
						return 0;
					}
					necklace->list_head=tmp->succ;
					return 0;
				}
				listnode*last=tmp->prev->prev;
				eliminateagain(last,total,necklace);
				return 0;
			}
			if(position>=1&&position<=total-1&&tmp->succ->ball==tmp->ball&&tmp->ball==colour){
				tmp->prev->succ=tmp->succ->succ;
				tmp->prev->succ->prev=tmp->prev;
				total=total-2;
				if(position==1){
					if(total==0){
						return 0;
					}
					necklace->list_head=tmp->succ->succ;
					return 0;
				}
				listnode*last=tmp->prev;
				eliminateagain(last,total,necklace);
				return 0;
			}
			if(position<=total-2&&tmp->succ->succ->ball==tmp->succ->ball&&tmp->succ->ball==colour){
				tmp->succ=tmp->succ->succ->succ;
				tmp->succ->prev=tmp;
				total=total-2;
				if(position==0){
					if(total==0){
						return 0;
					}
					necklace->list_head=tmp->succ;
					return 0;
				}
				listnode*last=tmp;
				eliminateagain(last,total,necklace);
				return 0;
			}
		}
		if(total>=1){
			necklace->insertbehind(&(data[rank++]),position,colour);
			total=total+1;
			return 0;
		}
	}
	return 0;
}

int eliminateagain(listnode*last,int &total,list *necklace){
	if(total>=3){
		if(total>=4&&last->succ->succ!=necklace->list_head&&last->succ!=necklace->list_head&&last!=necklace->list_head&&last->prev->ball==last->ball&&last->ball==last->succ->ball&&last->succ->ball==last->succ->succ->ball){
			last->prev->prev->succ=last->succ->succ->succ;
			last->prev->prev->succ->prev=last->prev->prev;
			total=total-4;
			if(total==0){
				return 0;
			}
			if(last->prev==necklace->list_head){
				necklace->list_head=last->succ->succ->succ;
				return 0;
			}
			last=last->prev->prev;
			eliminateagain(last,total,necklace);
			return 0;
		}
		if(last->succ!=necklace->list_head&&last!=necklace->list_head&&last->prev->ball==last->ball&&last->ball==last->succ->ball){
			last->prev->prev->succ=last->succ->succ;
			last->prev->prev->succ->prev=last->prev->prev;
			total=total-3;
			if(total==0){
				return 0;
			}
			if(last->prev==necklace->list_head){
				necklace->list_head=last->succ->succ;
				return 0;
			}
			last=last->prev->prev;
			eliminateagain(last,total,necklace);
			return 0;
		}
		if(last->succ->succ!=necklace->list_head&&last->succ!=necklace->list_head&&last->ball==last->succ->ball&&last->ball==last->succ->succ->ball){
			last->prev->succ=last->succ->succ->succ;
			last->prev->succ->prev=last->prev;
			total=total-3;
			if(total==0){
				return 0;
			}
			if(last==necklace->list_head){
				necklace->list_head=last->succ->succ->succ;
				return 0;
			}
			last=last->prev;
			eliminateagain(last,total,necklace);
			return 0;
		}
	}
	return 0;
}


