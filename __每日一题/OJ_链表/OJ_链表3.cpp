//6.反转链表：
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
	ListNode* reverseList(ListNode* head) {
		//头插法逆置单链表
		ListNode* cur = head;
		ListNode* pre = nullptr;
		head = nullptr;
		while (cur != nullptr) {
			pre = cur;
			cur = cur->next;
			pre->next = head;
			head = pre;
		}
		return head;
	}
};

//7.合并两个有序链表：
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(-1);  //创建一个头结点
		ListNode* pre = dummy;
		while (l1 && l2) {   //l1和l2都不为空时
			if (l1->val<l2->val) {
				pre->next = l1;
				l1 = l1->next;
			}
			else {
				pre->next = l2;
				l2 = l2->next;
			}
			pre = pre->next;
		}
		//合并后 l1 和 l2 最多只有一个还未被合并完，直接将链表末尾指向未合并完的链表即可
		pre->next = (l1 == nullptr ? l2 : l1);
		return dummy->next;
	}
};
