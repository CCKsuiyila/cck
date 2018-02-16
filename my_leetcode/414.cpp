//这题怎么感觉上午才做过    而且还是比这还复杂的
//7 ms    47.95 %    还好这题有个难点    不然......
class Solution {
public:
    int thirdMax(vector<int>& nums) {
		
        long long int max1 = -2147483649,max2 = -2147483649,max3 = -2147483649;     //-2147483648  64位系统int能表示的最小值...  原来难点在这  第23组的数据就是有这个值
		for(int i=0;i<nums.size();++i){
			if(nums[i]==max1||nums[i]==max2||nums[i]==max3){
				continue;
			}
			
			if(nums[i]>max1){
				max3 = max2;
				max2 = max1;
				max1 = nums[i];
			}else if(nums[i]>max2){
				max3 = max2;
				max2 = nums[i];
			}else if(nums[i]>max3){
				max3 = nums[i];
			}
		}
		
		if(max3!=-2147483649){
			return max3;
		}else{
			return max1;
		}
    }
};