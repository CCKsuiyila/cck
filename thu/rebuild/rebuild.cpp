#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

struct treenode{
	treenode*leftchild;
	treenode*rightchild;
	int data;
};
int sign=9;
treenode*tree=(treenode*)malloc(500100*sizeof(treenode));
int m=0;
int main(){
	int output(treenode*root);
	treenode *rebuild(int *preorder,int *inorder,int prefrom,int infrom,int length);
	int n;
	scanf("%d",&n);
	int *preorder=(int*)malloc(500100*sizeof(int));
	int *inorder=(int*)malloc(500100*sizeof(int));
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&preorder[i]);
	}
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&inorder[i]);
	}
	treenode*tree_root=rebuild(preorder,inorder,0,0,n);
	if(sign==9){
		output(tree_root);
	}else{
		fprintf(stdout,"%d ",-1);
	}
	return 0;
}

treenode *rebuild(int *preorder,int *inorder,int prefrom,int infrom,int length){
	if(length<=0){
		return NULL;
	}
	treenode *root=&(tree[m++]);
	root->data=preorder[prefrom];
	int i,j;
	for(i=infrom,j=0;j<length&&inorder[i]!=preorder[prefrom];i++,j++);
	if(j==length){
		sign=6;
		return NULL;
	}
	root->leftchild=rebuild(preorder,inorder,prefrom+1,infrom,i-infrom);
	root->rightchild=rebuild(preorder,inorder,prefrom+i-infrom+1,i+1,length-i+infrom-1);
	return root;
}

int output(treenode*root){
	
	if(NULL!=root->leftchild){
		output(root->leftchild);
	}
	if(NULL!=root->rightchild){
		output(root->rightchild);
	}
	fprintf(stdout,"%d ",root->data);
	return 0;
}
