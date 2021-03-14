class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;  //类对象数组

								 //开空间并且将每个数组第一个和最后一个置为1
		vv.resize(numRows);
		for (size_t i = 0; i<vv.size(); ++i) {
			vv[i].resize(i + 1);
			vv[i][0] = 1;
			vv[i][vv[i].size() - 1] = 1;
		}
		for (size_t i = 0; i<vv.size(); ++i) {
			for (size_t j = 0; j<vv[i].size(); ++j) {
				//每个数等于上一行和它下标相同的那个数+上一行和它下标相同的那个数的前一个数
				if (vv[i][j] != 1)
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
			}
		}
		return vv;
	}
};