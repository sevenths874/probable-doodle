//6.��ת����
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
		//ͷ�巨���õ�����
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

//7.�ϲ�������������
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
		ListNode* dummy = new ListNode(-1);  //����һ��ͷ���
		ListNode* pre = dummy;
		while (l1 && l2) {   //l1��l2����Ϊ��ʱ
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
		//�ϲ��� l1 �� l2 ���ֻ��һ����δ���ϲ��ֱ꣬�ӽ�����ĩβָ��δ�ϲ����������
		pre->next = (l1 == nullptr ? l2 : l1);
		return dummy->next;
	}
};
