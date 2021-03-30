//4.链表的中间结点：
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
	ListNode* middleNode(ListNode* head) {
		//双指针
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
};

//5.删除链表的倒数第N个结点：
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//双指针,让fast先走n步，然后一起走，直到走到末尾
		//最后slow指向的是倒数第n个结点的**前一个结点**
		//如果fast先走n-1步，然后一起走，则最后slow指向的是倒数第n个结点
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* tmp = nullptr;
		if (head == nullptr)    //如果链表为空则返回
			return nullptr;
		while (n--)   //快指针先走n步
			fast = fast->next;
		while (fast && fast->next) {   //然后一起走
			slow = slow->next;
			fast = fast->next;
		}

		if (fast == nullptr) {  //如果删除的是第一个结点
			tmp = head;
			head = head->next;
			delete tmp;
		}
		else {  //如果删除的是其余结点
			tmp = slow->next;
			slow->next = tmp->next;
			delete tmp;
		}
		return head;
	}
};
