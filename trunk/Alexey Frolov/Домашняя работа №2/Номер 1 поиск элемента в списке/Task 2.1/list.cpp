#include "stdafx.h"
#include <iostream>
#include "list.h"

using namespace std;

typedef int ElementType;

struct ListElement
{
	int value;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

List *create()
{
	List *result = new List;
	result -> head = nullptr;
	return result;
}

ListElement *head(List *list)
{
	return list->head;
}

ElementType returnValue(List *list, ListElement *position)
{
	return position->value;
}

void insertToHead(List *list, ElementType value)
{
	ListElement *newElement = new ListElement;
	newElement->value = value;
	newElement->next = list->head;
	list->head = newElement;
}

void insert(List *list, ElementType element)
{
	if (list->head == nullptr || element <= list->head->value)
	{
		ListElement *newElement = new ListElement;
		newElement->value = element;
		newElement->next = list->head;
		list->head = newElement;
		return;
	}

	Position number = list->head;
	while (number != nullptr)
	{
		if (number->next == nullptr)
		{
			ListElement *newElement = new ListElement;
			newElement->value = element;
			newElement->next = number->next;
			number->next = newElement;
			return;
		} 

		if (element <= number->next->value)
		{
			ListElement *newElement = new ListElement;
			newElement->value = element;
			newElement->next = number->next;
			number->next = newElement;
			return;
		}
		number = number->next;
	}
	/*ListElement *newElement = new ListElement;
	newElement->value = value;
	newElement->next = position->next;
	position->next = newElement;*/
}

void remove(List *list, ElementType element)
{
	Position number = list->head;
	while (number->next != nullptr)
	{
		if (number->next->value == element)
		{
			Position temp = number->next;
			number->next = number->next->next;
			delete temp;
			break;
		}
		number = number->next;
	}
	/*Position temp = position->next;
	position->next = position->next->next;
	delete temp;*/
}

void removeHead(List *list)
{
	Position temp = list->head;
	list->head = list->head->next;
	delete temp;
}

void removeList(List *list)
{
	Position number = list->head;
	while (number-> next != nullptr)
	{
		Position temp = number->next;
		number->next = number->next->next;
		delete temp;
		number = number->next;
	}
}

void print(List *list)
{
	Position temp = list->head;
	while (temp != nullptr)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
}

void printNumber(List *list, int pos)
{
	Position temp = list->head;
	int c = 0;
	while (c != pos)
	{
		c++;
		temp = temp->next;
	}
	cout << temp->value << endl;
}
