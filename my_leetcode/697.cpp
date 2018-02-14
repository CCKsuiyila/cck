//别人用的关联容器map加速
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> temp(nums);
		sort(temp.begin(),temp.end());
		vector<int> target;
		int target_count = 0;
		for(int j,i=0;i<temp.size();i = j){
			for(j=i+1;j<temp.size()&&temp[j]==temp[i];++j){}
			if(j-i==target_count){
				target.push_back(temp[i]);
			}else if(j-i>target_count){
				target_count = j-i;
				//target.swap(vector<int>());
				vector <int>().swap(target);
				target.push_back(temp[i]);
			}
		}
		
		int result=50000;
		for(int k=0;k<target.size();++k){
			int begin_index;
			int end_index;
			for(int i = 0;i<nums.size();++i){
				if(nums[i]==target[k]){
					begin_index = i;
					break;
				}
			}
			for(int i = nums.size()-1;i>=0;--i){
				if(nums[i]==target[k]){
					end_index = i;
					break;
				}
			}
			if(end_index-begin_index+1<result){
				result = end_index-begin_index+1;
			}
		}
		
		return result;
    }
};