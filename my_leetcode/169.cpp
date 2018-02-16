//这题啥都不告诉
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
		int result = nums[0];
		int count_result = 1;
		for(int i=1;i<nums.size();++i){
			if(nums[i]==result){
				++count_result;
			}else{
				if(count_result*2>nums.size()){
					return result;
				}else{
					result = nums[i];
					count_result = 1;
				}
			}
		}
		
		return result;
    }
};