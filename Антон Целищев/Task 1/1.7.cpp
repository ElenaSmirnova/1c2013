#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

int power (int a, int n)
{
	if (n == 0)
		return(1);
	if (n % 2 == 1)
		return(a * power(a, n - 1));
	if (n % 2 == 0)
	{
		int k = power(a, n / 2);
		return(k * k);
	}
}

int main()
{
	int a, n;
	printf("Print the base\n");
	scanf("%d", &a);
	printf("Print the power\n");
	scanf("%d", &n);
	printf("%d", power(a, n));
	getchar();
	getchar();
}








