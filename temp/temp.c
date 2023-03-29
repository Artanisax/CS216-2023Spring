#include <stdio.h>
#include <string.h>

int main() {
	int a[26] = {0};
	char b[100], c[100];
	gets(b);
	gets(c);
	int len = strlen(b), l = strlen(c);
	if (len != l)
	{
		printf("The words are not anagrams.");
		return 0;
	}
	for (int i = 0; i < len; i++)
	{
		a[b[i]-'a'] += 1;
		a[c[i]-'a'] -= 1;
	}
	for (int i = 0; i < 26; i++)
		if (a[i])
		{
			printf("The words are not anagrams.");
			return 0;
		}
	printf("The words are anagrams.");
	return 0;
}
