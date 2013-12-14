//Фролов Алексей
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a = 0;
	cout << "Enter the number:" << endl;
	cin >> a;
	if (a >= 2) 
		cout << "2 ";
	for (int j = 2; j < a; j++)
	{
		for (int i = 2; i < sqrt(float(j)) + 1; i++)
		{
			if (j % i == 0) 
				break;
			if (i >= sqrt(float(j))) 
				cout << j << " ";
		}

	}
	cout << endl;

	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	return 0;
}

