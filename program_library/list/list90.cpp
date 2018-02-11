//this is my list. 
//感觉还差个删除元素的函数   但是Zuma这题有点乱了  这会就不改了   下次有空改呗 或者下个题

//https://dsa.cs.tsinghua.edu.cn/oj/course.shtml?courseid=45 zuma测试通过
#include<cstdio>
#include<iostream>
using namespace std;

//cycle_list
class listnode{
	public://这仨要是私有的就会一堆错误
		listnode*prev;
		listnode*succ;
		char ball;
};
class list{
	public:
		list(int length);//构造函数,length为列表的最大长度,也就是总共申请多少内存
		listnode*list_head;//头指针
		int total;//列表元素总数
		void initialize(char ball);//初始化列表,并创建第一个元素
		listnode*append(char ball);//在列表末尾添加元素
		listnode*insertbehind(int num,char ball);//在任意位置添加 假设列表元素序号从1开始   num为1指在第一个元素后添加元素   num为0是特殊情况,此时将在第一个元素前面添加元素,并且新添加元素成为头元素(改变头指针)
	private: 
		int rank;//内存用到哪了
		listnode* data;//申请的内存
};

void list::initialize(char ball){//初始化列表,并创建第一个元素
			listnode*pnode = &(data[rank++]);
			list_head=pnode;
			list_head->prev=list_head;
			list_head->succ=list_head;
			list_head->ball=ball;
			total = 1;
}
listnode* list::append(char ball){//在列表末尾添加元素
			listnode*pnode = &(data[rank++]);
			pnode->prev=list_head->prev;
			pnode->succ=list_head;
			list_head->prev=pnode;
			pnode->prev->succ = pnode;
			pnode->ball=ball;
			total = total + 1;
			return pnode;
}
listnode* list::insertbehind(int num,char ball){//在任意位置添加 假设列表元素序号从1开始   num为1指在第一个元素后添加元素   num为0是特殊情况,此时将在第一个元素前面添加元素,并且新添加元素成为头元素(改变头指针)
			listnode*pnode = &(data[rank++]);
			if(0 == num){//这个其实是改变头元素
				pnode->prev=list_head->prev;
				pnode->succ=list_head;
				pnode->prev->succ=pnode;
				pnode->succ->prev=pnode;
				pnode->ball=ball;
				list_head = pnode;
				total = total + 1;
				return pnode;
			}else{//这个是正常情况  在某个元素后面插入
				listnode*container=list_head;
				for(int i=1;i<num;i++){
					container=container->succ;
				}
				pnode->prev=container;
				pnode->succ=container->succ;
				pnode->prev->succ=pnode;
				pnode->succ->prev=pnode;
				pnode->ball=ball;
				total = total + 1;
				return pnode;
			}
}
list::list(int length){
	data = new listnode[length+10];
	rank = 0;
	total = 0;
}


int main(){
	int eliminate(int position,char colour,listnode*head,list *necklace);
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
	static list necklace(20100);
	necklace.initialize(pearl[0]);
	for(int i=1;0!=pearl[i];++i){
		necklace.append(pearl[i]);
	}
	//process
	for(int i=0;i<n;++i){
		eliminate(position[i],colour[i],necklace.list_head,&necklace);
		if((necklace.total)==0){
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

int eliminate(int position,char colour,listnode*head,list *necklace){
	if((necklace->total)==0){//删去了&&position==0
		necklace->initialize(colour);
		return 0;
	}
	if((necklace->total)>0){
		if((necklace->total)>=2){
			int eliminateagain(listnode*last,list *necklace);
			listnode*tmp=head->prev;
			for(int i=0;i<position;i++){
				tmp=tmp->succ;
			}
			if(position>=2&&tmp->prev->ball==tmp->ball&&tmp->ball==colour){
				tmp->succ->prev=tmp->prev->prev;
				tmp->succ->prev->succ=tmp->succ;
				(necklace->total) = (necklace->total) - 2;
				if(position==2){
					if((necklace->total)==0){
						return 0;
					}
					necklace->list_head=tmp->succ;
					return 0;
				}
				listnode*last=tmp->prev->prev;
				eliminateagain(last,necklace);
				return 0;
			}
			if(position>=1&&position<=((necklace->total)-1)&&tmp->succ->ball==tmp->ball&&tmp->ball==colour){
				tmp->prev->succ=tmp->succ->succ;
				tmp->prev->succ->prev=tmp->prev;
				(necklace->total) = (necklace->total) - 2;
				if(position==1){
					if((necklace->total)==0){
						return 0;
					}
					necklace->list_head=tmp->succ->succ;
					return 0;
				}
				listnode*last=tmp->prev;
				eliminateagain(last,necklace);
				return 0;
			}
			if(position<=((necklace->total)-2)&&tmp->succ->succ->ball==tmp->succ->ball&&tmp->succ->ball==colour){
				tmp->succ=tmp->succ->succ->succ;
				tmp->succ->prev=tmp;
				(necklace->total) = (necklace->total) - 2;
				if(position==0){
					if((necklace->total)==0){
						return 0;
					}
					necklace->list_head=tmp->succ;
					return 0;
				}
				listnode*last=tmp;
				eliminateagain(last,necklace);
				return 0;
			}
		}
		if((necklace->total)>=1){
			necklace->insertbehind(position,colour);
			//(necklace->total) += 1;   就因为这个浪费半天时间, 这改完95分了
			return 0;
		}
	}
	return 0;
}

int eliminateagain(listnode*last,list *necklace){
	if((necklace->total)>=3){
		if((necklace->total)>=4&&last->succ->succ!=necklace->list_head&&last->succ!=necklace->list_head&&last!=necklace->list_head&&last->prev->ball==last->ball&&last->ball==last->succ->ball&&last->succ->ball==last->succ->succ->ball){
			last->prev->prev->succ=last->succ->succ->succ;
			last->prev->prev->succ->prev=last->prev->prev;
			(necklace->total) = (necklace->total) - 4;
			if((necklace->total)==0){
				return 0;
			}
			if(last->prev==necklace->list_head){
				necklace->list_head=last->succ->succ->succ;
				return 0;
			}
			last=last->prev->prev;
			eliminateagain(last,necklace);
			return 0;
		}
		if(last->succ!=necklace->list_head&&last!=necklace->list_head&&last->prev->ball==last->ball&&last->ball==last->succ->ball){
			last->prev->prev->succ=last->succ->succ;
			last->prev->prev->succ->prev=last->prev->prev;
			(necklace->total) = (necklace->total) - 3;;
			if((necklace->total)==0){
				return 0;
			}
			if(last->prev==necklace->list_head){
				necklace->list_head=last->succ->succ;
				return 0;
			}
			last=last->prev->prev;
			eliminateagain(last,necklace);
			return 0;
		}
		if(last->succ->succ!=necklace->list_head&&last->succ!=necklace->list_head&&last->ball==last->succ->ball&&last->ball==last->succ->succ->ball){
			last->prev->succ=last->succ->succ->succ;
			last->prev->succ->prev=last->prev;
			(necklace->total) = (necklace->total) - 3;
			if((necklace->total)==0){
				return 0;
			}
			if(last==necklace->list_head){
				necklace->list_head=last->succ->succ->succ;
				return 0;
			}
			last=last->prev;
			eliminateagain(last,necklace);
			return 0;
		}
	}
	return 0;
}


