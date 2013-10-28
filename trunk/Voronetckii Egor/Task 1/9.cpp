#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

void QuickSort(int *a, int n)
{
	if (n < 2) return;

	int base = 0;
	int i = 0, j = n - 1;
	while (true)
	{
		while (a[i] < a[base] && i < n) i++;
		while (a[j] > a[base] && j >= 0) j--;
		if (i < j && a[i] > a[j])
		{
			swap(a[i], a[j]);
			if (base == i) base = j;
			else if (base == j) base = i;
		}
		else break;
	}

	QuickSort(a, base);
	QuickSort(a + base + 1, n - base - 1);
}

int main()
{
	int *a, *b;
	int n;
	printf("write N from 1 to 1000000\n");
	scanf("%d", &n);
	printf("write N integers\n");
	if (n <= 0 || n > 1e6)
		return 0;
	a = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	QuickSort(a, n);

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	delete[] a;

	getchar();
	getchar();
}