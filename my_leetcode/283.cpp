//加个速     结果效果不是很明显
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int count_zero = 0;
		for(int i=0;i<nums.size();++i){
			if(nums[i]==0){
				++count_zero;
			}
		}
        for(int i=0;i<nums.size()-count_zero;++i){
			if(nums[i]==0){
				for(int j=i;j<nums.size();++j){
					if(nums[j]!=0){
						nums[i]=nums[j];
						nums[j]=0;
						break;
					}
				}
			}
		}
    }
};


/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
			if(nums[i]==0){
				for(int j=i;j<nums.size();++j){
					if(nums[j]!=0){
						nums[i]=nums[j];
						nums[j]=0;
						break;
					}
				}
			}
		}
    }
};
*/