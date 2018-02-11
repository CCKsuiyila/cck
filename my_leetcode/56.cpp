//别人说排序然后合并,试试
//根据自己的vector版排序改了个适合这个题的排序    结果改完一下就accept了
//也是令人惊讶    这个脑残题   那就思考一下吧
//虽然还不知道为啥排了序再加上原来的方法就好了

//以为这道题很简单   所以直接在电脑上敲了   结果他妈的题说的那么简单   
//什么都不说     浪费好多时间   还好学会交流了(当然这次算是模仿吧)
//我感觉我那个hash版的肯定更高效    有空再看看这个题

//对,感慨一下   自己那个排序真好用,改一改也很简单
//12MS   82.05%
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 int quicksort(vector<Interval>& data,int low,int high){
	int partition(vector<Interval>& data,int low,int high);
	if ((high-low)<1){
		return 0;
	}
	
	int middle=partition(data,low,high-1);
	quicksort(data,low,middle);
	quicksort(data,middle+1,high);
	return 0;
}

int partition(vector<Interval>& data,int low,int high){
	int backup_low=low;
	int backup_high=high;
	Interval middle_data=data[low];
	for(;low<high;){
		for(;low<high;){
			if(data[high].start>middle_data.start){
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(data[low].start<middle_data.start){
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
    vector<Interval> merge(vector<Interval>& intervals) {
		if(intervals.size()<=1){
			return intervals;
		}
		quicksort(intervals, 0 ,intervals.size());
		vector<Interval> result;
		result.push_back(intervals[0]);
		for(int i = 1,j = 0;i<intervals.size();++i){
			if(intervals[i].start<=result[j].end&&intervals[i].end>=result[j].start){
				Interval temp(min(result[j].start,intervals[i].start),max(result[j].end,intervals[i].end));
				result.pop_back();
				result.push_back(temp);
				while(j>=1&&result[j].start<=result[j-1].end&&result[j].end>=result[j-1].start){
					Interval temp(min(result[j].start,intervals[j-1].start),max(result[j].end,intervals[j-1].end));
					result.pop_back();
					result.pop_back();
					result.push_back(temp);
					--j;
				}
			}else{
				result.push_back(intervals[i]);
				++j;
			}
		}
		return result;
    }
}; 




//hash
//如此脑残的题   什么都不说   出了错,错的莫名其妙   傻逼一样
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 /*
class Solution {
public:
    Solution(){
       for(int i=0;i<10000;++i){
           hash[i] = -1;
       }
    }
    vector<Interval> merge(vector<Interval>& intervals) {
		if(intervals.size()<=1){
			return intervals;
		}
		vector<Interval> result;
		int i = 0;
		int max=0;
		while(i<intervals.size()){
			for(int j = intervals[i].start;j<intervals[i].end;++j){
				hash[j]=j;
				if(j>max){
					max=j;
				}
			}
			++i;
		}
		Interval temp;
		for(int j = 0;j<=max;){
			while(hash[j]!=j){++j;}
			temp.start=j;
			while(hash[j]==j){++j;}
			temp.end=j;
			result.push_back(temp);
		}
		return result;
    }
private:
    int* hash=new int[10000];
}; 
*/