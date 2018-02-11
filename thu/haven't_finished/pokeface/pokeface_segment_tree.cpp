#include<iostream>
#include<cstdio>
#include<malloc.h>
#define size 1000000
using namespace std;

class segment_tree{
	public:
		segment_tree(int *given_array,int *given_sign);
		void update(int num);
		void build(int lef,int righ,int num);
		void pushdown(int num,int lef,int righ);
		void region_change(int change_lef,int change_righ,int lef,int righ,int num);
		int query(int search_lef,int search_righ,int lef,int righ,int num);
	private:
		int *sum;
		int *sign;
		int *array;
};
//构造函数
segment_tree::segment_tree(int *given_array,int *given_sign){
	sum=(int *)malloc((size<<2)*sizeof(int));
	sign=given_sign;
	array=given_array;
}
//更新节点信息
void segment_tree::update(int num){
	sum[num]=sum[num<<1]+sum[num<<1|1];
}
//构建线段树
void segment_tree::build(int lef,int righ,int num){
	if(lef==righ){
		sum[num]=array[lef];
		return;
	}
	int middle=(lef+righ)>>1;
	build(lef,middle,num<<1);
	build(middle+1,righ,num<<1|1);
	update(num);
}

//下推函数
void segment_tree::pushdown(int num,int lef,int righ){
	int middle=(lef+righ)>>1;
	if(sign[num]!=0&&lef!=righ){
		if(sign[num<<1]){
			pushdown(num<<1,lef,middle);
		}
		if(sign[num<<1|1]){
			pushdown(num<<1|1,middle+1,righ);
		}
		sign[num<<1]=1;
		sign[num<<1|1]=1;
		sum[num<<1]=(middle-lef+1)-sum[num<<1];
		sum[num<<1|1]=(righ-middle)-sum[num<<1|1];
		sign[num]=0;
	}
	
}
//区间修改函数
void segment_tree::region_change(int change_lef,int change_righ,int lef,int righ,int num){
	int middle=(lef+righ)>>1;
	pushdown(num,lef,righ);
	if(change_lef<=lef&&righ<=change_righ){
		sum[num]=(righ-lef+1)-sum[num];
		sign[num]=1;
		return;
	}
	
	if(change_lef<=middle){
		region_change(change_lef,change_righ,lef,middle,num<<1);
	}
	if(change_righ>middle){
		region_change(change_lef,change_righ,middle+1,righ,num<<1|1);
	}
	update(num);
}
//区间查询函数
int segment_tree::query(int search_lef,int search_righ,int lef,int righ,int num){
	int middle=(lef+righ)>>1;
	pushdown(num,lef,righ);
	if(search_lef<=lef&&righ<=search_righ){
		return sum[num];
	}
	
	int ans=0;
	if(search_lef<=middle){
		ans=ans+query(search_lef,search_righ,lef,middle,num<<1);
	}
	if(search_righ>middle){
		ans=ans+query(search_lef,search_righ,middle+1,righ,num<<1|1);
	}
	return ans;
}

struct Act{
	char type;
	int from;
	int to;
};

int given_sign[4000100]={0};

int main(){
	//输入
	int n,m;
	fscanf(stdin,"%d %d",&n,&m);
	getchar();
	Act *act=(Act*)malloc(100100*sizeof(Act));
	for(int i=0;i<m;i++){
		fscanf(stdin,"%c %d %d",&act[i].type,&act[i].from,&act[i].to);
		getchar();
	}
	
	int *poke=(int*)malloc(1000100*sizeof(int));
	for(int i=0;i<1000100;i++){
		poke[i]=1;
	}
	
	segment_tree my_segment_tree(poke,given_sign);
	my_segment_tree.build(1,n,1);
	for(int i=0;i<m;i++){
		if(act[i].type=='H'){
			my_segment_tree.region_change(act[i].from,act[i].to,1,n,1);
		}
		if(act[i].type=='Q'){
			int count=my_segment_tree.query(act[i].from,act[i].to,1,n,1);
			cout<<count<<endl;
		}
	}
	return 0;
}