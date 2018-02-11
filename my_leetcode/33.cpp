//对 回忆一下自己的做题思路(最近每做一题就把这个粘过去)
//1.先理解题
//2.确定解题思路(选择数据结构算法什么的)   确定能解决正常情况,也不用考虑太多复杂度
//3.2达到之后, 开始考虑各种解决可能遇到的奇怪情况   然后看看有没有复杂度更低的思路

//隔了好久又开始,  写之前有个正常情况的思路,没有考虑特殊情况    然后就出错了再改   马马虎虎过了
// 50.65%   6 ms
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

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int size=nums.size();
		if(size==0){
			return -1;
		}
		if(size==1){
			if(nums[0]==target){
				return 0;
			}else{
				return -1;
			}
		}
		//sort
        int the_end = 0;
		Use_for_quicksort* sorted_array = new Use_for_quicksort[size+10];
		for(;nums[the_end]<nums[the_end+1];++the_end);//不考虑没有旋转的情况
		int i=0;
		for(int j=the_end+1;j<size;++i,++j){
			sorted_array[i].compare=nums[j];
			sorted_array[i].store_one=j;
		}
		for(int j=0;j<the_end+1;++i,++j){
			sorted_array[i].compare=nums[j];
			sorted_array[i].store_one=j;
		}
		//find_target
		int result=binary_search(sorted_array, 0, size, target);
		if(result==-1){
			return -1;
		}else{
			return sorted_array[result].store_one;
		}	
    }
};