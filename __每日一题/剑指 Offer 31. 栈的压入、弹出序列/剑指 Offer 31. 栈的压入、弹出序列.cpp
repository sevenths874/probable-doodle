class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> st;   //����ջģ����� 
		int pushi = 0, popi = 0;   //�ֱ�ָ����ջ�ͳ�ջ����
								   //����������û��ջʱ
		while (pushi < pushed.size()) {
			st.push(pushed[pushi++]);  //����
									   //��ջ������ջ��Ԫ�ص��ڳ�ջ����Ԫ��ʱ����ջ
			while (!st.empty() && st.top() == popped[popi]) {
				st.pop();
				popi++;  //����
			}
		}
		//�������ջΪ����Ϊtrue������Ϊfalse
		return st.empty();
	}
};
