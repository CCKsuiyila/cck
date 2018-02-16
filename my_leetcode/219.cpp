//最后看了一眼答案   别人仿佛用了set这个数据结构     测试一下    27 ms    哈哈哈    不过以后有空学习下这个数据结构

//归并排序版
// 26 ms    49.41 %
//做题过程种慢慢建立自己的函数库就是爽    这次就是例子   很快就改好了     时间复杂度也还可以接受     以后优化的时候再加速
//还有理论知识真的有用   比如说这次的快速排序的不稳定,归并排序的稳定     秒想出来    我要好好学习
class Use_for_quicksort{
	public:
		int compare;
		int store_one;
};

//mergesort algotithm
int mergesort(Use_for_quicksort *data,int low,int high){
	int merge(int low,int middle,int high,Use_for_quicksort *data);
	if(high-low<1){
		return 0;
	}
	int middle=(low+high)/2;
	mergesort(data,low,middle);
	mergesort(data,middle+1,high);
	merge(low,middle,high,data);
	return 0;
}

int merge(int low,int middle,int high,Use_for_quicksort *data){
	int i = low;
	int j = middle + 1;
	int k = 0;
	Use_for_quicksort* temp = new Use_for_quicksort[high - low + 10];
	while(i <= middle && j <= high){
		if(data[i].compare <= data[j].compare){
			temp[k++] = data[i++];
		}else{
			temp[k++] = data[j++];
			//count = count + middle + 1 - i;    这行是原来求逆序数用的  count是全局变量  怪不得学长说尽量不用全局变量   复用性有点差
		}
	}
	while(i <= middle){
		temp[k++] = data[i++];
	}
	while(j <= high){
		temp[k++] = data[j++];
	}
	for(i = low, k = 0; i <= high;){
		data[i++] = temp[k++];
	}
	delete []temp;
	return 0;
}

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		
		if(nums.size()==0||nums.size()==1){
			return false;
		}
		
        Use_for_quicksort save[nums.size()];
		for(int i=0;i<nums.size();++i){
			save[i].compare = nums[i];
			save[i].store_one = i;
		}
		mergesort(save,0,nums.size()-1);
		for(int i=1;i<nums.size();++i){
			if(save[i].compare==save[i-1].compare){
				if(abs(save[i].store_one-save[i-1].store_one)<=k){     //这种边界情况读清楚  不是<  是<=
					return true;
				}
			}
		}
		
		return false;
    }
};


/*
//想起了自己自创的排序算法以及搭配的特制结构体   试试吧   这样的话就算是和I没什么大的区别了
//第20组数据没过   [1,0,1,1] 1  Output: false   Expected: true 
//顿时想到了快速排序是不稳定的    没事   换归并排序

class Use_for_quicksort{
	public:
		int compare;
		int store_one;
};

//quicksort algotithm
int quicksort(Use_for_quicksort *data,int low,int high){
	int partition(Use_for_quicksort *data,int low,int high);
	if ((high-low)<1){
		return 0;
	}
	
	int middle=partition(data,low,high-1);
	quicksort(data,low,middle);
	quicksort(data,middle+1,high);
	return 0;
}

int partition(Use_for_quicksort *data,int low,int high){
	int backup_low=low;
	int backup_high=high;
	Use_for_quicksort middle_data=data[low];
	for(;low<high;){
		for(;low<high;){
			if(data[high].compare>middle_data.compare){
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(data[low].compare<middle_data.compare){
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		
		if(nums.size()==0||nums.size()==1){
			return false;
		}
		
        Use_for_quicksort save[nums.size()];
		for(int i=0;i<nums.size();++i){
			save[i].compare = nums[i];
			save[i].store_one = i;
		}
		quicksort(save,0,nums.size());
		for(int i=1;i<nums.size();++i){
			if(save[i].compare==save[i-1].compare){
				if(abs(save[i].store_one-save[i-1].store_one)<=k){     //这种边界情况读清楚  不是<  是<=
					return true;
				}
			}
		}
		
		return false;
    }
};
*/