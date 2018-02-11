//一眼看见n的复杂度,就有直觉是hash,看了看标签array,略懵.还是hard.
//不过直接按照hash做了   然后一下过去了
//6 ms  16.14%
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int* hash = new int[1000000];
		int size = nums.size();
		for(int i=0;i!=size;++i){
			if(nums[i]>0){
				hash[nums[i]]=nums[i];
			}
		}
		int result = 1;
		for(;hash[result]==result;++result);
		return result;
    }
};