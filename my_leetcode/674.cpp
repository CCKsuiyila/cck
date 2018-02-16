//17ms 超过18.62 %的人    就遍历了一遍,没有额外空间      感觉可以了吧  
//同样的代码  再来一遍15 ms    超过54.22 %的人  
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
		
		if(nums.size()==0){
			return 0;
		}
		
        int result = 1;
		int start = 0;
		int i;
		for(i=1;i<nums.size();++i){
			if(nums[i]<=nums[i-1]){
				if(i-start>result){
					result = i-start;
				}
				start = i;
			}
		}
		
		if(i-start>result){   //这个再来一遍就好了
			result = i-start;
		}
			
		return result;
    }
};


/*
//没有考虑特殊情况:全部递增上去
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
		
		if(nums.size()==0){
			return 0;
		}
		
        int result = 1;
		int start = 0;
		for(int i=1;i<nums.size();++i){
			if(nums[i]<=nums[i-1]){
				if(i-start>result){
					result = i-start;
				}
				start = i;
			}
		}
		
		return result;
    }
};
*/