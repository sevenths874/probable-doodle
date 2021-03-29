//1.��������1��
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
		//����ָ��
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next) {
			fast = fast->next->next;   //��ָ��һ��������
			slow = slow->next;  //��ָ��һ����һ��
			if (fast == slow)   //����л�һ��������
				return true;
		}
		return false;
	}
};

//2.��������2��
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
		//����ָ��,��ʽ��
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {  //������ȷ���뻷���
				ListNode* meet = slow;
				ListNode* cur = head;
				//�ҵ��뻷��㣺��ͼ��ʾ����Ϊ L=C-X������meet��cur������ͬ�ľ��룬һ�������뻷������
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

//3.�ཻ����
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
		//˫ָ�룺�ҵ����������β��㣬������β���ĵ�ַ���(�Ƚϵ��ǵ�ַ)����һ���ཻ
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
			ListNode* longlist = headA;  //�ҵ���������
			ListNode* shortlist = headB;
			if (lenA<lenB) {
				longlist = headB;
				shortlist = headA;
			}
			int gap = abs(lenA - lenB);
			while (gap--)    //������������gap��
				longlist = longlist->next;
			while (longlist != shortlist) {   //Ȼ��һ���ߣ�ֱ������
				longlist = longlist->next;
				shortlist = shortlist->next;
			}
			return longlist;
		}
	}
};
