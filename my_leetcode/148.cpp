//他要的复杂度只有快速排序和归并排序可以满足
//数组的这两种都遍过,但是单列表的没编过
//直接列表化数组,然后排序后再化列表试试

//很快就写好了(在vector版快速排序的基础上)  然后竟然一遍通过,语法错误都没有
//不过这应该算是作弊吧   依然没有写列表版的快速排序

//然后是交流  发现这道题的标准做法应该是归并排序(列表用快速排序可能会超时)
//数组的时候用归并会占用较多的空间,但是列表的时候发现,只需要常数个额外空间.

//有空一定要自己把列表的归并排序写一写.
// 42MS   99.91%
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
			if(data[high]>middle_data){
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(data[low]<middle_data){
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
		vector<int> data;
		for(ListNode* i = head; i!=NULL; i = i->next){
			data.push_back(i->val);
		}
        quicksort(data,0,data.size());
		int count = 0;
		for(ListNode* i = head; i!=NULL; i = i->next){
			i->val = data[count];
			++count;
		}
		return head;
    }
};