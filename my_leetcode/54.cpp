//其实自己是有思路的,但是不想写,  然后搜了搜别人怎么写,看了第一个,发现别人的思路还不如自己的呢,
//于是就自己写了(在纸上写)    下午敲到电脑上  然后改了点小错误  就accept了
//小错误下面有标注
// 3MS   3.15%   
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;   
		if(matrix.empty()){     //第一处,发现空的vector数组不能用size(),否则提醒
			return result;      //reference binding to null pointer of type 'struct value_type'
		}
        int high = 0;
		int low = matrix.size() - 1;
		int lef = 0;
		int righ = matrix[0].size() - 1;
		while(high<=low&&lef<=righ){              //<= 写成了<-
			for(int i = lef; i<=righ; ++i){
				result.push_back(matrix[high][i]);
			}
			++high;
			if(high>low){
				return result;
			}
			for(int i = high; i<=low; ++i){
				result.push_back(matrix[i][righ]);
			}
			--righ;
			if(righ<lef){
				return result;
			}
			for(int i = righ; i>=lef; --i){
				result.push_back(matrix[low][i]);
			}
			--low;
			if(low<high){
				return result;
			}
			for(int i = low; i>=high; --i){
				result.push_back(matrix[i][lef]);
			}
			++lef;
		}
		return result;
    }
};