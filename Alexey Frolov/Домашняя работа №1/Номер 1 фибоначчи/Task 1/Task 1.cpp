//Фролов Алексей
#include "stdafx.h"
#include <iostream>

using namespace std;

int fibonacci(int n)
{
	if (n <= 1)
		return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}

int itFibonacci (int n)
{
	int a[3] = {0};
	a[0] = 1;
	a[1] = 1;
	for (int i = 1; i < n; i++)
	{
		a[(i + 1) % 3] = a[i % 3] + a[(i + 2) % 3];
	}
	return a[n % 3];
}

int main()
{
	int number = 0;
	cout << "Enter number of Fibonacci numeric: " << endl;
	cin >> number;
	cout << fibonacci(number) << endl;//Заметна пауза уже с 33-35
	cout << itFibonacci(number) << endl;//Работает мгновенно

	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	return 0;
}

