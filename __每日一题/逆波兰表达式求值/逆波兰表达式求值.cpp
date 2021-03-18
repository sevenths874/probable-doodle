class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;  //存放操作数  
		int i = 0;
		while (i < tokens.size()) {
			//如果是操作符，则将栈顶元素和它的后一个元素出栈(先出栈的位右操作数)，然后将计算结果入栈
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
				int right = st.top();  st.pop();
				int left = st.top();  st.pop();
				if (tokens[i] == "+")  st.push(left + right);
				else if (tokens[i] == "-")  st.push(left - right);
				else if (tokens[i] == "*")  st.push(left*right);
				else if (tokens[i] == "/")  st.push(left / right);
			}
			//如果是操作数，则入栈
			else
				st.push(stoi(tokens[i]));
			++i;
		}
		return st.top();  //返回栈顶元素
	}
};

