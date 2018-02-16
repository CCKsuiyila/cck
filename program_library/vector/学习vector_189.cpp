//学习一下vector吧
// 20ms    41.46 %
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		
		int temp = -k;
        while(temp<0||temp>=nums.size()){    //这里暂时不知道怎么优化   但是感觉肯定有优化的办法
			temp += nums.size();
		}
		
		vector<int> result;              //速度并没有提高.....   不过了解了更多的vector操作,以及迭代器
		
		auto it=nums.begin()+temp;
		
		result.assign(it,nums.end());
		result.insert(result.end(),nums.begin(),it);
		
		nums = result;
    }
};

/*
//这种看起来啥要求都没有的题真的让我有点慌   先考虑k只为正数吧
// 19 ms   41.46 %
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		
		int temp = -k;
        while(temp<0||temp>=nums.size()){
			temp += nums.size();
		}
		
		vector<int> result;
		for(int i=temp;i<nums.size();++i){
			result.push_back(nums[i]);
		}
		for(int i=0;i<temp;++i){
			result.push_back(nums[i]);
		}
		
		nums = result;
    }
};
*/