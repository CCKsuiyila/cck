//从0到15到10到40到55 过了前11组数据,后面的都是超时,最后一组溢出
//这次酸水写的比较多吧,但是写的太水了   过度自信没有分块是一个大原因
/*	2017-02-22 00:48:40	55.0/100.0	 	很大的逻辑错误
 	2017-02-22 00:09:50	40.0/100.0	 	加上清理空指针
 	2017-02-22 00:08:15	40.0/100.0	 	-3变成-2
 	2017-02-21 23:17:40	10.0/100.0	 	那些清理废弃指针先注释掉
 	2017-02-21 22:54:01	10.0/100.0	 	>=1改为>=3
 	2017-02-21 22:15:40	15.0/100.0	 	100010改为1000100
 	2017-02-21 22:14:15	15.0/100.0	 	int main之前检查过
 	2017-02-21 19:33:27	0.0/100.0	 
*/
//竟然都是这种错误	希望没有下次了
//不过比较好的地方就是,当时从下不了手的状态变得能下手了   不再想着一下就写得最好了
//接下来的任务就是改善时间复杂度了   邮递员(tsp)那个题也是.
#include<iostream>
#include<cstdio>
using namespace std;

//tree_with_list
class tree_node{
	public://从此类都这么写吧,不然缩进也挺麻烦的
	tree_node();
	tree_node* leftchild;
	tree_node* rightchild;
	tree_node* father;
	tree_node* prev;
	tree_node* succ;
	int data;
};
tree_node::tree_node(){
	leftchild = NULL;
	rightchild = NULL;
	father = NULL;
	prev = NULL;
	succ = NULL;
	data = 0;
}

class tree{
	public:
	tree(int length);
	tree_node* tree_head;
	int total;
	void initialize(int value);
	tree_node* append(int value);
	private:
	int rank;
	tree_node* store;
};

tree::tree(int length){
	tree_head = NULL;
	total = 0;
	rank = 0;
	store = new tree_node[length+10];
}

void tree::initialize(int value){
	tree_head = &(store[rank++]);
	tree_head->prev=tree_head;
	tree_head->succ=tree_head;
	tree_head->data=value;
	total = 1;	
}

tree_node* tree::append(int value){
	tree_node* pnode = &(store[rank++]);
	pnode->prev = tree_head->prev;
	pnode->succ = tree_head;
	tree_head->prev = pnode;
	pnode->prev->succ = pnode;
	pnode->data = value;
	total = total + 1;
	return pnode;
}

int output(tree_node* a){
	if(a->leftchild != NULL){
		output(a->leftchild);
	}
	fprintf(stdout, "%d ", a->data);
	if(a->rightchild != NULL){
		output(a->rightchild);
	}
	return 0;
}

int main(){
	//input
	int n;
	fscanf(stdin, "%d", &n);
	//先序遍历输入
	int input;
	tree preorder_tree(1000100);
	fscanf(stdin, "%d", &(input));
	preorder_tree.initialize(input);
	for(int i = 1; i < n; ++i){
		fscanf(stdin, "%d", &(input));
		preorder_tree.append(input);
	}
	//后序遍历输入
	tree postorder_tree(1000100);
	fscanf(stdin, "%d", &(input));
	postorder_tree.initialize((input));
	for(int i = 1; i < n; ++i){
		fscanf(stdin, "%d", &(input));
		postorder_tree.append(input);
	}
	//输入还是有一点疑点,暂时找不出来, 先跳过看后面
	//process
	while(preorder_tree.total >= 3){
		int sign = 0;
		for(tree_node* i = preorder_tree.tree_head; 0 == sign; i = i->succ ){
			for(tree_node* j = postorder_tree.tree_head; 0 == sign ;j = j->succ){
				if(i->data == j->data){
					if((i->succ->data == j->prev->prev->data)&&(i->succ->succ->data == j->prev->data)){
						sign = 1;
						//建立i的父子关系
						i->leftchild = i->succ;
						i->rightchild = i->succ->succ;
						i->leftchild->father = i;
						i->rightchild->father = i;
						//清除i以及i儿子的列表关系
						i->succ = i->rightchild->succ;
						i->succ->prev = i;
					
						i->leftchild->prev = NULL;
						i->rightchild->prev = NULL;
						i->leftchild->succ = NULL;
						i->rightchild->succ = NULL;
					
						//清除j及其儿子的列表关系
						if(j->prev->prev == postorder_tree.tree_head){
							postorder_tree.tree_head = j;
						}
						tree_node* temp = j->prev;
						j->prev->prev->prev->succ = j;
						j->prev = j->prev->prev->prev;
					
						temp->prev->prev = NULL;
						temp->prev->succ = NULL;
						temp->prev = NULL;
						temp->succ = NULL;
					
						preorder_tree.total = preorder_tree.total - 2;
						postorder_tree.total = postorder_tree.total - 2;
					}
					break;
				}
			}
		}
	}
	
	//output
	output(preorder_tree.tree_head);
	return 0;
}



	
