class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
		
		nums.push_back(0);
		
		int result = 0;
		int temp = 0;
		for(int i=0;i<nums.size();++i){
			if(nums[i]==1){
				++temp;
			}else{
				if(temp>result){
					result = temp;
				}
				temp = 0;
			}
		}
		return result;
    }
};