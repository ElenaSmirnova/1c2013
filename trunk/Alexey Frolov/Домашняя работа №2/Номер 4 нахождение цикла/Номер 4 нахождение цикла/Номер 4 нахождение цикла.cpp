// Номер 4 нахождение цикла
//Фролов Алексей
#include "stdafx.h"
#include <iostream>
#include "listPoint.h"
#include <fstream>

using namespace std;

void test(ListPoint *list)
{
	PositionPoint position = head(list);
	while(position != nullptr)
	{
		//cout << returnValue(list, position) << endl;
		//system("pause");
		if (returnTest(list, position) == true)
		{
			cout << "There is a cycle!" << endl;
			return;
		}
		changeTestToTrue(list, position);
		position = next(list, position);
	}
	cout << "There is not a cycle!" << endl;
}

int main()
{
	ListPoint *list = create();

	ifstream in("input.txt");

	char temp;
	PositionPoint point = NULL;
	while (!in.eof())
	{
		in >> temp;
		//решётка означает, что на предыдущий элемент будет указывать последний
		if (temp == '#')
			point = head(list);
		else
			insertToHead(list, temp - '0');
	}

	if (point != NULL)
		loop(list, point);

	test(list);

	in.close();	

	deleteList(list);
	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	return 0;
}

