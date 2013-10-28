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

	if (p < 0 && n != 1 && n != -1)
		printf("power is less than zero\n");
	else if (p < 0)
		printf("%d\n", power(n, -p));
	else if (power(n, p) == 0 && n != 0)
		printf("answer is very big\n");
	else
		printf("%d\n", power(n, p));

	getchar();
	getchar();
}