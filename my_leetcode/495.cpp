//一眼看上去   题目并不难   背景也挺有意思 
//  60 ms    66.51 %

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration){
        
		if(timeSeries.size()==0){
			return 0;
		}
		
		int result = duration;  //最后一次攻击直接加上
		
		for(int i=0;i<timeSeries.size()-1;++i){
			int temp = timeSeries[i+1]-timeSeries[i];
			if(temp<duration){
				result += temp;
			}else{
				result += duration;
			}
		}
		
		return result;
    }
};