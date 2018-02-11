//忘记纪录了   啥都没有  下次做再看看吧
//hash 12ms   58.80%

class Use_for_quicksort{
	public:
		int compare;
		int store_one;
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        Use_for_quicksort* hash = new Use_for_quicksort[30000];
        Use_for_quicksort* hash_negative = new Use_for_quicksort[30000];
        for(int i = 0; i<30000; ++i){
            hash[i].compare = 0;
            hash_negative[i].compare = 0;
        }
        for(int i = 0; i<length; ++i){
            if(nums[i]>=0){
                hash[(nums[i])].compare += 1 ;
                hash[(nums[i])].store_one = i;
            }else{
                hash_negative[-(nums[i])].compare += 1 ;
                hash_negative[-(nums[i])].store_one = i;
            }
            
        }
        for(int i = 0; i<length; ++i){
            int difference = target - nums[i];
            if(difference>=0){
                if((difference!=nums[i]&&hash[difference].compare ==1)||(difference==nums[i]&&hash[difference].compare ==2)){
                    vector<int> result{i,hash[difference].store_one};
                    return result;
                }
            }else{
                if((difference!=nums[i]&&hash_negative[-difference].compare ==1)||(difference==nums[i]&&hash_negative[-difference].compare ==2)){
                    vector<int> result{i,hash_negative[-difference].store_one};
                    return result;
                }
            }
            
        }
    }
};

/*
//quicksort+binary_search  56ms     40.16%

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
	return -100;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        Use_for_quicksort cck[length+10];
        for(int i = 0; i<length; ++i){
            cck[i].compare = nums[i];
            cck[i].store_one = i;
        }
        quicksort(cck,0,length);
        int i;
        for(i = 0; i<length; ++i){
            int the_second = target - nums[i];
            int the_result = binary_search(cck,0,length,the_second);
            if((the_result != -100)&&(cck[the_result].store_one!=i)){
                vector<int> hhh{i,cck[the_result].store_one};
                return hhh;
            }
        }
    }
};
*/