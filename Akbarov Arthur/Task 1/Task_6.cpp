#include "stdafx.h"

const int maxn=1000;							// maximum N

int main()
{
	int n, a[maxn + 1];
	
	scanf_s ("%d", &n);

	for (int i = 0; i <= n; i++)
		a[i] = 0;

	for (int p = 2; p <= n; p++)
		if (a[p] == 0)
		{
			printf ("%d ", p);
			for (int k = 2; k <= float(n/p); k++)
				a[k*p] = 1;
		}

	printf ("\n");

	return 0;
}