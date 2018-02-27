//这个题的描述倒是挺复杂的    然后感觉看完描述和样例对不上   先根据理解写吧  
// 果然样例那个 output  6就是误导人    应该是4的
//有个题有点像昨天那个hash   不过简单多了
//33 ms    62.50 %            30 ms    100.00 %    哇  同样的代码,加了点注释   第二次直接100%了    可以的
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
		int result = 0;
        int max = nums.size();
		int count = 0;
		for(int i=0;i<nums.size();++i){
			if(nums[i]<max){
				++count;
				int temp = nums[i];
				nums[i] = max;
				while(nums[temp]<max){
					++count;
					int temp2 = nums[temp];          //这里必须有个temp2   刚开始没这行   样例输出是2不是4就是这里的问题
					nums[temp] = max;
					temp = temp2;
				}
				if(count>result){
					result = count;
				}
				count = 0;
			}
		}
		
		return result;
    }
};