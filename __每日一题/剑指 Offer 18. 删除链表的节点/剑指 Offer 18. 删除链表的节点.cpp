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
	ListNode* deleteNode(ListNode* head, int val) {
		ListNode* cur = head;
		ListNode* pre = cur;
		while (cur != nullptr) {
			if (head->val == val) {
				head = cur->next;
				break;
			}
			if (cur->val == val) {
				pre->next = cur->next;
				break;
			}
			else {
				pre = cur;
				cur = cur->next;
			}
		}
		return head;
	}
};