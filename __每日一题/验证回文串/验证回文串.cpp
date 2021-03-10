class Solution {
public:
	//ÅÐ¶ÏÊÇ·ñÊÇ×ÖÄ¸ºÍÊý×Ö×Ö·û
	bool isCharorNums(char c) {
		if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
			return true;
		return false;
	}
	bool isPalindrome(string s) {
		//½«´óÐ´×ÖÄ¸×ªÎªÐ¡Ð´×ÖÄ¸
		for (auto& ch : s) {
			if (ch >= 'A' && ch <= 'Z')
				ch += 32;
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin<end) {
			while (begin<end && !isCharorNums(s[begin]))
				++begin;
			while (begin<end && !isCharorNums(s[end]))
				--end;
			if (s[begin] == s[end]) {
				++begin;
				--end;
			}
			else
				return false;
		}
		return true;
	}
};
