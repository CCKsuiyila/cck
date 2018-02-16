//这个版本的二分查找查找失败时统一返回-100.这个版本的二分查找可以处理重复元素    返回重复元素中index最小者

//首先想到了hash表,然后是二分查找,但是没给范围,hash用起来有点慌
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();++i){
			if(numbers[i]*2==target){   //3.这种情况没考虑到
				vector<int> result;
				result.push_back(i+1);        
				result.push_back(i+2);
				return result;
			}
			int temp = binary_search(numbers,0,numbers.size(),target-numbers[i]);
			if(temp!=-100){
				vector<int> result;
				result.push_back(i+1);         //1.人家要的是index不是value    2.Please note that your returned answers (both index1 and index2) are not zero-based.什么玩意
				result.push_back(temp+1);
				return result;
			}
		}
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