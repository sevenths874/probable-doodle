class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;  //���������

								 //���ռ䲢�ҽ�ÿ�������һ�������һ����Ϊ1
		vv.resize(numRows);
		for (size_t i = 0; i<vv.size(); ++i) {
			vv[i].resize(i + 1);
			vv[i][0] = 1;
			vv[i][vv[i].size() - 1] = 1;
		}
		for (size_t i = 0; i<vv.size(); ++i) {
			for (size_t j = 0; j<vv[i].size(); ++j) {
				//ÿ����������һ�к����±���ͬ���Ǹ���+��һ�к����±���ͬ���Ǹ�����ǰһ����
				if (vv[i][j] != 1)
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
			}
		}
		return vv;
	}
};