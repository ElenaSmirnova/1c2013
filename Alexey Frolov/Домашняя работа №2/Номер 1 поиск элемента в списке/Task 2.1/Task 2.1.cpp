// Task 2.1.cpp
//Фролов Алексей
#include "stdafx.h" 
#include <iostream>
#include "list.h"
#include <time.h>

using namespace std;

int main()
{
	srand(time(nullptr));
	
	int length = rand() % 50 + 1;

	int a = 0;
	cout << "Enter your favourite number from 0 to " << length - 1 << endl;
	cin >> a;

	List *list = create();
	for (int i = 0; i < length; i++)
	{
		insertToHead(list, rand() % 50);
	}

	print(list);
	cout << endl;

	cout << "This number:" << endl;
	printNumber(list, a);

	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	return 0;
}

