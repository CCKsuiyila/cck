class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size()*nums[0].size()!=r*c){
			return nums;
		}else{
			vector<int> temp;
			for(int i=0;i<nums.size();++i){
				for(int j=0;j<nums[0].size();++j){
					temp.push_back(nums[i][j]);
				}
			}
			
			int count = 0;
			vector<vector<int>> result;
			for(int i=0;i<r;++i){
				vector<int> row;
				for(int j=0;j<c;++j){
					row.push_back(temp[count++]);
				}
				result.push_back(row);
			}
			
			return result;
		}
		
    }
};