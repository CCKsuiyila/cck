//大二寒假复习2017.2.13

//最简单的思路60-C输入60-C输出100
#include<iostream>
#include<cstdio>
using namespace std;

class Use_for_quicksort{
	public:
		int compare;
		int store_one;
};

//二分查找
int lef_binary_search(Use_for_quicksort *data,int low,int high
,int be_searched){
	
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
			return middle;
		}
	}
	if(be_searched>data[low].compare){
		return low+1;
	}else{
		return low;
	}
}

int righ_binary_search(Use_for_quicksort *data,int low,int high
,int be_searched){
	
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
			return middle;
		}
	}
	if(be_searched<data[low].compare){
		return low-1;
	}else{
		return low;
	}
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
	
	//input of the first line
	int n,m;
	//cin>>n>>m;
	fscanf(stdin, "%d %d", &n, &m);
	//input of the second line
	Use_for_quicksort* array = new Use_for_quicksort [500100];
	for(int i = 0; i < n; ++i){
		//cin>>array[i].compare;
		fscanf(stdin, "%d", &(array[i].compare));
	}
	//change this detail for the test data
	array[n].compare = 10000002;
	//input of the m line
	int* lef = new int [500100];
	int* righ = new int [500100];
	for(int i = 0; i < m; ++i){
		//cin>>lef[i]>>righ[i];
		fscanf(stdin, "%d %d", &(lef[i]), &(righ[i]));
	}
	
	//sort the array
	quicksort(array,0,n);
	
	//process
	for(int i = 0; i < m; ++i){
		int lef_index = lef_binary_search(array, 0, n, lef[i]);
		int righ_index = righ_binary_search(array, 0, n, righ[i]);
		//cout<<(righ_index - lef_index + 1)<<endl;
		fprintf(stdout, "%d\n", (righ_index - lef_index + 1));
	}
	return 0;
}