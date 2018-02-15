//2果然是超时了   肯定还能更加优化
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
		
		//1这种输入真是没考虑到
		if(nums.size()==0){
			return nums;
		}
		
		int temp = nums[0]-1;
		
        for(int i=0,j=0;i<nums.size();++i){
			if(nums[temp]==0){
				for(;j<nums.size();++j){
					if(nums[nums[j]-1]!=0){
						temp = nums[j]-1;
						++j;      
						break;         //4之前每次j都从零开始，这次记住上一次停下的地方，节约时间。然后之前没有break，每次都全部遍历一遍，这次有了break
					}
				}
			}
			int temp2 = nums[temp]-1;
			nums[temp] = 0;
			temp = temp2;
		}
		
		vector<int> result;
		for(int i=0;i<nums.size();++i){
			if(nums[i]!=0){
				result.push_back(i+1);
			}
		}
		
		return result;
    }
};