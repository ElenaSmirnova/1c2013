#pragma once

struct StackElement;
struct Stack;

typedef char ElementType;
typedef StackElement *Position;

//создаём стэк
Stack *create();


//добавить элемент
void push(Stack *stack, ElementType element);

//вернуть значение головы
ElementType top(Stack *stack);

//удалить голову
void pop(Stack *stack);

//проверяет стэк на пустоту
bool testForEmpty(Stack *stack);

//удаляем стэк
void deleteStack(Stack *stack);