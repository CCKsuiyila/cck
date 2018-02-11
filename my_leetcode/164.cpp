//这个题首先如果排序的话,肯定达不到线性时间,   所以应该有什么神奇的方法
//但是暂时想不出,所以先试试自己的朴素算法(不考虑超时的问题)

//但是很神奇,竟然一遍accept了    明明用了quicksort,这还是线性时间吗
//难道这个题是要考计数排序,但是这样的话需要额外空间啊     交流一下吧
//结果发现是要用桶排序   而且他要求是线性时间,空间复杂度   这样的话话其实计数排序也存在可能性
//但是这种脑残题已然是什么都不说清楚,难道让我们自己去试吗?  

//现在通过了就懒得试桶排序了   下次吧
//尴尬,突然发现题目还是有很多暗示的(非负整数,int型,线性时间空间)    是自己太脑残了
//但是他为啥非得让我过呢     不让我过不就完美了

//
// 6MS  76.14%
int quicksort(vector<int>& data,int low,int high){
	int partition(vector<int>& data,int low,int high);
	if ((high-low)<1){
		return 0;
	}
	
	int middle=partition(data,low,high-1);
	quicksort(data,low,middle);
	quicksort(data,middle+1,high);
	return 0;
}

int partition(vector<int>& data,int low,int high){
	int backup_low=low;
	int backup_high=high;
	int middle_data=data[low];
	for(;low<high;){
		for(;low<high;){
			if(data[high]>middle_data){
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(data[low]<middle_data){
				low=low+1;
			}else{
				data[high]=data[low];
				high=high-1;
				break;
			}
		}
	}
	int middle=low;
	data[low]=middle_data;
	low=backup_low;
	high=backup_high;
	return middle;
}

class Solution {
public:
    int maximumGap(vector<int>& nums) {
		if(nums.size()<2){
			return 0;
		}
        quicksort(nums,0,nums.size());
		int result = 0;
		for(int i =0; i<nums.size()-1; ++i){
			if(abs(nums[i+1]-nums[i])>result){
				result = abs(nums[i+1]-nums[i]);
			}
		}
		return result;
    }
};