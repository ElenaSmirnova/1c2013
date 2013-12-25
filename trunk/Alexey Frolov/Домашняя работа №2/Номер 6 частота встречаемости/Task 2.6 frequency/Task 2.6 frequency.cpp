// Task 2.6 frequency
//Фролов Алексей
#include "stdafx.h"
#include <iostream>
#include "listPoint.h"
#include <time.h>

using namespace std;

struct Number
{
	int value;
	int frequency;
};

int main()
{
	srand(time(nullptr));

	ListPoint *list = create();
	
	int length = 0;
	cout << "Enter the size of list" << endl;
	cin >> length;

	for (int i = 0; i < length; i++)
		insertToHead(list, rand() % 20);

	printList(list);
	cout << endl;

	Number *array = new Number [length];

	PositionPoint position = head(list);
	array[0].value = returnValue(list, position);
	array[0].frequency = 1;
	position = next(list, position);
	int sizeOfArray = 1;
	while (position != nullptr)
	{
		for (int i = 0; i < sizeOfArray; i++)
		{
			if (returnValue(list, position) == array[i].value)
			{
				array[i].frequency++;
				break;
			}

			if (i == sizeOfArray - 1)
			{
				array[sizeOfArray].value = returnValue(list, position);
				array[sizeOfArray].frequency = 1;
				sizeOfArray++;
				break;
			}
		}
		position = next(list, position);
	}

	for (int i = 0; i < sizeOfArray; i++)
		cout << array[i].value << '(' << array[i].frequency << ')' << " ";
	cout << endl;
	
	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	return 0;
}

