//阔别好久,又开始在纸上写了
//想好思路,在纸上写好后,搬到电脑上,改了几个小语法错误,然后通过了152组数据(共300多组)
//然后瞬间发现了自己把题考虑简单了
//但是很快又根据忘记考虑的数据,想出了更加严谨的算法.  但是只通过了168组数据
//第二天(清明节第二天)把整个代码抄了一遍,发现还是没有逻辑上的错误,于是开始查看错误的那组数据
//还是没发现有啥错误   最后没办法,只能调试一下了   很快发现了问题所在   修改后就通过了
//通过之后发现,自己的方法其实就能解决知道,但是没考虑的特殊情况.

//这又算是浪费了时间吧    严谨性还需加强   最终还是调试了.
//不过大思路是没问题的

// 9 ms   64.84%
class Solution {
public:
	int findTheLow(vector<int>& height,int from,int size){
		for(;(from+1)!=size&&height[from+1]<=height[from];++from);
		return from;
	}
	int findTheHigh(vector<int>& height,int from,int size){
		for(;(from+1)!=size&&height[from+1]>=height[from];++from);
		return from;
	}
    int trap(vector<int>& height) {
        int sum = 0;
		int now = 0;
		int size = height.size();
		if(size<3){
			return 0;
		}
		int* high_array = new int[10000];
		high_array[0]=now;
		int high_count=1;
		for(;now!=size-1;++high_count){
			int low = findTheLow(height, now, size);
			/*
			if(low==size-1){     //解决了这里168变accepted
				return 0;
			}
			*/
			high_array[high_count] = findTheHigh(height, low, size);
			now=high_array[high_count];
		}
		cout<<high_count;
		for(int low=0,high=high_count-1;low!=high;){
			int standard;
			if(height[high_array[low]]<=height[high_array[high]]){
				standard = height[high_array[low]];
				for(int j=high_array[low]+1;j!=high_array[high];++j){
					if(standard>height[j]){
						sum+=standard-height[j];
						height[j]=standard;
					}
				}
				int m=low+1;
				for(;m!=high&&height[high_array[m]]<=height[high_array[low]];++m);
				low=m;
			}else{
				standard = height[high_array[high]];
				for(int j=high_array[low]+1;j!=high_array[high];++j){
					if(standard>height[j]){
						sum+=standard-height[j];
						height[j]=standard;
					}
				}
				int m=high-1;
				for(;m!=low&&height[high_array[m]]<=height[high_array[high]];--m);
				high=m;
			}
		}
		return sum;
    }
};


//这是原来少考虑了一种情况的
/*
//对 回忆一下自己的做题思路(最近每做一题就把这个粘过去)
//1.先理解题
//2.确定解题思路(选择数据结构算法什么的)   确定能解决正常情况,也不用考虑太多复杂度
//3.2达到之后, 开始考虑各种解决可能遇到的奇怪情况   然后看看有没有复杂度更低的思路

class Solution {
public:
	int findTheLow(vector<int>& height,int from,int size){
		for(;(from+1)!=size&&height[from+1]<=height[from];++from);
		return from;
	}
	int findTheHigh(vector<int>& height,int from,int size){
		for(;(from+1)!=size&&height[from+1]>=height[from];++from);
		return from;
	}
    int trap(vector<int>& height) {
        int sum = 0;
		int now = 0;
		int size = height.size();
		if(size<3){
			return 0;
		}
		//解决M形状
		int low = findTheLow(height, now, size);
		int high = findTheHigh(height, low, size);
		if(low==now){
			now=high;
		}
		while(now!=size-1){
			int low = findTheLow(height, now, size);
			int high = findTheHigh(height, low, size);
			if(low==size-1){
				return sum;
			}
			int lower;
			if(height[now]<=height[high]){
				lower = height[now];
			}else{
				lower = height[high];
			}
			for(int i = now+1;i!=high;++i){
				if(lower>height[i]){
					sum+=lower-height[i];
				}
			}
			now=high;
		}
		return sum;
    }
};
*/