#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;
int fibrec(int n)
{
	if (n < 2) return n;
	else return fibrec(n - 1) + fibrec(n - 2);
}
int fibit(int n)
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
{cin>>n
		printf("%d", fibrec(n));
	printf(" ");
				printf("%d", fibit(n));	
}
