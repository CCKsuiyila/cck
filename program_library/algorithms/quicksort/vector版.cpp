//对 回忆一下自己的做题思路(最近每做一题就把这个粘过去)
//1. 先理解题
//2. 确定解题思路(选择数据结构算法什么的)   确定能解决正常情况,也不用考虑太多复杂度
//3. 2达到之后, 开始考虑各种解决可能遇到的奇怪情况   然后看看有没有复杂度更低的思路

//这题挺难懂的     先随意试试吧
//讲真  这题思路自己没问题了,昨天就没问题了    
//可是被那个什么申请内存错误,释放内存错误给卡住了   换了STL的swap才行    目前还不知道是啥原因
//就这样吧   被浪费了一点时间    还能接受   这题过   不过将来thu的toy估计需要借鉴这道题
//其实这题的有相同的数时不复杂,这就降低了难度
//这个题的quicksort是改过的可以给vector用的    以后需要可以回来找

//这题还有不懂的地方呢    没办法了



//12 ms     61.48% 
//quicksort algotithm
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

#include<algorithm>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size == 2){
			swap(nums[0],nums[1]);
        }
        if(size!=0&&size!=1&&size!=2){
            int i=size-1;
		    for( ;i>0&&nums[i]<=nums[i-1];--i){}
			
		    if(i==0){
			    quicksort(nums,0,size);
		    }else if(i==size-1){
		        swap(nums[i],nums[i-1]);
		    }else if(i>0&&i<size-1){
		        //这的cout<<i;可以删
				quicksort(nums,i,size);
				int k=i-1;
				for(;nums[k]>=nums[i];++i)
				cout<<i;//这的不能删    还不知道是啥原因
				swap(nums[k],nums[i]);
			}
        }
		
    }
};