//对 回忆一下自己的做题思路(最近每做一题就把这个粘过去)
//1.先理解题
//2.确定解题思路(选择数据结构算法什么的)   确定能解决正常情况,也不用考虑太多复杂度
//3.2达到之后, 开始考虑各种解决可能遇到的奇怪情况   然后看看有没有复杂度更低的思路

//直接从39改编了
// 9 ms  63.86%
//大概花了将近2个小时才把这里改好    不提前把思路想好真是可怕  浪费时间   并且现在还不敢说没问题了
//那个hash花了好久,却毫无成果,看来需要花时间深入学习一下hash了   
//但是后来发现完全不需要通过hash     跳出了这个怪圈

class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		vector<int> tmp;
		sort(candidates.begin(),candidates.end()); //先对C中候选数升序排序，为后面的剪枝做准备
		for(int i=0;i!=candidates.size();++i){
			cout<<candidates[i];
		}
		sou=candidates;
		dfs(tmp,target,0);
		return res;
	}
private:
	vector<vector<int> > res;  //保存最后结果
	vector<int> sou;  
	int sum(vector<int> tmp){ //计算累加和
		int r=0;
		for(int i=0;i!=tmp.size();++i)
			r+=tmp[i];
		return r;
	}
	int dfs(vector<int> &tmp,int tag,int l){
		if(l==sou.size()+1) //搜索到叶节点
			return 0;
		int tot=sum(tmp);
		if(tot==tag){
			res.push_back(tmp);
			return 1;
		}else if(tot>tag)  //剪枝
			return 1;
		else{
			for(int i=l;i!=sou.size();++i){ //因为C中每个数可以选多次，所以i从l开始，而不是l+1
				tmp.push_back(sou[i]);
				int temp=dfs(tmp,tag,i+1);
				tmp.pop_back(); //回溯，恢复tmp状态
				if(temp==1){
					return 0;
				}
				for(;i!=sou.size()-1&&sou[i]==sou[i+1];++i);
				
			}
		}
		return 0;
	}
};