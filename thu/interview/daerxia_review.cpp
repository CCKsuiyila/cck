//这感觉真好    有编好的模板用    不到半个小时就出来了  还是一次过, 虽然这题比较简单(当然难点就在编那个模板吧)
//做题的过程中就不断封装自己的工具吧    以后会越来越快的
//工具越好   做题越快      这也是更高级的语言的优点之一吧   那么那些语言使用的难度可想而知不会很高
//现在先做难的事吧(相对而言)    简单的以后学 也不迟


//2017-02-27 09:46:02	     50.0/50.0
#include<cstdio>
using namespace std;

//cycle_list
class listnode{
	public://这仨要是私有的就会一堆错误
		listnode*prev;
		listnode*succ;
		int ball;
};
class list{
	public:
		list(int length);//构造函数,length为列表的最大长度,也就是总共申请多少内存
		listnode*list_head;//头指针
		int total;//列表元素总数
		void initialize(int ball);//初始化列表,并创建第一个元素
		listnode*append(int ball);//在列表末尾添加元素
		listnode*insertbehind(int num,int ball);//在任意位置添加 假设列表元素序号从1开始   num为1指在第一个元素后添加元素   num为0是特殊情况,此时将在第一个元素前面添加元素,并且新添加元素成为头元素(改变头指针)
	private: 
		int rank;//内存用到哪了
		listnode* data;//申请的内存
};

void list::initialize(int ball){//初始化列表,并创建第一个元素
			listnode*pnode = &(data[rank++]);
			list_head=pnode;
			list_head->prev=list_head;
			list_head->succ=list_head;
			list_head->ball=ball;
			total = 1;
}
listnode* list::append(int ball){//在列表末尾添加元素
			listnode*pnode = &(data[rank++]);
			pnode->prev=list_head->prev;
			pnode->succ=list_head;
			list_head->prev=pnode;
			pnode->prev->succ = pnode;
			pnode->ball=ball;
			total = total + 1;
			return pnode;
}
listnode* list::insertbehind(int num,int ball){//在任意位置添加 假设列表元素序号从1开始   num为1指在第一个元素后添加元素   num为0是特殊情况,此时将在第一个元素前面添加元素,并且新添加元素成为头元素(改变头指针)
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
	data = new listnode[length];
	rank = 0;
	total = 0;
}

int main(){
	//input
	int n,m;
	fscanf(stdin,"%d %d",&n,&m);
	int* input = new int[n+10];
	for(int i=0;i<n;++i){
		fscanf(stdin,"%d",&(input[i]));
	}
	//process
	list mylist(n);
	mylist.initialize(input[0]);
	for(int i=1;i<n;++i){
		listnode* change_list_head = mylist.insertbehind(m,input[i]);
		mylist.list_head = change_list_head;
	}
	//output
	listnode* temporary_index = mylist.list_head;
	for(int i=0;i<n;++i){
		fprintf(stdout,"%d ",temporary_index->ball);
		temporary_index = temporary_index->prev;
	}
	return 0;
}