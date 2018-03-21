
//a more effective method    so resourceful
//6ms 12.97%   i think this will more efficient than before but result is not that, may be the test data is too little,only ten.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);
        for(int i=0;i<nums.size();++i){
            int last_size = result.size();
            for(int j=0;j<last_size;++j){
                vector<int> temp(result[j]);
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
};


/*
//backtracking conbining of the recursive and cycle
//write by myself
//7ms 12.97%   but the efficiency is bad
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);
        recursive(result,nums,temp,0);

        return result;
    }

    void recursive(vector<vector<int>> &result,vector<int> &nums,vector<int> &temp,int start){
        for(int i=start;i<nums.size();++i){
            temp.push_back(nums[i]);
            result.push_back(temp);
            recursive(result,nums,temp,i+1);
            temp.pop_back();
        }
        return;
    }
    
};
*/
