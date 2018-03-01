//这次一定要吸取教训   不要随意去从122改了   直接自己先想通    
//感觉122也有问题就做完这个再去看122   不要弄得很乱
//知道应该是动态规划了   但是想不出来具体怎么规划    找别人的借鉴一下
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sum = 0;
		for(int low = 0,high = 1;low<prices.size()-1&&high<prices.size();++high){
			int temp = prices[high] - prices[low]-fee;
			if(temp>0){
				sum += temp;
				low = high+1;
				++high;
				continue;
			}
			if(prices[high]<prices[low]){
				low = high;
			}
		}
		
		return sum;
    }
};

//根据122题改写的贪心算法果然是不行的    这题贪心算法解决不了   那么122 感觉也有问题
/*
第十八组数据
Input: [1,3,7,5,10,3]
3
Output: 5
Expected: 6

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sum = 0;
		for(int low = 0,high = 1;low<prices.size()-1&&high<prices.size();++high){
			int temp = prices[high] - prices[low]-fee;
			if(temp>0){
				sum += temp;
				low = high+1;
				++high;
				continue;
			}
			if(prices[high]<prices[low]){
				low = high;
			}
		}
		
		return sum;
    }
};
*/
