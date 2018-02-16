//array  easy部分不付费的最后一道   感觉很有纪念意义    2018/2/16  周五  大年初一   晚8:23分
//这是从最开始的方法改出来的
//过是过了  但是我感觉我没有掌握这道题的本质     目前只能说看出了点规律      [3,4,2,3]    这道题还待思考
//37 ms    51.30 %
class Solution {      
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
		for(int i=0;count<=1&&i<nums.size()-1;++i){
			if(nums[i]>nums[i+1]){
				if((i-1>=0&&nums[i+1]<nums[i-1])&&(i+2<nums.size()&&nums[i+2]<nums[i])){
					return false;
				}
				++count;
			}
		}
		if(count>1){
			return false;
		}else{
			return true;
		}
    }
};

/*
//这次一步到位吧      [4,2,3]   这个题有意思
//
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
		
		if(nums.size()<3){
			return true;
		}
		
		int count = 0;
		int current_max = nums[0];
		for(int i=1;count<=1&&i<nums.size();++i){
			if(nums[i]<current_max){
				++count;
			}else{
				current_max = nums[i];
			}
		}
		if(count>1){
			return false;
		}else{
			return true;
		}
    }
};
*/

/*
//一眼看上去又是很简单  [3,4,2,3] 第一次在这里出错(第311组数据)   有点意思
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
		for(int i=0;i<nums.size()-1;++i){
			if(nums[i]>nums[i+1]){
				++count;
			}
		}
		if(count>1){
			return false;
		}else{
			return true;
		}
    }
};
*/