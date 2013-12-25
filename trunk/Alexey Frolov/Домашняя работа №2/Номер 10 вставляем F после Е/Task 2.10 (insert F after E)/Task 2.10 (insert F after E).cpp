// Task 2.10 (insert F after E)
//Фролов Алексей
#include "stdafx.h"
#include <iostream>
#include "listPoint.h"
#include <time.h>

using namespace std;

int main()
{
	srand(time(nullptr));
	
	ListPoint *list = create();
	for (int i = 0; i < rand() % 15 + 1; i++)
		insertToHead(list, rand() % 10);

	cout << "This list:" << endl;
	printList(list);
	cout << endl;

	int E = 0;
	int F = 0;
	cout << "Enter E and F:" << endl;
	cin >> E >> F;

	PositionPoint position = head(list);
	
	while (position != nullptr)
	{
		if (returnValue(list, position) == E)
			insert(list, F, position);

		position = next(list, position);
	}

	cout << "This list:" << endl;
	printList(list);
	cout << endl;

	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	return 0;
}

