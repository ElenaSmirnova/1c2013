#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

char s[1000000];

bool IsPalindrome(char *s)
{
	int n;
	for (n = 0; s[n]; n++);
	for (int i = 0; i + i < n - 1; i++)
		if (s[i] != s[n - 1 - i])
			return false;
	return true;
}

int main()
{
	scanf("%s", s);

	if (IsPalindrome(s))
		printf("yes\n");
	else
		printf("no\n");

	getchar();
	getchar();
}