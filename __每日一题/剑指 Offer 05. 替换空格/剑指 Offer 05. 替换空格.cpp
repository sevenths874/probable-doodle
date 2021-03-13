char* replaceSpace(char* s) {
	int n = 0;
	for (int i = 0; i<strlen(s); ++i) {
		if (s[i] == ' ')  ++n;
	}
	n = n * 2 + strlen(s);
	char* ss = (char*)malloc(n + 1);
	int i = 0, j = 0;
	while (i<strlen(s)) {
		if (s[i] == ' ') {
			ss[j++] = '%'; ss[j++] = '2'; ss[j++] = '0';
			++i;
		}
		else
			ss[j++] = s[i++];
	}
	ss[n] = '\0';
	return ss;
}
