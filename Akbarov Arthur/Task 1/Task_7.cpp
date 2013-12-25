#include "stdafx.h"

int main()
{
	int a, n, ans = 1;

	scanf_s ("%d%d", &a, &n);

	for (int i = 0; i < n; i++)
		ans = ans*a;

	printf ("%d\n", ans);

	return 0;
}