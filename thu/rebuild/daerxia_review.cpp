//对 回忆一下自己的做题思路(最近每做一题就把这个粘过去)
//1.先理解题
//2.确定解题思路(选择数据结构算法什么的)   确定能解决正常情况,也不用考虑太多复杂度
//3.2达到之后, 开始考虑各种解决可能遇到的奇怪情况   然后看看有没有复杂度更低的思路

//这道题比真二叉树重构那道简单一些吧     树的话  暂时都用递归吧     有感觉直接上手
//结果感觉和从新做一样   没有灵感    突然之间就怀疑自己这样做是不是有些浪费时间
//跟怕的是这样把自己的热情消磨掉

//最终直接把原来的改了改   虽然记不得自己原来花了多少时间,也记不得当时是不是找别人的模仿了 
//但是感觉当时写的真是简洁
//感觉应该把那些经典的东西记到脑子里    不用每次都重新写    复习的目的就在此吧  
//是时候改变了

#include<iostream>
#include<cstdio>
using namespace std;

//treeNode
class treeNode{
public:
	treeNode();
	treeNode* leftchild;
	treeNode* rightchild;
	int data;
};
treeNode::treeNode(){
	treeNode* leftchild = NULL;
	treeNode* rightchild = NULL;
	data = 0;
}

int sign=9;
treeNode* treeStore= new treeNode[500100];
int count_treeStore=0;

//output函数
int output(treeNode*root){
	if(NULL!=root->leftchild){
		output(root->leftchild);
	}
	if(NULL!=root->rightchild){
		output(root->rightchild);
	}
	fprintf(stdout,"%d ",root->data);
	return 0;
}

//构造树函数
treeNode *rebuild(int *preorder,int *inorder,int prefrom,int infrom,int length){
	if(length<=0){
		return NULL;
	}
	treeNode *root=&(treeStore[count_treeStore++]);
	root->data=preorder[prefrom];
	int i,j;
	for(i=infrom,j=0;j<length&&inorder[i]!=preorder[prefrom];++i,++j);
	if(j==length){
		sign=6;
		return NULL;
	}
	root->leftchild=rebuild(preorder,inorder,prefrom+1,infrom,i-infrom);
	root->rightchild=rebuild(preorder,inorder,prefrom+i-infrom+1,i+1,length-i+infrom-1);
	return root;
}

int main(){
	//input
	int n;
	fscanf(stdin,"%d",&n);
	int* preorder=new int[500100];
	int* inorder= new int[500100];
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&preorder[i]);
	}
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&inorder[i]);
	}
	
	//process
	treeNode*tree_root=rebuild(preorder,inorder,0,0,n);
	
	//output
	if(sign==9){
		output(tree_root);
	}else{
		fprintf(stdout,"%d ",-1);
	}
	
	return 0;
}
