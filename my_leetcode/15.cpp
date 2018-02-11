//两种思路做完之后都不过,然后百度一下,看看别人的做法
//这下可高兴了  K-SUM 原来是一类问题   还挺难
//而且关于这类问题也就这两种方法   hash和排序    其中去重也是很重要的一部分
//今天从早上9点起床开始做到下午5点多   努力没白费啊    
//当然不足之处就是  直接电脑上开敲了  然后一些错误浪费了很多时间
//过段时间回过头来把这个解决掉.



//很快又想到,不用hash了,用quicksort+binary_search
//这次就在原来基础上改  很快   but
//在同样的地方时间超时了

//311 / 313 test cases passed
class Use_for_quicksort{
	public:
		int compare;
		int store_one;
};

//quicksort algotithm
int quicksort(Use_for_quicksort *data,int low,int high){
	int partition(Use_for_quicksort *data,int low,int high);
	if ((high-low)<1){
		return 0;
	}
	
	int middle=partition(data,low,high-1);
	quicksort(data,low,middle);
	quicksort(data,middle+1,high);
	return 0;
}

int partition(Use_for_quicksort *data,int low,int high){
	int backup_low=low;
	int backup_high=high;
	Use_for_quicksort middle_data=data[low];
	for(;low<high;){
		for(;low<high;){
			if(data[high].compare>middle_data.compare){
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(data[low].compare<middle_data.compare){
				low=low+1;
			}else{
				data[high]=data[low];
				high=high-1;
				break;
			}
		}
	}
	int middle=low;
	data[low]=middle_data;
	low=backup_low;
	high=backup_high;
	return middle;
}

//二分查找(略做改编,返回值为查找元素的个数)
int binary_search(Use_for_quicksort *data,int low,int high
,int be_searched){
	int number = 0;
	for(;low<high;){
		int middle=(low+high)>>1;
		if(be_searched<data[middle].compare){
			high=middle;
		}
		else if(be_searched>data[middle].compare){
			low=middle+1;
		}
		else{
			for(;be_searched==data[middle].compare;middle=middle-1);
			middle=middle+1;
			for(;be_searched==data[middle].compare;middle=middle+1){
				number += 1;
			}
			return number;
		}
	}
	return 0;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		int size = nums.size();
		int count = 0;
		if(size<3){
		    return result;
		}
        Use_for_quicksort* array = new Use_for_quicksort[size+10];
		for(int i=0;i<size;++i){
			array[i].compare = nums[i];
		}
		quicksort(array,0, size);
		for(int i = 0; i<size-1; ++i){
			for(int j = i+1; j<size; ++j){
				int temp = -(nums[i]+nums[j]);
				int three= binary_search(array, 0, size, temp);
				if(temp==nums[i]&&temp==nums[j]){
					if(three>=3){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
						}
			    }
				else if(temp==nums[i]||temp==nums[j]){
						if(three>=2){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
						}
					
				}else{
						if(three>=1){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
					 }
				}
			}
		}
		return result;
    }
};





/*
//初步构思 2层for循环加hash  直接在电脑上敲了
//这是最脑残的一次,没有之一
//大思路看起来是没问题的    但是没有考虑具体情况    直接上手了 
//刚开始各种小错误   每一个都困扰好久    要是在纸上先来一遍估计就好多了
//后来发现  input各种奇葩   这时候脑残的开始根据新出现的情况改代码(就是学长说的不应该做的那种)
//结果人家情况越来越多   终于算是把所有的奇葩情况见了一遍,但是感觉不行了   得重头理一遍思路
//于是重头理了一边思路,然后终于差不多没问题了(理了思路之后,遇见了最后一次奇葩情况,很快处理了)但是他妈的发现这种思路内存不够
//过了311,就差最后俩   这也是hash的尴尬   人家数字9万多, 但是内存申请那么多就超出了规定的    只能换思路了
//对  这他妈什么奇葩情况,狗日的leetcode,什么都不说清   狗逼



//311 / 313 test cases passed.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		int size = nums.size();
		int count = 0;
		if(size<3){
		    return result;
		}
        int* hash = new int[30000];
		int* hash_negative = new int[30000];
		for(int i = 0; i<30000; ++i){
			hash[i]= 0;
			hash_negative[i] = 0;
		}
		for(int i = 0; i<size; ++i){
			if(nums[i]>=0){
                hash[(nums[i])] += 1 ;
            }else{
                hash_negative[-(nums[i])] += 1 ;
            }
		}
		for(int i = 0; i<size-1; ++i){
			for(int j = i+1; j<size; ++j){
				int temp = -(nums[i]+nums[j]);
				if(temp==nums[i]&&temp==nums[j]){
					if(temp>=0){
						if(hash[temp]>=3){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
							hash[temp] = 1;
						}
					}else{
						if(hash[-temp]>=3){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
							hash[-temp] = 1;
						}
					}
				}
				else if(temp==nums[i]||temp==nums[j]){
					if(temp>=0){
						if(hash[temp]>=2){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
							hash[temp] = 1;
						}
					}else{
						if(hash_negative[-temp]>=2){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
							hash_negative[temp] = 1;
						}
					}
				}else{
					if(temp>=0){
						if(hash[temp]>=1){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
						}
					}else{
						if(hash_negative[-temp]>=1){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
						}
					}
				}
			}
		}
		return result;
    }
};
*/