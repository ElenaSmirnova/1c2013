#include "stdafx.h"
#include "stdlib.h"

const int n=9;							// number of elements in the array

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int main()
{
	int mass[n];
	for (int i = 0; i < n; i++)
		mass[i] = rand();

	for (int i = 0; i < n; i++)
		printf ("%d ", mass[i]);
	printf("\n");	


	int base = 0;						// base element index
	int index = n - 1;					// boundary index of elements > base element
	int value = mass[base];				// value of base element
		
	for (int i = 1; i < n; i++)
		if (mass[i] > value)	
			swap(mass[i], mass[index--]);
	swap(mass[base], mass[index]);

	for (int i = 0; i < n; i++)
		printf ("%d ", mass[i]);
	printf ("\n");
	
	return 0;
}