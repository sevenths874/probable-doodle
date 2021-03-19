class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> st;   //辅助栈模拟进出 
		int pushi = 0, popi = 0;   //分别指向入栈和出栈序列
								   //当还有数据没入栈时
		while (pushi < pushed.size()) {
			st.push(pushed[pushi++]);  //后移
									   //当栈不空且栈顶元素等于出栈序列元素时，出栈
			while (!st.empty() && st.top() == popped[popi]) {
				st.pop();
				popi++;  //后移
			}
		}
		//如果辅助栈为空则为true，否则为false
		return st.empty();
	}
};
