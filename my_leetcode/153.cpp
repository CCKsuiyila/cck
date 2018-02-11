//就想找一道简单的凑购array的20道题   然后选中了这道
//果然直接想出思路,然后电脑上敲,然后accept了  不超过10分钟吧   
//而且只有一个漏掉的分号的语法错误    牛逼
// 3MS   36.74%
class Solution {
public:
    int findMin(vector<int>& nums) {
		if(nums.size()==1){
			return nums[0];
		}
		int i = 1;
        for(;i<nums.size()&&nums[i]>nums[i-1];++i);
		if(i==nums.size()){
			return nums[0];
		}else{
			return nums[i];
		}
		
    }
};