//Фролов Алексей
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int sizeOfNumber = 50;

void sortingBubble(int x[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (x[j] > x[j + 1])
			{
				int temp = 0;
				temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
		}
	}
}

void sorting(int x[], int length)//пусть элементы массива от 0 до sizeOfNumber;
{
	int *a = new int [sizeOfNumber];
	for (int i = 0; i < sizeOfNumber; i++)
		a[i] = 0;

	for (int i = 0; i < length; i++)
		a[x[i]]++;

	int k = 0;
	for (int i = 0; i < sizeOfNumber; i++)
	{
		for (int j = 0; j < a[i]; j++)
		{
			x[k] = i;
			k++;
		}
	}
	delete[] a;
}

void fillingArray(int a[], int length)
{
	for (int i = 0; i < length; i++)
		a[i] = rand() % sizeOfNumber;
}

void outArray(int a[], int length)
{
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	srand(time(NULL));

	int length = 0;
	cout << "Enter the length of the array:" << endl;
	cin >> length;

	int *a = new int [length];
	cout << "This first array:" << endl;
	fillingArray(a, length);
	outArray(a, length);

	sortingBubble(a, length);
	cout << "This sorted (bubble) array:" << endl;
	outArray(a, length);

	cout << "This second array:" << endl;
	fillingArray(a, length);
	outArray(a, length);

	cout << "This sorted () array:" << endl;
	sorting(a, length);
	outArray(a, length);

	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	delete[] a;
	return 0;
}