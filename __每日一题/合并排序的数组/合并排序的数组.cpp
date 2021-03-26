class Solution {
public:
	void merge(vector<int>& A, int m, vector<int>& B, int n) {
		//ÄæÏòË«Ö¸Õë
		int i = m - 1;  int j = n - 1;
		int max = m + n - 1;
		while (i >= 0 && j >= 0) {
			if (A[i]>B[j]) {
				A[max] = A[i];
				--i;
				--max;
			}
			else {
				A[max] = B[j];
				--j;
				--max;
			}
		}
		while (j >= 0) {
			A[max] = B[j];
			--j;
			--max;
		}
	}
};