#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

int FibRecurse(int n)
{
	if (n < 2) return n;
	else return FibRecurse(n - 1) + FibRecurse(n - 2);
}

int FibIterate(int n)
{
	int *fib = new int[n + 1];

	fib[0] = 0, fib[1] = 1;
	for (int i = 2; i <= n; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	int res = fib[n];

	delete[] fib;
	return res;
}

int main()
{
	int time = clock();
	printf("%d\n", FibRecurse(37));
	printf("recursive time %d\n", clock() - time);
	time = clock();
	printf("%d\n", FibIterate(37));
	printf("iterative time%d\n", clock() - time);

	getchar();
	getchar();
}