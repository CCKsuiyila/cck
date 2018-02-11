//这算是开始正式做吧(124这三道都是随意做的)  像以前做清华的一样 先在纸上,然后敲到电脑上
//Congratulations, you've just unlocked a solution!   这次竟然出现这个   虽然还不懂是啥意思
//这次最大的收获   磨刀不误砍柴工   写之前花点时间想清楚是很必要的
//不足的是  这次还是开了小黑框   做了类似调试的事   这是应该避免的   不过这次也发现了自己的一个问题   以后一定要初始化   宁愿多花时间
//循环给每一个数组元素初始化     像这次   错的莫名其妙     讲真  不开小黑框  这次真的不知道咋回事   虽然现在还不知道具体啥
//原因(就知道了是哪里有问题)
// 32 ms   48.92%

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int s_length = s.size();
		int max_size = 0;
		int cur_length = 0;
		int* hash = new int[95];
        for(int i = 0; i < s_length; ++i){
			for(int k = 0; k<95; ++k){
			    hash[k] = 0;
			}
			cur_length = 0;
			int index = 0;
			for(int j = i; j < s_length; ++j){
				index = s[j] - '!' + 1;
				if(hash[index] != 8){
					hash[index] = 8;
					cur_length += 1;
				}else{
					break;
				}
			}
			if(cur_length>max_size){
				max_size = cur_length;
			}
		}
		delete [] hash;
		return max_size;
    }
};