//这个题一眼看上去   没思路   感觉是数学题找规律    没办法和什么算法呀数据结构呀联系起来
//自己找了一会没找出规律还是去看别人已经找出的规律吧

//最后就大概根据别人的规律写出来了
//29 ms   25.50 %

class Solution {
public:
    vector<int> constructArray(int n, int k){
		vector<int> standard;
		for(int i=0; i<n; ++i){
			standard.push_back(i+1);
		}
		
		if(n<=2||k==1){
			return standard;
		}
		vector<int> result;
		
		if(k%2==1){     //k为奇数需要处理一下
			result.push_back(0);
			--k;
		}
		
		int count = 1;
		int low = 0; 
		int high = standard.size()-1;
		result.push_back(standard[high]);
		--high;
		result.push_back(standard[low]);
		++low;
		count = 2;
		
		for(;count<k;count+=2){
			result.push_back(standard[high]);
			--high;
			if(high<low){
				break;      //加最后一个数会这样
			}
			result.push_back(standard[low]);
			++low;
		}
		
		while(low<=high){
			result.push_back(standard[low]);
			++low;
		}
		
		if(k%2==1){     //k为奇数需要处理一下
			result[0] = result[result.size()-1];
			result.pop_back();
		}
		
		return result;
    }
	
};