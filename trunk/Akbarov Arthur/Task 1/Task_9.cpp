#include "stdafx.h"

const int maxn = 10000;				// max number of elements in the array

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void qsort(int A[], int l, int r)
{
	int i = l;
	int j = r;
	int base = A[(l + r) / 2];
	
	while (i <= j)
	{
		while (A[i] < base)
			i++;	
		while (A[j] > base)
			j--;
		if (i <= j)
			swap(A[i++], A[j--]);
	}

	if (l < j)
		qsort(A, l, j);
	if (i < r)
		qsort(A, i, r);
}

int main()
{
	int n, A[maxn];

	scanf_s ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s ("%d", &A[i]);

	qsort(A, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf ("%d ", A[i]);
	printf ("\n");

	return 0;
}