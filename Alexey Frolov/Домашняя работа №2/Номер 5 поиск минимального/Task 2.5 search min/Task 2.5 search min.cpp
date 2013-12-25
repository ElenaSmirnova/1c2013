// Task 2.5
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
	
	int length = 0;
	cout << "Enter the size of list" << endl;
	cin >> length;

	for (int i = 0; i < length; i++)
		insertToHead(list, rand() % 20);

	printList(list);
	cout << endl;

	cout << "minimum: " << searchMin(list) << endl;

	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	return 0;
	return 0;
}

