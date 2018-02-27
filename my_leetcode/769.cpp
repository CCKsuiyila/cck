//想通再写     可是不是很通就accep了   就先这样吧   主要是没法结合已经学的   感觉就是发现了个规律
//3 ms     显示下面这东西    估计是新题做的人少吧
//Accepted Solutions Runtime Distribution   Sorry. We do not have enough accepted submissions to show runtime distribution chart.
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
		int result = 0;
        int current_max = 0;
		
		for(int i=0;i<arr.size();++i){
			if(arr[i]>current_max){
				current_max = arr[i];
			}
			if(i==current_max){
				++result;
			}
		}
		return result;
    }
};