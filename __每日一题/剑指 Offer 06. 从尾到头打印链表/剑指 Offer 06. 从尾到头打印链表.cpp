typedef struct ListNode ListNode;
int* reversePrint(struct ListNode* head, int* returnSize) {
	int len = 0;
	ListNode* cur = head;
	ListNode* tmp = NULL;
	head = NULL;
	while (cur) {
		tmp = cur;
		cur = cur->next;
		tmp->next = head;
		head = tmp;
		++len;
	}
	int* arr = (int*)malloc(sizeof(int)*len);
	int i = 0;
	cur = head;
	while (cur) {
		arr[i++] = cur->val;
		cur = cur->next;
	}
	*returnSize = len;
	return arr;
}
