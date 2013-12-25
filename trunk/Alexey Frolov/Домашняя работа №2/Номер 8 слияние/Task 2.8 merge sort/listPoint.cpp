#include "stdafx.h"
#include <iostream>
#include "listPoint.h"

using namespace std;

typedef int ElementType;

struct ListElement
{
	int value;
	ListElement *next;
};

struct ListPoint
{
	ListElement *head;
};


ListPoint *create()
{
	ListPoint *result = new ListPoint;
	result->head = nullptr;
	return result;
}

ListElement *head(ListPoint *list)
{
	return list->head;
}

ListElement *last(ListPoint *list)
{
	return nullptr;
}

ListElement *next(ListPoint *list, ListElement *position)
{
	return position->next;
}

ElementType returnValue(ListPoint *list, ListElement *position)
{
	return position->value;
}

int sizeOfList(ListPoint *list)
{
	if (head(list) == nullptr)
		return 0;
	
	int size = 0;
	PositionPoint temp = list->head;
	while (temp != nullptr)
	{
		temp = temp->next;
		size++;
	}
	return size;
}

ListElement *middle(ListPoint *list)
{
	int middle =  sizeOfList(list) / 2 - 1;
	ListElement *temp = list->head;
	while(middle > 0)
	{
		middle--;
		temp = temp->next;
	}
	return temp;
}

void insertToHead(ListPoint *list, ElementType element)
{
	ListElement *newElement = new ListElement;
	newElement->value = element;
	newElement->next = list->head;
	list->head = newElement;
}

void insert(ListPoint *list, ElementType value, ListElement *position)
{
	/*printList(list);
	cout << endl;
	cout << "!" << position << endl;
	system("pause");

	if (sizeOfList(list) == 0)
	{
		insertToHead(list, value);
		return;
	}

	printList(list);
	cout << endl;
	cout << position << endl;
	system("pause");*/

	ListElement *element = new ListElement;
	element->value = value;
	element->next = position->next;
	position->next = element;
}

void remove(ListPoint *list, PositionPoint position)
{
	PositionPoint temp = position->next;
	position->next = position->next->next;
	delete temp;
}

void removeHead(ListPoint *list)
{
	PositionPoint temp = list->head;
	list->head = list->head->next;
	delete temp;
}

void deleteList(ListPoint *list)
{
	ListElement *temp = head(list);
	while (temp != nullptr)
	{
		ListElement *tempNext = temp;
		temp = next(list, temp);
		delete tempNext;
	}
	delete list;
}

void printList(ListPoint *list)
{
	PositionPoint temp = list->head;
	while (temp != nullptr)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
}