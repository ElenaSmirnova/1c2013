//Фролов Алексей
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void insert(int a[], int begin, int end)
{
	for (int i = begin + 1; i < end; i++)
	{
		for (int j = i; j > 0 && a[j - 1] > a[j]; j--)
		{
			int temp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = temp;
		}
	}
}

void qSort(int a[], int begin, int end)
{
    int i = begin;
	int j = end;

	int neutral = 0;
	bool temp1 = 1;
	while (temp1)
	{
		if (a[begin] > a[begin + 1])
		{
			neutral = a[begin];
			temp1 = 0;
		}
		else if (a[begin] < a[begin + 1])
		{
			neutral = a[begin + 1];
			temp1 = 0;
		}
		else
			begin++;
	}
 
    do 
	{
        while (a[i] < neutral) i++;
        while (a[j] > neutral) j--;
 
        if(i <= j) 
		{
			int temp = 0;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
 
    if (i < end && (end - i) > 10)
        qSort(a, i, end);
	else if ((end - i) <= 10)
		insert(a, i, end + 1);
    if (begin < j && (j - begin) > 10)
        qSort(a, begin,j);
	else if ((j - begin) <= 10)
		insert(a, begin, j + 1);
}

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

	qSort(a, 0, length - 1);

	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;

	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	delete[] a;
	return 0;
}