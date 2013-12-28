#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

void BubSort(int a[100], int n)
{
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++)
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
}

void CountSort(int a[100], int n)
{
	int b[100];
	for (int i = 0; i < 100; i++)
		b[i] = 0;

	for (int i = 0; i < n; i++)
		b[a[i]]++;
	int k = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < b[i]; j++)
		{
			a[k] = i;
			k++;
		}
}

int main()
{
	int a[100], c[100];
	int n;
	printf("Print the length of the array\n");
	scanf("%d", &n);

	printf("Print the array\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++)
		c[i] = a[i];

	printf("Bubble sort ");
	BubSort(a, n);

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
	printf("Counting sort ");
	CountSort(c, n);

	for (int i = 0; i < n; i++)
		printf("%d ", c[i]);

	getchar();
	getchar();
}