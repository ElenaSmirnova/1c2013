#include "stdafx.h"
#include "stdlib.h"

const int n = 10;			// default size of list

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
	result->head = nullptr;
	return result;
}

void InsertToHead(List *list, int value_of_new_element)
{
	ListElement *newElement = new ListElement;
	newElement->value =	value_of_new_element;
	newElement->next = list->head;
	list->head = newElement;
}

void InsertToEnd(List *list, int value_of_new_element)
{
	if (list->head == 0)
	{
		InsertToHead(list, value_of_new_element);
		return;
	}
	ListElement *temp = list->head;
	while (temp->next != nullptr)
		temp = temp->next;
	ListElement *newElement = new ListElement;
	newElement->value = value_of_new_element;
	newElement->next = temp->next;
	temp->next = newElement;
}

void InsertToPosition(List *list, int value_of_new_element, int position)
{
	if (position == 1)
		InsertToHead(list, value_of_new_element);
	else
	{
		ListElement *temp = list->head;
		for (int i = 2; i < position; i++)
			temp = temp->next;
		ListElement *newElement = new ListElement;
		newElement->value = value_of_new_element;
		newElement->next = temp->next;
		temp->next = newElement;
	}
}

void InsertList(List *list)
{
	printf ("How much elements do you want your list to have?\n(insert integer n >= 0)\n");
	int n;
	scanf_s("%d", &n);
	if (n == 0) return;

	printf ("Print all elements\n");
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf_s ("%d", &a);
		InsertToEnd(list, a);
	}
}

void CutElementOnPosition(List *list, int position)
{
	if (list->head == nullptr) return;
	if (position == 1)
	{
		list->head = list->head->next;
		return;
	}
	ListElement *temp = list->head;
	for (int i = 2; i < position; i++)
	{
		temp = temp->next;
		if (temp->next == nullptr) return;
	}
	temp->next = temp->next->next;
}

int ElementOnPosition(List *list, int position)
{
	ListElement *temp = list->head;
	for (int i = 1; i < position; i++)
		temp = temp->next;
	
	return temp->value;
}

void PrintList(List *list)
{
//	if (list->head = nullptr) return;
	ListElement *temp = list->head;
	for (int i = 0; temp != nullptr; i++)
	{
		printf ("%d ", temp->value);
		temp = temp->next;
	}
	printf ("\n");
}

int HeightOfList(List *list)
{
	ListElement *temp = list->head;
	int i;
	for (i = 0; temp != nullptr; i++)
		temp = temp->next;

	return i;
}

void ReverseList(List *list)
{
	int n;
	n = HeightOfList(list);
	if (n == 0) return;
	ListElement **mass = new ListElement*[n + 1];
	for (int i = 0; i < n; i++)
	{
		static ListElement *temp = list->head;
		mass[i] = temp;
		temp = temp->next;	
	}
	mass[0]->next = nullptr;
	list->head = mass[n - 1];
	for (int i = n - 1; i > 0; i--)
		mass[i]->next = mass[i - 1];
}

int PositionOfMinElement(List *list)
{
	int min = 0, min_value = INT_MAX;
	ListElement *temp = list->head;
	for (int i = 1; temp != nullptr; i++)
	{
		if (temp->value < min_value)
		{
			min = i;
			min_value = temp->value;
		}
		temp = temp->next;
	}
	return min;

}

int main()
{
	List *A = create();	
	InsertList(A);
	printf ("Height_A = %d\n", HeightOfList(A));
	PrintList(A);
	printf ("Input number of element\n");
	int n;
	scanf_s ("%d", &n);
	printf ("A_%d = ", n);
	printf ("%d\n", ElementOnPosition(A, n));
	printf ("What about cut it?\n");
	CutElementOnPosition(A, n);
	PrintList(A);
	printf ("Let`s reverse our list\n");
	ReverseList(A);
	PrintList(A);
	printf ("Mimimum element from our new list has a position: %d%\n", PositionOfMinElement(A));

	return 0;
}