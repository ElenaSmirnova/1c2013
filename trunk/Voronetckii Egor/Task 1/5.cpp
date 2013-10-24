#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

const int N = 1e6;

char s[N];
char t[N];
int pi[N];

int KMP(char *s, char *t)
{
	int n;
	for (n = 0; s[n]; n++);
	s[n] = 1;
	int m;
	for (m = 0; t[m]; m++)
		s[n + m + 1] = t[m];
	pi[0] = 0;
	for (int i = 1; i < n + m + 1; i++)
	{
		pi[i] = 0;
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	int res = 0;
	for (int i = 0; i < m; i++)
		if (pi[i + n + 2] == n) res++;
	return res;
}

int main()
{
	// sample input
	scanf("%s", s);
	// string input
	scanf("%s", t);

	printf("%d\n", KMP(s, t));

	getchar();
	getchar();
}