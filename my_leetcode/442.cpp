//看讨论区   找到一个感觉很厉害的  98%
//128 ms     84.62 %   测了好多次   最高就是前面    最低16%   这个系统无敌了
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
		nums.push_back(nums.size()+1);
        for(int i = 0; i < nums.size()-1;++i){
            nums[abs(nums[i])] = -nums[abs(nums[i])];
            if(nums[abs(nums[i])] > 0){
				result.push_back(abs(nums [i]));
			}
        }
        return result;
    }
};


/*
//10000表示这个值取了但是这个位置没数   9999表示这个值取了位置也有数了

//这个题  改了一上午一下午   没改好,    晚上重新思考了一遍然后重新写就好了   但是这个题他的答案顺序非得要求和他的顺序一样,简直无话可说,他的标准答案又不是排序过的
//相比之下,你的不是一个接一个遍历过来的   你的是跳来跳去的   对比之下看出了差距
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.size()==0){
			return nums;
		}
		
		nums.push_back(10000);
		
		vector<int> result;
		int temp = nums[0];
		nums[0] = 10000;
		int j = 1;
		
		while(j<nums.size()){
			if(nums[temp]==9999){
				result.push_back(temp);
				while(nums[j]==10000||nums[j]==9999){
					++j;
				}
				temp = nums[j];
				nums[j] = 10000;
			}else if(nums[temp]==10000){
				nums[temp] = 9999;
				while(nums[j]==10000||nums[j]==9999){
					++j;
				}
				temp = nums[j];
				nums[j] = 10000;
			}else{
				int temp2 = nums[temp];
				nums[temp] = 9999;
				temp = temp2;
			}
		}
		
		return result;
    }
};
*/