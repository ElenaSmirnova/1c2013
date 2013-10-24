#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

void SortByFirst(int *a, int n)
{
	int base = 0;
	int i = 0, j = n - 1;
	while (true)
	{
		while (a[i] < a[base] && i < n) i++;
		while (a[j] > a[base] && j >= 0) j--;
		if (i < j)
		{
			swap(a[i], a[j]);
			if (base == i) base = j;
			else if (base == j) base = i;
		}
		else break;
	}
}

int main()
{
	int *a, *b;
	int n;
	rand();
	scanf("%d", &n);
	if (n <= 0 || n > 1e6)
		return 0;
	a = new int[n];

	for (int i = 0; i < n; i++)
		a[i] = rand();
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	SortByFirst(a, n);

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	delete[] a;

	getchar();
	getchar();
}