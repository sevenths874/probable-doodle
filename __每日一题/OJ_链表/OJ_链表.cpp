//1.环形链表1：
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
	bool hasCycle(ListNode *head) {
		//快慢指针
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next) {
			fast = fast->next->next;   //快指针一次走两步
			slow = slow->next;  //慢指针一次走一步
			if (fast == slow)   //如果有环一定会相遇
				return true;
		}
		return false;
	}
};

//2.环形链表2：
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
	ListNode *detectCycle(ListNode *head) {
		//快慢指针,公式法
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {  //相遇后，确定入环结点
				ListNode* meet = slow;
				ListNode* cur = head;
				//找到入环结点：如图所示，因为 L=C-X，所以meet和cur会走相同的距离，一定会在入环点相遇
				while (meet != cur) {
					cur = cur->next;
					meet = meet->next;
				}
				return cur;
			}
		}
		return nullptr;
	}
};

//3.相交链表：
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//双指针：找到两个链表的尾结点，若两个尾结点的地址相等(比较的是地址)，则一定相交
		ListNode* curA = headA;
		ListNode* curB = headB;
		int lenA = 0, lenB = 0;
		if (headA == nullptr || headB == nullptr)
			return nullptr;
		while (curA && curA->next) {
			++lenA;
			curA = curA->next;
		}
		while (curB && curB->next) {
			++lenB;
			curB = curB->next;
		}
		if (curA != curB)
			return nullptr;
		else {
			ListNode* longlist = headA;  //找到长的链表
			ListNode* shortlist = headB;
			if (lenA<lenB) {
				longlist = headB;
				shortlist = headA;
			}
			int gap = abs(lenA - lenB);
			while (gap--)    //长的链表先走gap步
				longlist = longlist->next;
			while (longlist != shortlist) {   //然后一起走，直到相遇
				longlist = longlist->next;
				shortlist = shortlist->next;
			}
			return longlist;
		}
	}
};
