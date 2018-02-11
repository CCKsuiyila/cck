//感觉很简单的样子   直接上手敲吧
//确实是挺简单的   不过直接上手敲,犯了好多小错误  浪费了一点时间
// 3MS    26.67%
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0;
		int white = 0;
		int blue = 0;
		for(int i = 0; i < nums.size();++i){
			if(nums[i]==0){
				++red;
			}else if(nums[i]==1){
				++white;
			}else{
				++blue;
			}
		}
		int index = 0;
		for(int i = 0; i < red ;++i){     //就是这里   刚开始没用i  后来i < red的i用的是index
			nums[index]=0;
			++index;
		}
		for(int i = 0; i < white ;++i){    //
			nums[index]=1;
			++index;
		}
		for(int i = 0; i < blue ;++i){    //
			nums[index]=2;
			++index;
		}
		return;
    }
};