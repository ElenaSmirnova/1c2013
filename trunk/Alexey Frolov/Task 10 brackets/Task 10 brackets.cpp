//Task 10
//Фролов Алексей
#include "stdafx.h"
#include <iostream>
#include "stack.h"
#include <locale.h>

using namespace std;

bool test(char str[], Stack *stack);

int main()
{
	setlocale(LC_ALL, "Russian");

	Stack *stack = create();

	char str[1000];
	cout << "Enter the text:" << endl;
	gets(str);
	
	if (test(str, stack))
		cout << "right!" << endl;
	else
		cout << "error!" << endl;

	deleteStack(stack);

	return 0;
}

bool oppositeClose(char a, char b)
{
	return (a == '(' && b == ')');
}

bool closeBracket(char a)
{
	return a == ')';
}

bool isBrace(char a)
{
	return a == '(' || a == ')';
}

bool test(char str[], Stack *stack)
{
	int temp = 0;
	while (!isBrace(str[temp]))
		temp++;

	push(stack, str[temp]);
	for (int i = temp + 1; i < strlen(str); i++)
	{
		if (!isBrace(str[i]))
			continue;

		if (!testForEmpty(stack) && closeBracket(str[i]))// если требуется что-то от пустого стэка
		{
			cout << "Нарушила правильность скобка: " << i + 1 << endl;
			return false;
		}

		if (testForEmpty(stack) && oppositeClose(top(stack), str[i]))
		{
			top(stack);
			pop(stack);
		}
		else
			push(stack, str[i]);
	}

	if (!testForEmpty(stack))
		return true;
	else
	{
		cout << "Определить какая скобка нарушила правильность не удалось." << endl;
		return false;
	}
}
