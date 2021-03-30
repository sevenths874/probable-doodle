//4.������м��㣺
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
		//˫ָ��
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
};

//5.ɾ������ĵ�����N����㣺
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
		//˫ָ��,��fast����n����Ȼ��һ���ߣ�ֱ���ߵ�ĩβ
		//���slowָ����ǵ�����n������**ǰһ�����**
		//���fast����n-1����Ȼ��һ���ߣ������slowָ����ǵ�����n�����
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* tmp = nullptr;
		if (head == nullptr)    //�������Ϊ���򷵻�
			return nullptr;
		while (n--)   //��ָ������n��
			fast = fast->next;
		while (fast && fast->next) {   //Ȼ��һ����
			slow = slow->next;
			fast = fast->next;
		}

		if (fast == nullptr) {  //���ɾ�����ǵ�һ�����
			tmp = head;
			head = head->next;
			delete tmp;
		}
		else {  //���ɾ������������
			tmp = slow->next;
			slow->next = tmp->next;
			delete tmp;
		}
		return head;
	}
};
