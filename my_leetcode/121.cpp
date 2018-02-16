//记录一些信息,加快速度  然后就想到动态规划  
//然后就过了    9ms   超过10.54 %的人
//其实这个题用个一般的数组不用vector可能好点,不过算了     都习惯vector了
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		
		if(prices.size()<2){   //没这个还不行     算了算了   就加上吧
			return 0;
		}
		
		vector<int> left_min_contain;
		left_min_contain.push_back(prices[0]);
		for(int i=1;i<prices.size()-1;++i){
			if(prices[i]<left_min_contain[i-1]){
				left_min_contain.push_back(prices[i]);
			}else{
				left_min_contain.push_back(left_min_contain[i-1]);
			}
		}
		
		vector<int> right_max_not_contain;
		right_max_not_contain.push_back(prices[prices.size()-1]);
		for(int i=prices.size()-2,j=0;i>=0;--i,++j){
			if(prices[i]>right_max_not_contain[j]){
				right_max_not_contain.push_back(prices[i]);
			}else{
				right_max_not_contain.push_back(right_max_not_contain[j]);
			}
		}
		
		for(int i=0,j=right_max_not_contain.size()-1;i<j;++i,--j){
			int temp = right_max_not_contain[i];
			right_max_not_contain[i] = right_max_not_contain[j];
			right_max_not_contain[j] = temp;
		}
		
		int result = 0;
		for(int i=0;i<left_min_contain.size();++i){
			if(right_max_not_contain[i]-left_min_contain[i]>result){
				result = right_max_not_contain[i]-left_min_contain[i];
			}
		}
		
		return result;
    }
};

/*
//最简单的方法   不过怕是要超时   果然,最后一组数据超时了
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		
		if(prices.size()<2){
			return 0;
		}
		
        int result = 0;
		for(int i=0;i<prices.size()-1;++i){
			for(int j = i+1;j<prices.size();++j){
				if(prices[j]-prices[i]>result){
					result = prices[j]-prices[i];
				}
			}
		}
		
		return result;
    }
};
*/