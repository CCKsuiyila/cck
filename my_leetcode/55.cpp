//交流的过程中发现有迭代版   自己先改一改试一试
//虽然没有和别人的那样  又有全局又有局部,但是也听过了
//这次突然有了点想法    根据复杂度来判断要遍历几遍

//然后2那个需要记录跳几次的也可以用循环    迟点改吧
//  9 ms   93.70%
class Solution {
public:
    bool canJump(vector<int>& nums) {
		if(nums.size()<=1){
			return true;
		}
        int current = 0;
		int i = 0;
		for(;i<=current;++i){
			if(nums[i]+i>current){
				current =nums[i]+i;
				if(current>=nums.size()-1){
					return true;
				}
			}
		}
		return false;
    }
};

/*
//这个直接从Jump Game||改过来了   同时修改了一些小细节
//小细节在下面
// 12 ms 62.89% 
class Solution {
public:
	int numToEnd(vector<int>&nums,int index, int& sign){
		int compare=0;
		int store;
		int i=0,j=index+1;
		if(0==nums[index]){
			return 1;
		}
		for(;i<nums[index];++i,++j){
			if(j==nums.size()-1){
				sign = 9;
				return 1;       //这里把return 0 改成了return 0;  这样就更好理解了
			}
			if(i+nums[j]>=compare){
				store=j;
				compare=i+nums[j];
			}
		}
		return numToEnd(nums,store,sign)+1;
	}
	
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
			return true;
		}
		int sign = 6;
		numToEnd(nums,0,sign);
		if(sign==6){
			return false;
		}else{
			return true;
		}
    }
};
*/