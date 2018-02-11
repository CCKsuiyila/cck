//对 回忆一下自己的做题思路(最近每做一题就把这个粘过去)
//1.先理解题
//2.确定解题思路(选择数据结构算法什么的)   确定能解决正常情况,也不用考虑太多复杂度
//3.2达到之后, 开始考虑各种解决可能遇到的奇怪情况   然后看看有没有复杂度更低的思路

//这个思路很简单   就是改变一下二分查找,能够解决找不到的情况   但是在这个过程中发现了一个小瑕疵   改了就好了
//46.58%    6 ms
class Use_for_quicksort{
	public:
		int compare;
		int store_one;
};

//二分查找
int binary_search(Use_for_quicksort *data,int low,int high
,int be_searched){
	int high_sign = high;
	for(;low<high;){
		int middle=(low+high)>>1;
		if(be_searched<data[middle].compare){
			high=middle;
		}
		else if(be_searched>data[middle].compare){
			low=middle+1;
		}
		else{
			return middle;
		}
	}
	if(low==high_sign){       //就是这里
		return high_sign;
	}else{
		if(be_searched<data[low].compare){
			return low;
		}else{
			return low+1;
		}
	}
}

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size=nums.size();
        Use_for_quicksort* sorted_array = new Use_for_quicksort[size+10];
		for(int i=0;i<size;++i){
			sorted_array[i].compare=nums[i];
		}
		int result=binary_search(sorted_array, 0, size, target);
		return result;
    }
};
