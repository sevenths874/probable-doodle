class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		for (auto e : nums) {
			q.push(e);
		}
		//��ǰk-1�����ݳ���
		while (--k) {
			q.pop();
		}
		return q.top();
	}
	priority_queue<int> q;
};
