// counting sort

#include "stdafx.h"

const int maxm = 10000;		// max value of elements

int main()
{
	int a, n, mass[maxm];
	for (int i = 0; i < maxm; i++)
		mass[i] = 0;
	
	scanf_s ("%d", &n);
		for (int i = 0; i < n; i++)
	{
		scanf_s ("%d", &a);
		mass[a]++;
	}

	for (int i = 0; i < maxm; i++)
		for (int j = 0; j < mass[i]; j++)
			printf ("%d ", i);
	printf("\n");
	
	return 0;
}