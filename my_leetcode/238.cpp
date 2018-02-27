//这题一眼看上去也没有什么问题   
// 53 ms   28.56 %

//以为没有0的  结果有  有就有吧   分类讨论就好
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		
		int zero_sign = 0;   //表示0的个数
		
		int multiply_all = 1;
        for(int i=0;i<nums.size();++i){
			if(nums[i]!=0){
				multiply_all *= nums[i];
			}else{
				++zero_sign;
			}
		}
		
		vector<int> result;
		if(zero_sign>1){
			for(int i=0;i<nums.size();++i){
				result.push_back(0);
			}	
		}else if(zero_sign==1){
			for(int i=0;i<nums.size();++i){
				if(nums[i]!=0){
					result.push_back(0);
				}else{
					result.push_back(multiply_all);
				}
			}			
		}else{
			for(int i=0;i<nums.size();++i){
				result.push_back(multiply_all/nums[i]);
			}	
		}
		
		
		return result;
    }
};