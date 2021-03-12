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
		//统计n个数中32个位中合计1的个数
		for (auto e : nums) {
			for (int i = 0; i<32; ++i) {
				if ((e >> i) & 1 == 1)
					++bitarray[i];
			}
		}
		//1的个数为 3m 或者 (3m+1)
		int val = 0;
		for (int i = 0; i<32; ++i) {
			if (bitarray[i] % 3 == 1)
				val |= (1 << i);
		}
		return val;
	}
};
