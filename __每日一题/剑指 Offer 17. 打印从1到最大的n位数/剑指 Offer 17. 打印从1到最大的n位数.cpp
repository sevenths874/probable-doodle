class Solution {
public:
	vector<int> printNumbers(int n) {
		vector<int> v;
		// int sum=0;
		// while(--n)
		//     sum+=(pow(10,n)*9);
		// sum+=9;
		int sum = pow(10, n) - 1;
		for (int i = 1; i <= sum; ++i)
			v.push_back(i);
		return v;
	}
};
