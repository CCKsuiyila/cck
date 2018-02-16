//感觉一次遍历就好了
//182 ms    54.46 %
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
		int current_max = 0;
		for(int i=0;i<k;++i){
			current_max += nums[i];
		}
		double result = current_max;
		
		for(int i=0,j=k;j<nums.size();++i,++j){
			current_max = current_max + nums[j] - nums[i];     //就这个k和j搞混了   浪费多少时间     虽然知道出了问题肯定是自己的问题   但是还是调试了一下   下次不要偷懒   自己看代码
			if(current_max>result){
				result = current_max;
			}
		}
		
		result /= k;
		return result;
    }
};