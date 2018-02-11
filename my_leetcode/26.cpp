/*
//不得不吐槽这题目,感觉总是说不清楚   或许也有点原因是因为英语不是母语吧
//刚开始以为只要管length就好了  结果...  才知道人家是真正要改变数组的.
//然后思考一下  很快有个想法    但不是很确定   就写上去试试咯   
//然后改了俩错吧   第一个加了nums[i] = -100;  第二个把0改成了-100  然后就过了
//整体来说,这个题不难   还是数组加双指针问题   复杂度不超过n的平方吧(前面的系数是小于1的)

// 29 ms    51.00%
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0){
			return 0;
		}
		int temporary = nums[0];
		int length = size;
		int null_index=0;
		for(int i = 1; i<size; ++i){
			if(nums[i]==temporary){
				length = length-1;
				nums[i] = -100;
			}else{
				temporary = nums[i];
				for(int j = null_index;j<i;++j){
				    if(nums[j]==-100){
				        nums[j]=nums[i];
						nums[i] = -100;
				        null_index = j+1;
				        break;
				    }
				}
			}
		}
		return length;
    }
};
*/

//试试stl
//搜了半天  感觉说的都不是很清楚    直接上手试了   然后就过了    
//以后多了解一下STL   多试试   反正不用付出啥  最好找个专门介绍STL的网站(除了那个英文的)



//32 ms   40.91
#include<algorithm>  
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int length = unique(nums.begin(),nums.end())-nums.begin();
		return length;
    }
};