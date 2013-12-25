// Task 2
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
	for (int i = 0; i < rand() % 15 + 1; i++)
		insertToHead(list, rand() % 50);

	print(list);
	cout << endl;

	cout << length(list) << endl;

	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	return 0;
}

