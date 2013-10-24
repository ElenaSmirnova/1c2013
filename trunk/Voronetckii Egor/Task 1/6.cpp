#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

int PrimeCnt(int n)
{
	bool *prime = new bool[n + 1];
	for (int i = 0; i <= n; i++) prime[i] = true;
	int res = 0;
	for (int i = 2; i <= n; i++)
		if (prime[i])
		{
			res++;
			for (int j = i; (long long)i * j <= n; j++)
				prime[i * j] = false;
		}
	return res;
}

int main()
{
	int n;
	scanf("%d", &n);
	if (n <= 1) printf("0\n");
	else if (n > 1e7) printf("many\n");

	printf("%d\n", PrimeCnt(n));

	getchar();
	getchar();
}