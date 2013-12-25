#include "stdafx.h"

int fibonacci(int n)
{	
	if ((n == 0) | (n == 1))
		return n;
	else
		if (n < 0)
			return n%2 == 0 ? fibonacci(-n) : -fibonacci(-n);
		else
			return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	int n;
	scanf_s ("%d", &n);

	printf ("F_%d = %d\n", n, fibonacci(n));

	return 0;
}
