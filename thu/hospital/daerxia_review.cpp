//这次看了提示,先想到了quicksort+leetcode里面的那个去重题,然后看了下面的数据大小又想到了hash,都试试吧

/*
//hash
//   	2017-02-28 16:37:05	     40.0/50.0	
#include<iostream>
#include<cstdio>
using namespace std;

class Use_for_quicksort{
	public:
		int compare;
		int store_one;
};

int main(){
	//申请hash表
	Use_for_quicksort* hash = new Use_for_quicksort[32770];
	for(int i = 0; i<32770; ++i){
		hash[i].compare = 38000;
		hash[i].store_one = 0;
	}
	//直接输入hash表
	int n;
	fscanf(stdin,"%d",&n);
	int a;
	int b;
	for(int i=0;i<n;++i){
		fscanf(stdin,"%d %d",&a,&b);
		hash[a].compare = a;
		hash[a].store_one += b;
	}
	//process
	long long int less = 1000000000000000000;
	int best;
	long long int temporary=0;
	for(int i = 0;i<=32767;++i){
		if(hash[i].compare!=38000){
			for(int j=0;j<i;++j){
				if(hash[j].compare!=38000){
					temporary += (i-j)*hash[j].store_one;
				}
			}
			for(int j=i+1;j<=32767;++j){
				if(hash[j].compare!=38000){
					temporary += (j-i)*hash[j].store_one;
				}
			}
			if(temporary<less){
				less=temporary;
				best = i;
			}
			temporary=0;
		}
	}
	fprintf(stdout,"%d\n",best);
	fprintf(stdout,"%lld",less);
	return 0;
}
*/



 
//来吧quicksort+leetcode
//这个不去重的话,很快就写好了  但是后来写去重  花了好久    看来从一个已有的改也是挺麻烦的   
//不过去重后果然运行时间减少好多,虽然还是没过最后一组  

//	2017-02-28 19:41:54     45.0/50.0
#include<iostream>
#include<cstdio>
using namespace std;

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

int removeDuplicates(Use_for_quicksort* nums, int size){
        if(size < 2){
			return 0;
		}
		int temporary = nums[0].compare;
		int temporary_index = 0;
		int length = size;
		int null_index=0;
		for(int i = 1; i<size; ++i){
			if(nums[i].compare==temporary){
				length = length-1;
				nums[i].compare = -100;
				nums[temporary_index].store_one += nums[i].store_one;
			}else{
				temporary = nums[i].compare;
				temporary_index = i;
				int j = null_index;
				for(;j<i;++j){
				    if(nums[j].compare==-100){
				        nums[j].compare=nums[i].compare;
						nums[j].store_one=nums[i].store_one;
						temporary_index = j;
						nums[i].compare = -100;
				        null_index = j+1;
				        break;
				    }
				}
			}
		}
		return length;
}
	
int main(){
	//input
	int n;
	fscanf(stdin,"%d",&n);
	Use_for_quicksort* array = new Use_for_quicksort[n+10];
	for(int i=0;i<n;++i){
		fscanf(stdin,"%d %d",&(array[i].compare),&(array[i].store_one));
	}
	quicksort(array,0,n);
	//不去重45   去个重看看   
	n = removeDuplicates(array,n);
	//process
	long long int less = 1000000000000000000;
	int best;
	long long int temporary=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<i;++j){
			temporary += (array[i].compare-array[j].compare)*array[j].store_one;
		}
		for(int j=i+1;j<n;++j){
			temporary += (array[j].compare-array[i].compare)*array[j].store_one;
		}
		if(temporary<less){
			less=temporary;
			best=array[i].compare;
		}
		temporary=0;
	}
	fprintf(stdout,"%d\n",best);
	fprintf(stdout,"%lld",less);
	return 0;
}
