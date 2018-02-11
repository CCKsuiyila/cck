//感觉也不是很难的样子    偷懒一下,直接上手敲吧
//很快敲出来,改了一下小错误,就很愉快的accept了
//论基础扎实的重要性
//而且这个题还是原地排序的,没有借用外部储存空间
//49MS   58.69%
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
    ListNode* insertionSortList(ListNode* head) {
		if(head==NULL||head->next==NULL){
			return head;
		}
		ListNode* current = head->next;
		ListNode* head_sorted = head;
		head_sorted->next = NULL;
		for(;current!=NULL;){
			ListNode* temp = current;
			current = current->next;			//
			if(temp->val<head_sorted->val){
				temp->next = head_sorted;
				head_sorted = temp;
				continue;
			}
			ListNode* i = head_sorted;
			for(;i->next!=NULL&& i->next->val< temp->val; i = i->next);
			temp->next = i->next;
			i->next = temp;
		}
		return head_sorted;
    }
};