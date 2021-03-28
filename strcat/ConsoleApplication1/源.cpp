#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//char* my_strcat(char* dst, char* src)
//{
//	assert(dst && src);
//	int len = strlen(src)+strlen(dst)+1;
//	char* p = (char*)malloc(sizeof(char)*len);
//	strcpy(p, dst);
//	dst = p;
//	p += strlen(dst);
//	while (*p++ = *src++);
//	return dst;
//}

char* my_strcat(char* dst, const char* src)
{
	assert(dst && src);
	char* p = dst;
	while (*p) ++p;
	while (*p++ = *src++);
	return dst;
}

void reverse(char* str)
{
	char* sstr = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(sstr, str);
	int len = strlen(sstr);
	int low = 0;
	int high = len - 1;
	while (low < high)
	{
		char tmp = sstr[low];
		sstr[low] = sstr[high];
		sstr[high] = tmp;
		low++;
		high--;
	}
	printf("%s\n", sstr);
}


int main()
{
	/*char a[] = "abcd";
	char b[] = "efg";
	char* p = my_strcat(a, b);
	printf("%s\n", p);*/

	/*char* a = "abcdef";
	reverse("abcdef");*/

	char a[20] = "abcde";
	char* b = "fgh";
	my_strcat(a, b);
	printf("%s\n", a);

	system("pause");
	return 0;

}