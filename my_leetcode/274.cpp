//毛概课看了看,有了个思路   晚上回来直接上手敲吧
//敲着敲着,发现自己对这个概念并没有真正理解
//然后根据错误的输出结果一边理解,一边修改,也没花多久就accept了
//对  这个降序版的快速排序一遍改好直接就能用了

//交流
//看了比人的思路,自己的思路大概也清楚了  然后改了一下,代码简化了好多
//但是测试的运行时间和原来一样,原来和现在两个都是遍历了一遍,这应该没法降低复杂度了吧
//怀疑是排序浪费了时间   换系统的排序算法试试
//学会了给系统的sort降序了  但是改用系统的sort之后效率依然没有提高

//再来个hash版看看能不能加速
//hash版写了好久没写出来   这大概就是普通程序员和高级程序员之间鸿沟吧,你能突破吗?
//迟点回来一定要搞定这个
class Solution {
public:
    int hIndex(vector<int>& citations) {
		int array[10000]={0};
		int max = 0;
		for(int i = 0;i<citations.size();++i){
			if(citations[i]>max){
				max = citations[i];
			}
			++array[citations[i]];
		}
		int count = 0;
		int i = max;
		for(;i>1&&i>=count; ){
			--i;
			count += array[i];
		}
		cout<<array[2];
		if(i==max){
			return max;
		}else{
			return count;
		}
    }
};

/*
//交流之后有点感觉
// 3MS 26.60 %
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        int i = 0;
		for(; i<citations.size()&&citations[i]>=i+1; ++i);
		return i;
    }
};
*/

/*
// 3MS 26.60 %
//降序版快速排序
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
			if(data[high]<=middle_data){    //这里感觉<=比<更高效
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(data[low]>=middle_data){     //同上
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
    int hIndex(vector<int>& citations) {
        quicksort(citations, 0, citations.size());
        int max = 0;
		for(int i = 0; i<citations.size(); ++i){
			if(i+1>=citations[i]&&citations[i]>max){
				max = citations[i];
			}
			if(citations[i]>=i+1&&i+1>max){
			    max = i+1;
			}
		}
		return max;
    }
};
*/