// Task 11.cpp
//Фролов Алексей
#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include "stack.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	Stack *stack1 = create();
	Stack *stack2 = create();

	char a[1000];
	do
	{
		cout << "Введите строку: (длина должны быть чётной)" << endl;
		gets(a);
	} while(strlen(a) % 2 == 1);

	// заполняем стэки
	for (int i = 0; i < strlen(a) / 2; i++)
		push(stack1, a[i]);
	for (int i = strlen(a) / 2; i < strlen(a); i++)
		push(stack2, a[i]);

	char *b = new char [strlen(a)];
	int i = 0;
	while (testForEmpty(stack1))
	{
		b[i] = top(stack1);
		pop(stack1);
		i++;
	}
	while (testForEmpty(stack2))
	{
		b[i] = top(stack2);
		pop(stack2);
		i++;
	}

	for (i = 0; i < strlen(a); i++)
		cout << b[i];
	cout << endl;

	delete[] b;
	return 0;
}

