#include<iostream>
#include<cstdio>
#include<malloc.h>
#define size 100007
using namespace std;

class segment_tree{
	public:
		segment_tree(int *given_array,int given_n);
		void update(int num);
		void build(int lef,int righ,int num);
		void point_change(int changed_num,int addend,int lef,int righ,int num);
		void pushdown(int num,int lef_amount,int righ_amount);
		void region_change(int change_lef,int change_righ,int addend,int lef,int righ,int num);
		int query(int search_lef,int search_righ,int lef,int righ,int num);
	private:
		int *sum;
		int *sign;
		int *array;
		int n;
};
//构造函数
segment_tree::segment_tree(int *given_array,int given_n){
	sum=(int *)malloc((size<<2)*sizeof(int));
	sign=(int*)malloc((size<<2)*sizeof(int));
	array=given_array;
	n=given_n;
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
//点修改
void segment_tree::point_change(int changed_num,int addend,int lef,int righ,int num){
	if(lef==righ){
		sum[num]=sum[num]+addend;
		return;
	}
	int middle=(lef+righ)>>1;
	if(changed_num<=middle){
		point_change(changed_num,addend,lef,middle,num<<1);
	}else{
		point_change(changed_num,addend,middle+1,righ,num<<1|1);
	}
	update(num);
}
//下推函数
void segment_tree::pushdown(int num,int lef_amount,int righ_amount){
	if(sign[num]){
		sign[num<<1]=sign[num<<1]+sign[num];
		sign[num<<1|1]=sign[num<<1|1]+sign[num];
		sum[num<<1]=sum[num<<1]+sign[num]*lef_amount;
		sum[num<<1|1]=sum[num<<1|1]+sign[num]*righ_amount;
		sign[num]=0;
	}
	
}
//区间修改函数
void segment_tree::region_change(int change_lef,int change_righ,int addend,int lef,int righ,int num){
	if(change_lef<=lef&&righ<=change_righ){
		sum[num]=sum[num]+addend*(righ-lef+1);
		sign[num]=sign[num]+addend;
		return;
	}
	int middle=(lef+righ)>>1;
	pushdown(num,middle-lef+1,righ-middle);
	if(change_lef<=middle){
		region_change(change_lef,change_righ,addend,lef,middle,num<<1);
	}
	if(change_righ>middle){
		region_change(change_lef,change_righ,addend,middle+1,righ,num<<1|1);
	}
	update(num);
}
//区间查询函数
int segment_tree::query(int search_lef,int search_righ,int lef,int righ,int num){
	if(search_lef<=lef&&righ<=search_righ){
		return sum[num];
	}
	int middle=(lef+righ)>>1;
	pushdown(num,middle-lef+1,righ-middle);
	int ans=0;
	if(search_lef<=middle){
		ans=ans+query(search_lef,search_righ,lef,middle,num<<1);
	}
	if(search_righ>middle){
		ans=ans+query(search_lef,search_righ,middle+1,righ,num<<1|1);
	}
	return ans;
}
int main(){
	int given_array[100007]={1};
	int given_n;
	scanf("%d",&given_n);
	segment_tree my_segment_tree(given_array,given_n);
	my_segment_tree.build(1,given_n,1);
	return 0;
}