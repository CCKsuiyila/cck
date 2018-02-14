class Solution {
public:
    int dominantIndex(vector<int>& nums) {
		int index = 0;
        for(int i=0;i<nums.size();++i){
			if(nums[i]>nums[index]){
				index = i;
			}
		}
		for(int i=0;i<nums.size();++i){
			if(i==index){
				continue;
			}
			if(nums[i]*2>nums[index]){
				return -1;
			}
		}
		return index;
    }
};