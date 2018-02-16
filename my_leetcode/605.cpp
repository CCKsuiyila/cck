// 一眼看上去挺简单的     不知道有没有藏什么阴谋   先试试吧
//想的挺简单的,刚开始写的时候越写越麻烦,感觉不对,觉得肯定有更简单的写法,这时候停下来,直接换了种写法,然后这种写法就简单了    时间复杂度还行
//18 ms  64.64 %
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		
		int count = 0;
		for(int i = 0;i<flowerbed.size();++i){
			if(flowerbed[i]!=1&&((i-1)<0||flowerbed[i-1]!=1)&&((i+1)>=flowerbed.size()||flowerbed[i+1]!=1)){
				flowerbed[i] = 1;
				++count;
			}
		}
		
		if(count>=n){
			return  true;
		}else{
			return false;
		}
    }
};