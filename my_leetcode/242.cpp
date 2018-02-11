//虽然才周四,突然就有想做题的感觉了
//刚开始没有读清楚题,以为是whistory的简单版,结果编完后不对
//再读完题,真正理解了题  然后直接hash出现在脑子里   然后直接上手敲完  accept(一遍)

//交流阶段发现了还有另一个思路(排序然后比对)  具体哪个快试一试吧
//对,和你一样的思路还有更好的优化
//对比之下还是hash更快   快好多

//排序比对版
//23MS    22.14 %
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        sort(s.begin(),s.end());
		sort(t.begin(),t.end());
		if(s==t){
			return true;
		}else{
			return false;
		}
    }
};

/*
//hash版
//9MS  77.75%
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int s_count[30] = {0};
		int t_count[30] = {0};
		for(int i = 0;i<s.size();++i){
			++s_count[s[i]-'a'];
		}
		for(int i = 0;i<t.size();++i){
			++t_count[t[i]-'a'];
		}
		int j=0;
		for(;j<26&&s_count[j]==t_count[j];++j);
		if(j==26){
			return true;
		}else{
			return false;
		}
    }
};
*/