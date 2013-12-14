//Фролов Алексей
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include "time.h"

using namespace std;

int main()
{
	srand(time(NULL));

	int length = 0;
	cout << "Enter the length of the array:" << endl;
	cin >> length;

	int *a = new int [length];
	for (int i = 0; i < length; i++)
	{
		a[i] = rand() % 50;
		cout << a[i] << " ";
	}
	cout << endl;

	int neutral = a[0];
	int i = 0;
	int j = length - 1;
	int temp = 0;

	while (i <= j)
	{
		while (neutral > a[i] && i < length)
			i++;
		while (neutral <= a[j] && j >= 0)
			j--;
		if (i <= j)
		{
			temp = a[i];
			a[i] = a[j] ;
			a[j] = temp;
			i++;
			j--;
		}
	}

	for (i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;

	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	delete[] a;
	return 0;
}

