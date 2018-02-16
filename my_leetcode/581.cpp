//一眼看上去感觉很简单,试试          做完发现果然很简单.    刚开始还考虑了一下动态规划来着    还好没朝着动态规划做下去
// 50 ms    28.04 %
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
		if(nums.size()==0){
			return 0;
		}
		
		vector<int> sorted = nums;
		sort(sorted.begin(),sorted.end());
		int low=0;
		while(low<nums.size()&&nums[low]==sorted[low]){
			++low;
		}
		
		if(low==nums.size()){        //忘记考虑这种情况了
			return 0;
		}
		
		int high = nums.size()-1;
		while(nums[high]==sorted[high]){
			--high;
		}
		
		return high-low+1;
		
    }
};