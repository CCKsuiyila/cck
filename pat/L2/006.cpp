
#include<iostream>
#include<cstdio>
#include<vector>
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


//构造树函数
treeNode *rebuild(int *postorder,int *inorder,int postfrom,int infrom,int length){
	if(length<=0){
		return NULL;
	}
	treeNode *root=&(treeStore[count_treeStore++]);
	root->data=postorder[postfrom];
	int i,j;
	for(i=infrom,j=0;j<length&&inorder[i]!=postorder[postfrom];++i,++j);
	if(j==length){
		sign=6;
		return NULL;
	}
	root->leftchild=rebuild(postorder,inorder,postfrom-(length-i+infrom-1)-1,infrom,i-infrom);
	root->rightchild=rebuild(postorder,inorder,postfrom-1,i+1,length-i+infrom-1);
	return root;
}


int main(){
	//input
	int n;
	fscanf(stdin,"%d",&n);
	int* postorder=new int[500100];
	int* inorder= new int[500100];
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&postorder[i]);
	}
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&inorder[i]);
	}
	
	//process
	treeNode*tree_root=rebuild(postorder,inorder,n-1,0,n);
	
	//output
	vector<treeNode*> result;
    result.push_back(tree_root);
    for(int i=0;i<result.size();++i){
        if(result[i]->leftchild!=NULL){
            result.push_back((result[i]->leftchild));
        }
        if(result[i]->rightchild!=NULL){
            result.push_back((result[i]->rightchild));
        }
    }

    
    if(result.size()==0){
        return 0;
    }else{
        cout<<result[0]->data;
    }
    for(int i=1;i<result.size();++i){
        cout<<' '<<result[i]->data;
    }
	return 0;
}

/*
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


//构造树函数
treeNode *rebuild(int *postorder,int *inorder,int postfrom,int infrom,int length){
	if(length<=0){
		return NULL;
	}
	treeNode *root=&(treeStore[count_treeStore++]);
	root->data=postorder[postfrom];
    cout<<postorder[postfrom];
	int i,j;
	for(i=infrom,j=0;j<length&&inorder[i]!=postorder[postfrom];++i,++j);
	if(j==length){
		sign=6;
		return NULL;
	}
	root->leftchild=rebuild(postorder,inorder,postfrom-(length-i+infrom-1)-1,infrom,i-infrom);
	root->rightchild=rebuild(postorder,inorder,postfrom-1,i+1,length-i+infrom-1);
	return root;
}

//output函数
int output(treeNode*root){
	fprintf(stdout,"%d ",root->data);
	if(NULL!=root->leftchild){
		output(root->leftchild);
	}
	if(NULL!=root->rightchild){
		output(root->rightchild);
	}
	return 0;
}

int main(){
	//input
	int n;
	fscanf(stdin,"%d",&n);
	int* postorder=new int[500100];
	int* inorder= new int[500100];
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&postorder[i]);
	}
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&inorder[i]);
	}
	
	//process
	treeNode*tree_root=rebuild(postorder,inorder,n-1,0,n);
	
	//output
	if(sign==9){
		output(tree_root);
	}else{
		fprintf(stdout,"%d ",-1);
	}
	
	return 0;
}
*/
