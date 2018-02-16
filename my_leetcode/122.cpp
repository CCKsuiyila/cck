//这个题不怎么理解    还没有例子
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
		int sum = 0;
		for(int low = 0,high = 1;low<prices.size()-1&&high<prices.size();){
			if(prices[low]<prices[high]){
				sum += prices[high] - prices[low];
			}
			low = high;
			++high;
		}
		
		return sum;
    }
};