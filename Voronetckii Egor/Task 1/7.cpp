#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

int power(int n, int p)
{
	int res = 1;
	while (p)
	{
		if (p % 2 == 1)
		{
			if (abs((long long)res * n) < 2e9)
				res *= n;
			else res = 0;
		}
		if ((long long)n * n < 2e9)
			n *= n;
		else res = 0;
		p /= 2;
	}
	return res;
}

int main()
{
	int n, p;
	scanf("%d%d", &n, &p);

	printf("%d\n", power(n, p));

	getchar();
	getchar();
}