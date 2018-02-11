//对 回忆一下自己的做题思路(最近每做一题就把这个粘过去)
//1.先理解题
//2.确定解题思路(选择数据结构算法什么的)   确定能解决正常情况,也不用考虑太多复杂度
//3.2达到之后, 开始考虑各种解决可能遇到的奇怪情况   然后看看有没有复杂度更低的思路

//很快就有思路了,很快就写出来了   然后有问题   被卡了半天  发现是==写成了=   尴尬   
// 5.11%   18 ms
class Use_for_quicksort{
	public:
		int compare;
		int store_one;
};

//二分查找
int binary_search(Use_for_quicksort *data,int low,int high
,int be_searched){
	
	for(;low<high;){
		int middle=(low+high)>>1;
		if(be_searched<data[middle].compare){
			high=middle;
		}
		else if(be_searched>data[middle].compare){
			low=middle+1;
		}
		else{
			for(;be_searched==data[middle].compare;middle=middle-1);
			middle=middle+1;
			return middle;
		}
	}
	return -1;
}

class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		int size=nums.size();
        Use_for_quicksort* sorted_array = new Use_for_quicksort[size+10];
		for(int i=0;i<size;++i){
			sorted_array[i].compare=nums[i];
		}
		int my_begin=binary_search(sorted_array, 0, size, target);
		int my_end=my_begin;
		if(my_begin==-1){
			vector<int> result;
			result.push_back(my_begin);
			result.push_back(my_end);
			return result;
		}else{
			for(;sorted_array[my_end].compare==target;++my_end);  //就是这里
			--my_end;
			vector<int> result;
			result.push_back(my_begin);
			result.push_back(my_end);
			
			return result;
		}
    }
};