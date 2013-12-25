#include "stdafx.h"

int fibonacci(int n)
{	
	int a, b;
	a = 0;
	b = 1;

	if (n >= 0)
		for (int i = 0; i < n; i++)
		{
			b = a + b;
			a = b - a;
		}
	else
		for (int i = 0; i > n; i--)
		{
			a = b - a;
			b = b - a;
		}
	
	return a;
}

int main()
{
	int n;
	scanf_s ("%d", &n);

	printf ("F_%d = %d\n", n, fibonacci(n));

	return 0;
}
