class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		
		//special case   i forget it
		if(nums.size()==0||nums.size()==1){
			return false;
		}
		
        sort(nums.begin(),nums.end());
		for(int i=0;i<nums.size()-1;++i){
			if(nums[i]==nums[i+1]){
				return true;
			}
		}
		
		return false;
    }
};