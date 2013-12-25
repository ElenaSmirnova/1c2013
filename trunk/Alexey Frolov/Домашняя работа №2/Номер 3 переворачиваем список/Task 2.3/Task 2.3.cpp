// Task 2.3.cpp
//Фролов Алексей
#include "stdafx.h"
#include <iostream>
#include "list.h"
#include <time.h>

using namespace std;

int main()
{
	srand(time(nullptr));

	List *list = create();
	int length = rand() % 10 + 3;

	int *mas = new int [length];

	for (int i = 0; i < length; i++)
	{
		int temp = rand() % 50;
		insertToHead(list, temp);
		mas[i] = temp;
	}

	cout << "list: ";
	print(list);
	cout << endl;

	removeList(list);

	for (int i = length - 1; i >= 0; i--)
		insertToHead(list, mas[i]);
	
	cout << "new list: ";
	print(list);
	cout << endl;


	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	delete []mas;
	removeList(list);
	delete list;
	return 0;
}

