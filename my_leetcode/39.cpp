//连个朴素算法都么想,就开始在网上搜了    结果发现是个回溯法    
//看了看别人的算法  大概知道回溯法是个啥了   然后发现自己以前隐约用过
//然后发现  别人的算法有个重复的地方   然后就给他改了改   果然  时间减少一半

//这大概就是学长说要借鉴别人的算法的原因吧     如果闭门造车  估计要卡死在这道题上了  
//清华的题卡住不前   大概有一部分原因就是清华的题不好找答案


//根据别人的做了些优化     83%   12MS
class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<int> tmp;
		sort(candidates.begin(),candidates.end()); //先对C中候选数升序排序，为后面的剪枝做准备
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
		if(l==sou.size()) //搜索到叶节点
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
				int temp=dfs(tmp,tag,i);
				tmp.pop_back(); //回溯，恢复tmp状态
				if(temp==1){
					return 0;
				}
			}
		}
		return 0;
	}
};



/*
//别人的(未修改)     30%    22MS
class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<int> tmp;
		sort(candidates.begin(),candidates.end()); //先对C中候选数升序排序，为后面的剪枝做准备
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
	void dfs(vector<int> &tmp,int tag,int l){
		if(l==sou.size()) //搜索到叶节点
			return ;
		int tot=sum(tmp);
		if(tot==tag){
			res.push_back(tmp);
			return ;
		}else if(tot>tag)  //剪枝
			return ;
		else{
			for(int i=l;i!=sou.size();++i){ //因为C中每个数可以选多次，所以i从l开始，而不是l+1
				tmp.push_back(sou[i]);
				dfs(tmp,tag,i);
				tmp.pop_back(); //回溯，恢复tmp状态
			}
		}
	}
};
*/