//这个题和上一道神似   感觉没多大问题   就在纸上画了下思路后直接上手敲了
//刚开始的思路估计有各种乱七八糟的问题(就是原来没有第一个for循环确定length)
//然后突然想到  先来一遍遍历确定length复杂度也加不到哪吗    然后正确简洁的思路就来了   挡也挡不住
//还不知道他只算到length之前,然后又想试试STL,然后搜了个vector.clear()用了用    后来发现不用这东西   还提速了    
//总体来说,这题难度较低吧   但还是应该提前花点时间想想思路,争取花时间最少.    记住3sum(上午到下午你,然后晚上钟奇龙学长,很深刻的教训)

//6 ms   14.52%
//3 ms    68.98%    这个是注释掉nums.clear();之后   果然猜对了   他只算到length之前
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
		int j=0;
		int length = size;
		for(int i = 0;i<size;++i){
			if(nums[i]==val){
				length -= 1;
			}
		}
		if(legnth==0){
			//nums.clear();
			return length;
		}
		for(int i=size-1;i>=length;--i){
			if(nums[i]!=val){
				for(;nums[j]!=val;++j){}
				nums[j]=nums[i];
				++j;
			}
		}
		return length;
    }
};