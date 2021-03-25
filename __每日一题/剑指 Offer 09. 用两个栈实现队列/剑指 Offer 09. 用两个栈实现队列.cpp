class CQueue {
public:
	CQueue() {

	}

	void appendTail(int value) {
		s_in.push(value);
	}

	int deleteHead() {
		if (s_out.empty()) {   //���ջs_outΪ�գ���ջs_in����
			while (!s_in.empty()) {
				s_out.push(s_in.top());
				s_in.pop();
			}
		}

		if (s_out.empty())
			return -1;
		int tmp = s_out.top();
		s_out.pop();
		return tmp;
	}

	stack<int> s_in, s_out;
};

/**
* Your CQueue object will be instantiated and called as such:
* CQueue* obj = new CQueue();
* obj->appendTail(value);
* int param_2 = obj->deleteHead();
*/