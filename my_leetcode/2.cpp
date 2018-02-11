//这个也啥都没纪录  下次做再看看
// 52ms  34.31%
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int* array1 = new int[500];
		int* array2 = new int[500];
		int* output = new int[500];
		for(int i = 0; i<500; ++i){
			array1[i] = 0;
			array2[i] = 0;
			output[i] = 0;
		}
		int length1 = 0;
		int length2 = 0;
		//l1数组化
		while(l1->next!=NULL){
			array1[length1] = l1->val;
			length1 += 1;
			l1 = l1->next;
		}
		array1[length1] = l1->val;
		length1 += 1;
		//l2数组化
		while(l2->next!=NULL){
			array2[length2] = l2->val;
			length2 += 1;
			l2 = l2->next;
		}
		array2[length2] = l2->val;
		length2 += 1;
		//process
		if(length1>=length2){
		    int i =0;
			for(; i<length2; ++i){
				array1[i] += array2[i];
				array1[i+1] += (array1[i])/10;//进位
				array1[i] = (array1[i])%10;
			}
			while(array1[i]>=10){
			    array1[i+1] += (array1[i])/10;//进位
			    array1[i] = (array1[i])%10;
			    ++i;
			    if(i>=length1){
			        length1 = i+1;
			    }
			}
			ListNode* cck = new ListNode(array1[0]);
			ListNode* result = cck;
			for(int i = 1; (i<length1)||((i==length1)&&(array1[i] != 0)); ++i){
				result->next = new ListNode(array1[i]);
				result = result->next;
			}
			return cck;
		}
		if(length1<=length2){
		    int i =0;
			for(; i<length1; ++i){
				array2[i] += array1[i];
				array2[i+1] += (array2[i])/10;//进位
				array2[i] = (array2[i])%10;
			}
			while(array2[i]>=10){
			    array2[i+1] += (array2[i])/10;//进位
			    array2[i] = (array2[i])%10;
			    ++i;
			    if(i>=length2){
			        length2 = i+1;
			    }
			}
			ListNode* cck = new ListNode(array2[0]);
			ListNode* result = cck;
			for(int i = 1; (i<length2)||((i == length2)&&(array2[i] != 0)); ++i){
				result->next = new ListNode(array2[i]);
				result = result->next;
			}
			return cck;
		}
    }
};