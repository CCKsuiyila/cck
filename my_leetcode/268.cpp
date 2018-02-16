//来个时间空间都考虑的   25ms
class Solution {
public:
    int missingNumber(vector<int>& nums) {
		
		nums.push_back(-2);
		
		for(int i=0;i<nums.size()-1;++i){
			for(int j=nums[i];j>=0&&j<nums.size();){
				int temp = nums[j];         // 这里多了一层nums[nums[j]]     结果指针错误了,浪费半天时间才找出来     下次注意
				nums[j] = -1;
				j = temp;
			}
		}
		
		for(int i=0;i<nums.size();++i){
			if(nums[i]!=-1){
				return i;
			}
		}
    }
};


/*
//其实这种类型 hash省时间    先不管空间复杂度   23ms   不是吧  这样时间上也才超过  47.03 %的人?   这还是运行还几遍的最佳结果
class Solution {
public:
    int missingNumber(vector<int>& nums) {
		
		int save[nums.size()+1] = {0};
        
		for(int i=0;i<nums.size();++i){
			save[nums[i]] = 100;
		}
		
		for(int i=0;i<nums.size()+1;++i){
			if(save[i]!=100){
				return i;
			}
		}
    }
};
*/

/*
//无脑版   排序+遍历一遍  省空间了,不过时间有点慢 34ms
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
		for(int i=0;i<nums.size();++i){
			if(nums[i]!=i){
				return i;
			}
		}
		
		return nums.size();
    }
};
*/