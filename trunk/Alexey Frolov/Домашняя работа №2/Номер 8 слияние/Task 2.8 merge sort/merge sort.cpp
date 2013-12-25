#include "stdafx.h"
#include <iostream>
#include "merge sort.h"

using namespace std;

List *mergeSort(List *list)
{
	if (sizeOfList(list) == 1)
		return list;

	Position choice = NULL;
	List *left = create();
	insertToHead(left, returnValue(list, head(list)));
	List *right = create();
	insertToHead(right, returnValue(list, next(list, middle(list))));

	Position leftPos = head(left);
	Position rightPos = head(right);
	
	//разделим наш список на две половины
	Position temp = next(list, head(list));
	while (temp != next(list, middle(list)))
	{

		insert(left, returnValue(list, temp), leftPos);
		leftPos = next(left, leftPos);
		temp = next(list, temp);
	}
	temp = next(list, temp);
	while (temp != last(list))
	{
		insert(right, returnValue(list, temp), rightPos);
		rightPos = next(right, rightPos);
		temp = next(list, temp);
	}
	
	//теперь применим сортировку для "половинок"
	left = mergeSort(left);
	right = mergeSort(right);

	//sortList - спискок, который должен получиться в результате сортировки
	List *sortList = create();
	Position sortListPos = head(sortList);

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
	
	deleteList(left);
	deleteList(right);
	deleteList(list);

	return sortList;
}