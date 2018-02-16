//紧接着118    不就空间限制了吗    只能同时保留两行   没问题的   写着写着感觉对vector还是不够熟悉  
//5 ms   0.55 %      这种题懒得考虑时间了   就这样吧

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
		result.push_back(1);
		if(rowIndex==0){
			return result;
		}
		if(rowIndex==1){       //这种情况也算特殊情况,因为下面标注那一句
			result.push_back(1);
			return result;
		}
		for(int i=1,j=1;i<=rowIndex;++i){
			vector<int> temp;
			temp.push_back(1);
			for(j=1;j<i-1;++j){
				temp.push_back(result[j-1]+result[j]);
			}
			temp.push_back(result[j-1]+1);               //就是这里
			temp.push_back(1);
			
			result = temp;
		}
		return result;
    }
};
