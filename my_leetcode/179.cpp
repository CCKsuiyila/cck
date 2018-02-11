//看完这个题,思考了一会大概有个思路了
//定义一个比较函数,可以比较两个数字哪个放前面,然后借助quicksort给这个数组排个序,
//然后直接当做字符串连起来就好了

//就按照自己上面想的思路accept了,不过因为直接敲了, 所以出了些小问题
//还用了小黑框调试   尴尬  问题下面有记录

//这次首先对快速排序有复习了一遍,然后改写,思路很好
//然后突发奇想想到了string的妙用,查了查,果然有,然后就学着用了   然后还用的挺好
//那个排序排出来的越靠后的越要放到前面
//但是这个用时实在是略难看    是时候交流一下了

//交流
//交流完之后更有成就感了   因为别人也都是这个思路  不过不知道他们的速度咋样(基本都是Java和Python的)
//巨大的成就感啊   这是排序里面最难的题    然后你自己很快就把关键的思路想出来了    满满的成就感
//下一道,迟点在考虑加速的问题吧

/*
//看看别人的速度
//3MS 77.77%
class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> arr;
        for(auto i:num)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        string res;
        for(auto s:arr)
            res+=s;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return  res;
    }
};
*/
//和自己的思路完全相同,就是他对于库的使用相当熟练,而自己都用的自己手写的
//以后会进步吧

//36MS  0.94% 
int compare(int a, int b){                 //相当于>号
	stringstream input_one;
	input_one<<a;
	stringstream input_two;
	input_two<<b;
	string one = input_one.str();
	string two = input_two.str();
	if((one+two)>(two+one)){
		return a;
	}else{
		return b;
	}
}

int quicksort(vector<int>& data,int low,int high){
	int partition(vector<int>& data,int low,int high);
	if ((high-low)<1){
		return 0;
	}
	
	int middle=partition(data,low,high-1);
	quicksort(data,low,middle);
	quicksort(data,middle+1,high);
	return 0;
}

int partition(vector<int>& data,int low,int high){
	int backup_low=low;
	int backup_high=high;
	int middle_data=data[low];
	for(;low<high;){
		for(;low<high;){
			if(compare(data[high],middle_data)==data[high]){
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(compare(data[low],middle_data)==middle_data){     //这里原来写的有问题(算是没改好)if(compare(data[low],middle_data)==data[low]){
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

class Solution {
public:
    string largestNumber(vector<int>& nums) {
		quicksort(nums,0,nums.size());
		string result;
		for(int i = nums.size()-1; i>=0; --i){
			stringstream temp;
			temp<<nums[i];
			result += temp.str();
		}
		if(result[0]=='0'){         //这个没想到     不过出来后解决很简单
			return "0";
		}
		return result;
    }
};