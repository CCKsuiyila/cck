//看了这道题,感觉很熟悉,清华题仿佛有类似的,然后又和数据结构那个求二叉树的深度有些神似
//反正都是递归  递归嘛,虽然效率低,但是好些然后飞快就写出来了
//(先在纸上较为杂乱的写了初步的代码,然后敲到电脑上)  
//然后加了一些处理特殊情况的if  然后就  71 / 92 test cases passed   
//Time Limit Exceeded  [5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5]

//然后看看如何提高效率吧   看了一遍代码就想出来了(类似贪心算法吧,减少递归)  试试吧
//然后这次没在纸上写了,直接在低效版本上面改出来的,稍微花了点时间,也不多
//不过发现   一旦改代码,总是没底   

//做Jump Game 后修改一些小细节

// 13 MS   49.29%
class Solution {
public:
	int numToEnd(vector<int>&nums,int index){
		int compare=0;
		int store;
		int i=0,j=index+1;
		for(;i<nums[index];++i,++j){
			if(j==nums.size()-1){
				return 1;    //这里return 0 改成return 1  更好理解了
			}
			if(i+nums[j]>=compare){
				store=j;
				compare=i+nums[j];
			}
		}
		return numToEnd(nums,store)+1;
	}
    int jump(vector<int>& nums) {
		if(nums.size()==1){
			return 0;
		}
		/*
		if(nums.size()==2){
			return 1;
		}*/                          //这个不需要的
        return numToEnd(nums, 0);    //上面改了这里就不需要+1了
    }
};



//低效版
/*
class Solution {
public:
	int numToEnd(vector<int>&nums,int index){
		int compare=10000000;
		for(int i=0,j=index+1;i<nums[index];++i,++j){
			if(j==nums.size()-1){
				return 0;
			}
			int temp = numToEnd(nums,j);
			if(temp<compare){
				compare=temp;
			}
		}
		return compare+1;
	}
    int jump(vector<int>& nums) {
		if(nums.size()==1){
			return 0;
		}
		if(nums.size()==2){
			return 1;
		}
        return numToEnd(nums, 0);
    }
};
*/