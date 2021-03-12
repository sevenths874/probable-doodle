class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int val = 0;
		for (auto e : nums) {
			val ^= e;
		}
		return val;
	}
};



class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int bitarray[32] = { 0 };
		//ͳ��n������32��λ�кϼ�1�ĸ���
		for (auto e : nums) {
			for (int i = 0; i<32; ++i) {
				if ((e >> i) & 1 == 1)
					++bitarray[i];
			}
		}
		//1�ĸ���Ϊ 3m ���� (3m+1)
		int val = 0;
		for (int i = 0; i<32; ++i) {
			if (bitarray[i] % 3 == 1)
				val |= (1 << i);
		}
		return val;
	}
};
