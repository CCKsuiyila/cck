//初步思路  2层for循环应该可以解决问题   这次就不纸上写了
//确实写起来很快,而且简单数据可以过,但是48/49超时了,所以还得改进,各种优化都做了,还是不过   需要换思路了
//借鉴别人的思路   过了   但是一时还不懂为啥   对  借鉴别人的也出来了Congratulations, you've just unlocked a solution! 

//19ms     49.82%    说明还有更高效的
class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = height.size() - 1;
		int i = 0;
		int water = 0;
		int temp = 0;
		while(i<j){
			temp = (j-i)*((height[i]<=height[j])?(height[i]):(height[j]));
			if(temp>water){
				water = temp;
			}
			(height[i]<=height[j])?(++i):(--j);
		}
		return water;
    }
};


/*
//自己的超时版  2层for循环
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
		int result1 = 0;
		int result2 = 0;
		int water = 0;
		for(int i = 0; i < n-1; ++i){
			for(int j = i+1,difference = 1; j<n ; ++j,++difference){
				int temp = difference*((height[i]<=height[j])?(height[i]):(height[j]));
				if(temp>water){
					result1 = i;
					result2 = j;
					water = temp;
				}
			}
		}
		return water;
    }
};
*/