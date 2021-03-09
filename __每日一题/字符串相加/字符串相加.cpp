class Solution {
public:
	string addStrings(string num1, string num2) {
		int end1 = num1.size() - 1, end2 = num2.size() - 1;
		int val1 = 0, val2 = 0, next = 0;   //val1/val2���ڽ����ַ���ÿһλ�ϵ�����,next��ʾ��λ
		string retstr;
		while (end1 >= 0 || end2 >= 0) {   //ֱ�������ַ�������������
			if (end1 >= 0)
				val1 = num1[end1--] - '0';
			else
				val1 = 0;
			if (end2 >= 0)
				val2 = num2[end2--] - '0';
			else
				val2 = 0;
			int ret = val1 + val2 + next;
			if (ret>9) {
				ret -= 10;
				next = 1;
			}
			else
				next = 0;
			retstr += (ret + '0');   //β��
		}
		if (next == 1)
			retstr += '1';
		reverse(retstr.begin(), retstr.end());   //����
		return retstr;
	}
};
