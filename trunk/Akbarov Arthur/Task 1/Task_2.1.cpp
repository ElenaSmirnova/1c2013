// bubble sort

#include "stdafx.h"

const int maxn = 10000;			// max number of elements in the array

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int main()
{
	int n, mass[maxn];
	scanf_s ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s ("%d", &mass[i]);

	bool a;						// true <=> были инверсии
	do
	{
		a = 1;
		for (int j = 0; j + 1 < n; ++j)
			if (mass[j] > mass[j + 1])
			{
				swap(mass[j], mass[j + 1]);
				a = 0;
			}
	}
	while (!a);

	for (int k = 0; k < n; k++)
		printf("%d ", mass[k]);
	printf ("\n");
	
	return 0;
}