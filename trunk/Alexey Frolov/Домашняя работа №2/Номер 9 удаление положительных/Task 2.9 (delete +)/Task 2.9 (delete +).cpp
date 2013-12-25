// Task 9
//Фролов Алексей
#include "stdafx.h"
#include <iostream>
#include "listPoint.h"
#include <time.h>

using namespace std;

int main()
{
	srand(time(nullptr));

	ListPoint *L = create();
	for (int i = 0; i < rand() % 15 + 1; i++)
		insertToHead(L, rand() % 50 - 25);

	cout << "This list:" << endl;
	printList(L);
	cout << endl;

	
	while (returnValue(L, head(L)) > 0)
		removeHead(L);

	PositionPoint position = head(L);

	while (next(L, position) != nullptr)
	{
		if (returnValue(L, next(L, position)) > 0)
			remove(L, position);
		else
			position = next(L, position);
	}
	cout << "This list without positive elements:" << endl;
	printList(L);
	cout << endl;

	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	return 0;
}

