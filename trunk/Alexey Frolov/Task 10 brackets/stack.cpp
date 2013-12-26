#include "stdafx.h"
#include <iostream>
#include "stack.h"

using namespace std;


struct StackElement
{
	ElementType value;
	StackElement *next;
};

struct Stack
{
	StackElement *head;
};


Stack *create()
{
	Stack *result = new Stack;
	result->head = nullptr;
	return result;
};


void push(Stack *stack, ElementType element)
{
	StackElement *newElement = new StackElement;
	newElement->value = element;
	newElement->next = stack->head;
	stack->head = newElement;
}

bool testForEmpty(Stack *stack)
{
	if (stack->head == nullptr)
		return false;
	else
		return true;
}

ElementType top(Stack *stack)
{
	return stack->head->value;
}

void pop(Stack *stack)
{
	StackElement *temp = stack->head;
	stack->head = stack->head->next;
	delete temp;
}

void deleteStack(Stack *stack)
{
	while (stack->head != nullptr)
		pop(stack);
	delete stack;
}