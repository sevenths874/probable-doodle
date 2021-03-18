class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;  //��Ų�����  
		int i = 0;
		while (i < tokens.size()) {
			//����ǲ���������ջ��Ԫ�غ����ĺ�һ��Ԫ�س�ջ(�ȳ�ջ��λ�Ҳ�����)��Ȼ�󽫼�������ջ
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
				int right = st.top();  st.pop();
				int left = st.top();  st.pop();
				if (tokens[i] == "+")  st.push(left + right);
				else if (tokens[i] == "-")  st.push(left - right);
				else if (tokens[i] == "*")  st.push(left*right);
				else if (tokens[i] == "/")  st.push(left / right);
			}
			//����ǲ�����������ջ
			else
				st.push(stoi(tokens[i]));
			++i;
		}
		return st.top();  //����ջ��Ԫ��
	}
};

