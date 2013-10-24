#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

char s[1000000];

bool test(char *s)
{
	int cnt = 0;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '(') cnt++;
		else if (s[i] == ')') cnt--;
		if (cnt < 0) return false;
	}
	return cnt == 0;
}

int main()
{
	scanf("%s", s);

	if (test(s)) printf("yes\n");
	else printf("no\n");

	getchar();
	getchar();
}