#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

void Erat (int n)
{
	bool p[10000];
	for (int i = 2; i <= n; i++)
		p[i] = true;
	p[0] = false;
	p[1] = false;
	for (int i = 2; i <= n; i++)
		if (p[i])
		{
			for (int j = i; i * j <= n; j++)
				p[i * j] = false;
			printf("%d", i);
			printf("\n");
		}
}

int main()
{
	int n;
	printf("Print the natural number\n");
	scanf("%d", &n);
	Erat(n);

	getchar();
	getchar();
}










