//构造图形类问题
//3ms    1.76 %    这种题先考虑时间空间了     过了就好

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		
		vector<vector<int>> result;
		
		vector<int> temp;
		temp.push_back(1);
		for(int i=0;i<numRows;++i){
			result.push_back(temp);
		}
		
		for(int i=2;i<numRows;++i){
			for(int j=1;j<i;++j){
				if(j==i-1){        //忘记了自己的1是后加上的  所以这错了     讲道理    这种题vector真是不如数组好用
					result[i].push_back(result[i-1][j-1]+1);
					continue;
				}
				result[i].push_back(result[i-1][j-1]+result[i-1][j]);
			}
		}
		
		for(int i=1;i<numRows;++i){
			result[i].push_back(1);
		}
        
		return result;
    }
};