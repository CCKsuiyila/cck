class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left_sum;
		left_sum.push_back(0);
		for(int i=1;i<nums.size();++i){
			left_sum.push_back(nums[i-1]+left_sum[i-1]);
		}
		
		vector<int> right_sum;
		right_sum.push_back(0);
		for(int i=nums.size()-2,j=0;i>=0;--i,++j){
			right_sum.push_back(nums[i+1]+right_sum[j]);
		}
		
		for(int i=0,j=nums.size()-1;i<j;++i,--j){
			int temp = right_sum[i];
			right_sum[i] = right_sum[j];
			right_sum[j] = temp;
		}
		
		for(int i=0;i<nums.size();++i){
			if(left_sum[i]==right_sum[i]){
				return i;
			}
		}
		
		return -1;
    }
};

