//Фролов Алексей
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	char str[1000];
	cout << "Enter str:" << endl;
	gets(str);

	char str1[1000];
	cout << "Enter str1:" << endl;
	gets(str1);

	int count = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j < strlen(str1); j++)
		{
			if (str1[j] != str[i + j])
				break;

			if (j == strlen(str1) - 1)
				count++;
		}
	}

	cout << count << endl;

	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	return 0;
}