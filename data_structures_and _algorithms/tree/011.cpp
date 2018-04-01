
//https://www.patest.cn/contests/gplt/L2-011

//20180331  review
#include<bits/stdc++.h>
using namespace std;

vector<int> inorder(50),preorder(50);

struct tree_node{
    tree_node* father = NULL;
    tree_node* left_child = NULL;
    tree_node* right_child = NULL;
    int key = -1, layer = -1;
};

tree_node* tree_store = new tree_node[50];
int count_tree_store = 0;

tree_node* build_tree(int prefrom,int infrom,int length,int layer){
    if(length<=0){
        return nullptr;
    }
    int temp = infrom;
    while(inorder[temp]!=preorder[prefrom]) ++temp;
    tree_node* temp_root = &(tree_store[count_tree_store++]);
    temp_root->key = preorder[prefrom];
    temp_root->layer = layer;
    temp_root->left_child = build_tree(prefrom+1,infrom,temp-infrom,++layer);
    temp_root->right_child = build_tree(temp-infrom+prefrom+1,temp+1,length-(temp-infrom)-1,++layer);
    return temp_root;
}

void swap1(tree_node* change){
    if(change->left_child!=nullptr){
        swap1(change->left_child);
    }
    if(change->right_child!=nullptr){
        swap1(change->right_child);
    }
    tree_node* temp = change->left_child;
    change->left_child = change->right_child;
    change->right_child = temp;
}
int main(){
    int n;  cin>>n;
    for(int i=0;i<n;++i) cin>>inorder[i];
    for(int i=0;i<n;++i) cin>>preorder[i];

    tree_node* tree_root = build_tree(0,0,n,0);
    swap1(tree_root);
    vector<tree_node*> result;
    result.push_back(tree_root);
    for(int i=0;i<result.size();++i){
        if(result[i]->left_child!=nullptr){
            result.push_back(result[i]->left_child);
        }
        if(result[i]->right_child!=nullptr){
            result.push_back(result[i]->right_child);
        }
    }
    for(int i=0;i<result.size();++i){
        cout<<result[i]->key;
        if(i!=result.size()-1){
            cout<<' ';
        }
    }
}


/*
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

//output函数
int output(treeNode*root){
	if(NULL!=root->leftchild){
		output(root->leftchild);
	}
	if(NULL!=root->rightchild){
		output(root->rightchild);
	}

    treeNode *temp;
    temp = root->leftchild;
    root->leftchild = root->rightchild;
    root->rightchild = temp;
	return 0;
}



int main(){
	//input
	int n;
	fscanf(stdin,"%d",&n);
	int* preorder=new int[500100];
	int* inorder= new int[500100];
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&inorder[i]);
	}
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&preorder[i]);
	}

	//process
	treeNode*tree_root=rebuild(preorder,inorder,0,0,n);
	output(tree_root);
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
*/


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

