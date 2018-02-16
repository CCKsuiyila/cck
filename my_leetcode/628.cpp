//最佳的方案
//第一次  49ms  这个OJ真是有毒   第二次47ms  第三次50    算了算了   知道这个好就行
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
		int min1 = 1000,min2 = 1000,max1 = -1000,max2 = -1000,max3 = -1000;
		for(int i=0;i<nums.size();++i){
			if(nums[i]<min1){
				min2 = min1;
				min1 = nums[i];
			}else if(nums[i]<min2){
				min2 = nums[i];
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
	
		int result = max1*max2*max3;
		if(min1*min2*max1>result){
			result = min1*min2*max1;
		}
		
		return result;
    }
};


/*
//只需找出min1,min2   max1,max2,max3   然后比较两种情况   这样是不需要排序的,只需要遍历两遍     
//然后看一遍最佳答案   发现人家就遍历了一遍    再改改
//47ms
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
		int min1 = 1000,min2 = 1000,max1 = -1000,max2 = -1000,max3 = -1000;
		for(int i=0;i<nums.size();++i){
			if(nums[i]<min2){
				if(nums[i]<min1){
					min2 = min1;
					min1 = nums[i];
					continue;
				}
				min2 = nums[i];
			}
		}
		
		for(int i=0;i<nums.size();++i){
			if(nums[i]>max3){
				if(nums[i]>max2){
					if(nums[i]>max1){
						max3 = max2;
						max2 = max1;
						max1 = nums[i];
						continue;
					}
					max3 = max2;
					max2 = nums[i];
					continue;
				}
				max3 = nums[i];
			}
		}
        
		int result = max1*max2*max3;
		if(min1*min2*max1>result){
			result = min1*min2*max1;
		}
		
		return result;
    }
};
*/

/*
//确实一眼看上去   排个序  比较下两种情况哪个更大是一般人都能想到的方法    但是看了别人更好的思路,确实发现是自己太懒了
//70ms
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
		int result = nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
		if(nums[0]*nums[1]*nums[nums.size()-1]>result){
			result = nums[0]*nums[1]*nums[nums.size()-1];
		}
		
		return result;
    }
};
*/