//Фролов Алексей
#include "stdafx.h"
#include <iostream>

using namespace std;

int inBrow (int n,long int number)
{
	int temp = number;
	for (int i = 1; i < n; i++)
		number *= temp;
	
	return number;
}
int notInBrow (int n, long  int number)
{
	int temp = number;

	int i = 2;
	for (i = 2; i < n; i += i)
		number *= number;

	for (i = i / 2; i < n; i++)
		number *= temp;

	return number;
}
int main()
{
	long int number = 0;
	cout << "Enter number: " <<endl;
	cin >> number;

	int n = 0;
	cout << "Enter degree:" << endl;
	cin >> n;
	
	cout << inBrow(n, number) <<endl;
	cout << notInBrow(n, number) <<endl;

	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	return 0;
}

