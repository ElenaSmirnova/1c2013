#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

void BubbleSort(int *a, int n)
{
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++)
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
}

void CountingSort(int *a, int n)
{
	int *b = new int[100];
	for (int i = 0; i < 100; i++)
		b[i] = 0;
	for (int i = 0; i < n; i++)
		if (a[i] < 0 || a[i] >= 100)
		{
			printf("\nerror\n");
			getchar();
			getchar();
			getchar();
			getchar();
			getchar();
			getchar();
			getchar();
			exit(0);
		}
		else b[a[i]]++;
	for (int i = 0, j = 0; i < 100; j += b[i], i++)
		for (int k = 0; k < b[i]; k++)
			a[j + k] = i;
}

int main()
{
	int *a, *b;
	int n;
	printf("Write N from 1 to 1000000\n");
	scanf("%d", &n);
	printf("Write N integers from 0 to 99\n");
	if (n <= 0 || n > 1e6)
		return 0;
	a = new int[n];
	b = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), b[i] = a[i];
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	cout << endl;

	BubbleSort(a, n);
	printf("Bubble sort:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	CountingSort(b, n);
	printf("Counting sort:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", b[i]);
	printf("\n");

	delete[] a;
	delete[] b;

	getchar();
	getchar();
}