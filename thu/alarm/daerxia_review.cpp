//对 回忆一下自己的做题思路(最近每做一题就把这个粘过去)
//1. 先理解题
//2. 确定解题思路(选择数据结构算法什么的)   确定能解决正常情况,也不用考虑太多复杂度
//3. 2达到之后, 开始考虑各种解决可能遇到的奇怪情况   然后看看有没有复杂度更低的思路

//看到这个题 就想起了归并排序,快速排序,二分查找.....感觉和哪个都有相似之处
//没错   就是分治法    这题简直就是分治法的经典应用    铭记

//这题还是略复杂的    第一次最终于15分停止
//周末休息了两天,入坑了王者荣耀玩了玩    
//然后周一中午拿纸画了画,理了下思路    很快找见一个漏洞(不知道不改会有什么后果,但知道改了更严谨,更加能处于控制之中)
//然后就改了,然后就从15分到了50分
//之前从->15也是发现了一个漏洞
//还是要养成好习惯吧    严谨一点  争取不是思路的漏洞   一遍过去最好
//这题就这样了
//
#include<cstdio>
#include<iostream>
using namespace std;
class Line{
public:
	long long int x;
	long long int y;
};

class Use_for_quicksort{
	public:
		int compare;
		long long int store_one;
		long long int store_two;
		int result;
};

int process(Use_for_quicksort* point, Line* line, int low, int high, int line_low, int line_high){
	int line_middle = (line_low+line_high)/2;
	int lef = low;
	int righ = high-1;
	Use_for_quicksort temp = point[righ];
	while(lef<righ){
		while(lef<righ){
			if(((line[line_middle].x)*(point[lef].store_two)+(line[line_middle].y)*(point[lef].store_one)-(line[line_middle].x)*(line[line_middle].y))<0){
				point[lef].result = line_middle;
				++lef;
			}else{
				point[lef].result = line_middle+1;
				point[righ] = point[lef];
				--righ;
				break;
			}
		}
		while(lef<righ){
			if(((line[line_middle].x)*(point[righ].store_two)+(line[line_middle].y)*(point[righ].store_one)-(line[line_middle].x)*(line[line_middle].y))>=0){
				point[righ].result = line_middle+1;
				--righ;
			}else{
				point[righ].result = line_middle;
				point[lef] = point[righ];
				++lef;
				break;
			}
		}
	}
	point[lef] = temp;
	if(((line[line_middle].x)*(point[lef].store_two)+(line[line_middle].y)*(point[lef].store_one)-(line[line_middle].x)*(line[line_middle].y))<0){
		point[lef].result = line_middle;
		if(line_middle==line_low){
			return 0;
		}
		process(point, line, low, lef+1, line_low, line_middle);
		if(lef!=high-1&&line_middle!=line_high-1){                                    //15->50
			process(point, line, lef+1, high, line_middle+1, line_high );
		}
		
	}else{
		point[lef].result = line_middle+1;
		if(line_middle==line_low){
			return 0;
		}
		if(righ!=low){
			process(point, line, low, lef, line_low, line_middle);
		}
		if(line_middle!=line_high-1){                                                 //15->50
			process(point, line, lef, high, line_middle+1, line_high );
		}
		
	}
	return 0;
}

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

int main(){
	//input
	int n;
	int m;
	fscanf(stdin,"%d %d",&n,&m);
	Line* line = new Line[100010];
	for(int i=0;i<n;++i){
		fscanf(stdin,"%lld %lld",&line[i].x,&line[i].y);
	}
	Use_for_quicksort* point = new Use_for_quicksort[1000010];
	for(int i=0;i<m;++i){
		point[i].compare = i;
		fscanf(stdin,"%lld %lld",&point[i].store_one,&point[i].store_two);
	}
	//process
	process(point, line, 0, m, 0, n);
	quicksort(point, 0, m);
	//output
	for(int i=0;i<m;++i){
		fprintf(stdout,"%d\n",point[i].result);
	}
	return 0;
}

