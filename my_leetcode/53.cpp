//一个很关键的认识   一定要和别人讨论   但是现在现实中没人讨论
//但是网络搜索这个题,就会发现别人的思路   看别人的思路也算是略微的思想交流吧
//这时候leetcode的巨大优势就发挥出来了   

//神奇   卡耐基梅隆大学的Jay Kadane
//这里即使最终结果是负数也可以解决
//(如果最终结果是负数,说明每个元素都是负数,那么只需要找出那个最大的负数就好了)

//看了那个博主的代码和评论区,莫名又有了自信
// 9 MS   57.56%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int length = nums.size();
		long long int sum = 0;
		long long int max_sum = -10000000000000;
		for(int i = 0; i<length; ++i){
			sum += nums[i];
			if(sum>max_sum){
				max_sum = sum;
			}
			if(sum<=0){
				sum = 0;
			}
		}
		return max_sum;
    }
};


/*
//这个题寒假的时候计蒜客做过,叫做最大子阵列  当时就用的这个复杂度为N^2的思路
//昨天搜索看别人怎么做的时候,发现复杂度为N^2,N^3的都算是暴力破解了
//别人还有复杂度为N(logN)的和N的;
//这个复杂度为N^2,最后一组数据没通过
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int length = nums.size();
		if(length == 0){
			return 0;
		}
		if(length == 1){
			return nums[0];
		}
		int sum = 0;
		int max_sum = -100000000;
        int* sum_array = new int[length+10];
		for(int i = 0; i<length; ++i){
			sum += nums[i];
			sum_array[i] = sum;
			if(sum>max_sum){
				max_sum = sum;
			}
		}
		for(int i = 0; i<length-1; ++i){
			for(int j = i+1; j<length; ++j){
				if(sum_array[j] - sum_array[i]>max_sum){
					max_sum = sum_array[j] - sum_array[i];
				}
			}
		}
		return max_sum;
    }
};
*/