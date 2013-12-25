// Task 2.8 merge sort
//Фролов Алексей
#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include "listPoint.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int length = 0;

	ListPoint *left = create();
	cout << "Введите количество элементов первого списка:" << endl;
	cin >> length;
	int temp = 0;
	cout << "Вводите элементы списка:" << endl;
	PositionPoint position = nullptr;
	for (int i = 0; i < length; i++)
	{
		cin >> temp;
		if (sizeOfList(left) == 0)
		{
			insertToHead(left, temp);
			position = head(left);
		}
		else
		{
			insert(left, temp, position);
			position = next(left, position);
		}
	}
	
	ListPoint *right = create();
	cout << "Введите количество элементов второго списка:" << endl;
	cin >> length;
	temp = 0;
	cout << "Вводите элементы списка:" << endl;
	position = nullptr;
	for (int i = 0; i < length; i++)
	{
		cin >> temp;
		if (sizeOfList(right) == 0)
		{
			insertToHead(right, temp);
			position = head(right);
		}
		else
		{
			insert(right, temp, position);
			position = next(right, position);
		}
	}

	ListPoint *sortList = create();
	PositionPoint sortListPos = head(sortList);

	//отдельно рассмотрим случай, когда в sortList ещё нет элементов
	if (returnValue(left, head(left)) <= returnValue(right, head(right)))
	{
		insertToHead(sortList, returnValue(left, head(left)));
		sortListPos = head(sortList);
		removeHead(left);
	}
	else
	{
		insertToHead(sortList, returnValue(right, head(right)));
		sortListPos = head(sortList);
		removeHead(right);
	}

	while (sizeOfList(left) != 0 && sizeOfList(right) != 0)
	{
		if (returnValue(left, head(left)) <= returnValue(right, head(right)))
		{
			insert(sortList, returnValue(left, head(left)), sortListPos);
			sortListPos = next(sortList, sortListPos);
			removeHead(left);
		}
		else
		{
			insert(sortList, returnValue(right, head(right)), sortListPos);
			sortListPos = next(sortList, sortListPos);
			removeHead(right);
		}
	}

	while (sizeOfList(left) != 0)
	{
		insert(sortList, returnValue(left, head(left)), sortListPos);
		removeHead(left);
		sortListPos = next(sortList, sortListPos);
	}
	while (sizeOfList(right) != 0)
	{
		insert(sortList, returnValue(right, head(right)), sortListPos);
		removeHead(right);
		sortListPos = next(sortList, sortListPos);
	}

	printList(sortList);
	cout << endl;

	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	return 0;
}

