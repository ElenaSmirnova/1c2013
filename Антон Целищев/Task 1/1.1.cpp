#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

int FibRec(int n)
{	
	if (n == 1) return (1);
    else if (n == 0) return (0);
	else return (FibRec(n - 1) + FibRec(n - 2));
}

int FibIt(int n)
{
	int a, b, c;
	a = 0;
	b = 1;
	c = 1;
	if (n == 0) return (0);
	if (n == 1) return (1);
	if (n >= 2)
	{
		for (int i = 0; i < n - 2; i++)
		{
			a = b;
			b = c;
			c = a + b;
		}
		return(c);
	}
}

int main()
{
	int n = 0;
	printf("Print the number of Fibonacci number\n");
	scanf("%d", &n);
	printf("Recursively: " "%d", FibRec(n));
	printf("\n");
	printf("Iteratively: " "%d", FibIt(n));
	getchar();
	getchar();
}