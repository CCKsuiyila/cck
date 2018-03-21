//这个版本的二分查找如果找到则返回正确的index.若找不到则返回一个比目标值小的index(比目标值小是一定的,但是不能保证是第一个,写的不是很严谨,还需证明)
//28 ms    96.27 %     竟然加速这么多   可以的                      但是改动之后需要对k为负值进行处理     k为负值是  一律返回0   
// 这大概是你排名最靠前的一道题了吧  再来一遍竟然40多ms  有毒       讲道理 这个k我是真的不懂了     之前那个版本我也没考虑k负值情况            
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
		
		if(k<0){
			return 0;
		}
		if(nums.size()<2){
			return 0;
		}
		if(k==0){          //这种情况的数据是真的骚
			int result = 0;
			sort(nums.begin(),nums.end());
			for(int i=0,j=i+1;i<nums.size()-1;i=j){
				for(j=i+1;j<nums.size()&&nums[j]==nums[i];++j){}
				if(j!=i+1){
					++result;
				}
			}
			return result;
		}
		
		sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
		
		int result = 0;
		
		int temp = 1;
		for(int i=0;i<nums.size()-1;++i){                //改完之后才发现这样的加速真的是效果有限...
			temp = binary_search(nums,temp,nums.size(),k+nums[i]);
			if(nums[temp]-nums[i]==k){
				++result;
			}
		}
		
		return result;
    }
	
	//二分查找vector版
	int binary_search(vector<int>& numbers,int low,int high,int be_searched){
	
		for(;low<high;){
			int middle=(low+high)>>1;
			if(be_searched<numbers[middle]){
				high=middle;
			}
			else if(be_searched>numbers[middle]){
				low=middle+1;
			}
			else{
				//for(;be_searched==numbers[middle];middle=middle-1);
				//middle=middle+1;
				return middle;
			}
		}
		int i=low;       //不是很严谨的找第一个比目标值小的index
		while(numbers[i]>be_searched){
			--i;
		}
		return i;
	}
};

/*
//41 ms   36.87 %     改进下binary_search的返回值应该可以加速
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
		
		if(nums.size()<2){
			return 0;
		}
		if(k==0){          //这种情况的数据是真的骚
			sort(nums.begin(),nums.end());
			int result = 0;
			for(int i=0,j=i+1;i<nums.size()-1;i=j){
				for(j=i+1;j<nums.size()&&nums[j]==nums[i];++j){}
				if(j!=i+1){
					++result;
				}
			}
			return result;
		}
		
		sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
		
		int result = 0;
		
		for(int i=0;i<nums.size();++i){
			cout<<nums[i]<<" ";
			int temp = binary_search(nums,i+1,nums.size(),k+nums[i]);
			if(temp!=-100){
				++result;
			}
		}
		
		return result;
    }
	
	//二分查找vector版
	int binary_search(vector<int>& numbers,int low,int high,int be_searched){
	
		for(;low<high;){
			int middle=(low+high)>>1;
			if(be_searched<numbers[middle]){
				high=middle;
			}
			else if(be_searched>numbers[middle]){
				low=middle+1;
			}
			else{
				for(;be_searched==numbers[middle];middle=middle-1);
				middle=middle+1;
				return middle;
			}
		}
		return -100;
	}
};
*/