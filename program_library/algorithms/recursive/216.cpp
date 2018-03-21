//这个题感觉题目很简单   但是要给出所有可能的答案  所以可能有点麻烦   试着写写吧
//这个找出第一个答案很快,但是如何找出后面的答案又变成了一个找规律的问题  是自己找呢,还是找个答案看看呢
//我写不出来了  我要找个答案看看

//刚开始我也想过这种最朴素的算法,当时想的九层循环有点太多了吧,而且效率不会太好,当时忘记了递归,也确实是好久都不用了
//3 ms     1.73 %             不过从结果来看    这样效率确实低    几乎倒数了      
//不过看了一圈评论,也都是递归这个思路     接下来自己改下细节吧      暂时不去写非递归了
//这个题也回忆了一下指针   尤其是复杂类型的指针
/*
class Solution{
public:
	vector<vector<int>> combinationSum3(int k, int n){
		vector<vector<int>> res;
		vector<int> out;
		combinationSum3DFS(k,n,1,out,res);
		return res;
	}
	
	void combinationSum3DFS(int k, int n, int level, vector<int> &out, vector<vector<int>> &res){
		if(n<0){
			return;
		}
		if(n==0&&out.size()==k){
			res.push_back(out);
		}
		for(int i=level;i<=9;++i){
			out.push_back(i);
			combinationSum3DFS(k,n-i,i+1,out,res);
			out.pop_back();
		}
	}
};
*/

//improve
// 2 ms    32.34 %   效果还行
class Solution{
public:
	vector<vector<int>> combinationSum3(int k, int n){
		vector<vector<int>> result;
		vector<int> current;
		combinationSum3DFS(k,n,1,current,result);
		return result;
	}
	
	int stop = 0;   //省事来个全局变量    这个用来减少不必要的递归
	void combinationSum3DFS(int k, int n, int level, vector<int> &current, vector<vector<int>> &result){
		if(n<0){
			stop = 1;
			return;
		}
		if(n==0&&current.size()==k){
			result.push_back(current);
		}
		for(int i=level;i<=9&&stop==0;++i){
			current.push_back(i);
			combinationSum3DFS(k,n-i,i+1,current,result);
			current.pop_back();
		}
		stop = 0;
	}
};

/*
//九层循环试试
// 2 ms    32.34 %          看来要超过2ms是要找到规律    而不是这样挨个遍历   暂时不找了     这个题真的写了好久   虽然说是事比较多的时候写的
class Solution{
public:
	vector<vector<int>> combinationSum3(int k, int n){
		vector<vector<int>> result;
		vector<int> current;
		int level;
		for(int one = 1,level=1;level<=k&&n>0&&one<=9;++one){
			current.push_back(one);
			n -= one;
			if(n==0&&level==k){
				result.push_back(current);
				n += one;
				current.pop_back();
				break;
			}
			for(int two = one+1,level=2;level<=k&&n>0&&two<=9;++two){
				current.push_back(two);
				n -= two;
				if(n==0&&level==k){
					result.push_back(current);
					n += two;
					current.pop_back();
					break;
				}
				for(int three = two+1,level=3;level<=k&&n>0&&three<=9;++three){
					current.push_back(three);
					n -= three;
					if(n==0&&level==k){
						result.push_back(current);
						n += three;
						current.pop_back();
						break;
					}
					for(int four = three+1,level=4;level<=k&&n>0&&four<=9;++four){
						current.push_back(four);
						n -= four;
						if(n==0&&level==k){
							result.push_back(current);
							n += four;
							current.pop_back();
							break;
					}
						for(int five = four+1,level=5;level<=k&&n>0&&five<=9;++five){
							current.push_back(five);
							n -= five;
							if(n==0&&level==k){
								result.push_back(current);
								n += five;
								current.pop_back();
								break;
							}
							for(int six = five+1,level=6;level<=k&&n>0&&six<=9;++six){
								current.push_back(six);
								n -= six;
								if(n==0&&level==k){
									result.push_back(current);
									n += six;
									current.pop_back();
									break;
								}
								for(int seven = six+1,level=7;level<=k&&n>0&&seven<=9;++seven){
									current.push_back(seven);
									n -= seven;
									if(n==0&&level==k){
										result.push_back(current);
										n += seven;
										current.pop_back();
										break;
									}
									for(int eight = seven+1,level=8;level<=k&&n>0&&eight<=9;++eight){
										current.push_back(eight);
										n -= eight;
										if(n==0&&level==k){
											result.push_back(current);
											n += eight;
											current.pop_back();
											break;
										}
										for(int nine = eight+1,level=9;level<=k&&n>0&&nine<=9;++nine){
											current.push_back(nine);
											n -= nine;
											if(n==0&&level==k){
												result.push_back(current);
												n += nine;
												current.pop_back();
												break;
											}
											n += nine;
											current.pop_back();
										}
										n += eight;
										current.pop_back();
									}
									n += seven;
									current.pop_back();
								}
								n += six;
								current.pop_back();	
							}
							n += five;
							current.pop_back();							
						}
						n += four;
						current.pop_back();
					}
					n += three;
					current.pop_back();
				}
				n += two;
				current.pop_back();
			}
			n += one;
			current.pop_back();
		}
		return result;
	}
};
*/