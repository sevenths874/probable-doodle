class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		for (auto e : nums) {
			q.push(e);
		}
		//将前k-1个数据出队
		while (--k) {
			q.pop();
		}
		return q.top();
	}
	priority_queue<int> q;
};
