#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

char str[1000];

bool digit(char c)
{
	return c >= '0' && c <= '9';
}

int main()
{
	//freopen("txt.in", "r", stdin);

	scanf("%s", str);
	int len;
	for (len = 0; str[len]; len++);

	int section = 0;
	int pos = 0;
	if (digit(str[0]))
		for (; pos < len; pos++)
		{
			if (str[pos] == 'E')
			{
				if (section == 2) break;
				section = 2;
				if (str[pos + 1] == '+' || str[pos + 1] == '-') pos++;
				if (!digit(str[pos + 1])) break;
			}
			else if (str[pos] == '.')
			{
				if (section != 0) break;
				section = 1;
				if (!digit(str[pos + 1])) break;
			}
			else if (!digit(str[pos])) break;
		}
	if (pos == len) printf("yes\n");
	else printf("no\n");

	getchar();
	getchar();

	return 0;
}