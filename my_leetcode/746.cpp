//动态规划
class Solution{
public:
    int minCostClimbingStairs(vector<int>& cost){
        vector<int>  temp;
		temp.push_back(0);
		temp.push_back(0);
		for(int i=2;i<=cost.size();++i){
			if((cost[i-1]+temp[i-1])<(cost[i-2]+temp[i-2])){
				temp.push_back(cost[i-1]+temp[i-1]);
			}else{
				temp.push_back(cost[i-2]+temp[i-2]);
			}
		}
		return temp[cost.size()];
    }
};



//贪心算法不行...
/*
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost){
        int sum_one = cost[0];
		int i = 0;
		while(i!=(cost.size()-1)&&i!=(cost.size()-2)){
			if(cost[i+1]<cost[i+2]){
				sum_one += cost[i+1];
				i = i+1;
			}else{
				sum_one += cost[i+2];
				i = i+2;
			}
		}
		
		int sum_two = cost[1];
		i = 1;
		while(i!=(cost.size()-1)&&i!=(cost.size()-2)){
			if(cost[i+1]<cost[i+2]){
				sum_two += cost[i+1];
				i = i+1;
			}else{
				sum_two += cost[i+2];
				i = i+2;
			}
		}
		
		if(sum_one<sum_two){
			return sum_one;
		}else{
			return sum_two;
		}
    }
};
*/